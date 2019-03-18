#include <clang/Basic/FileManager.h>
#include <clang/Basic/VirtualFileSystem.h>
#include <clang/Frontend/FrontendActions.h>
#include <clang/Tooling/Tooling.h>

#include <llvm/ADT/IntrusiveRefCntPtr.h>
#include <llvm/Support/raw_ostream.h>

#include <string>
#include <vector>

#include "MetaFrontendAction.h"

int main(int argc, const char **argv) {
  // the content of the string is written to a virtual file and compiled
  std::string source_code;

  // source code can be passed via arg, other a default string is used
  // it is insecure, but it only a prototype
  if (argc == 1) {
    source_code =
        "int i = 3;\n class foo { float d; };\n int bar(){ return 4;}";
  } else {
    source_code = argv[1];
  }

  // create the virtual overlay filesystem
  llvm::IntrusiveRefCntPtr<clang::vfs::OverlayFileSystem> OverlayFileSystem(
      new clang::vfs::OverlayFileSystem(clang::vfs::getRealFileSystem()));
  llvm::IntrusiveRefCntPtr<clang::vfs::InMemoryFileSystem> InMemoryFileSystem(
      new clang::vfs::InMemoryFileSystem);
  OverlayFileSystem->pushOverlay(InMemoryFileSystem);
  llvm::IntrusiveRefCntPtr<clang::FileManager> Files(
      new clang::FileManager(clang::FileSystemOptions(), OverlayFileSystem));

  std::vector<std::string> Args;
  Args.push_back("ClingSplitter");
  Args.push_back("-Idef");
  Args.push_back("-fsyntax-only");
  Args.push_back("test.cpp");
  clang::tooling::ToolInvocation Invocation(Args, new MetaFrontenAction,
                                            Files.get());

  // inject a virtual file with the content of source_code
  InMemoryFileSystem->addFile("test.cpp", 0,
                              llvm::MemoryBuffer::getMemBuffer(source_code));

  return !Invocation.run();
}
