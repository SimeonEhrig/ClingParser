#include <llvm/Support/raw_ostream.h>

#include "MetaVisitor.h"

bool MetaVisitor::VisitFunctionDecl(clang::FunctionDecl *func) {
  llvm::outs() << "found function: " << func->getNameAsString() << "\n";
  return true;
}

bool MetaVisitor::VisitCXXRecordDecl(clang::CXXRecordDecl *Declaration) {
  // For debugging, dumping the AST nodes will show which nodes are already
  // being visited.
  Declaration->dump();

  // The return value indicates whether we want the visitation to proceed.
  // Return false to stop the traversal of the AST.
  return true;
}
