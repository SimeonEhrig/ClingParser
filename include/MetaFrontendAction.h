#ifndef METAFRONTENDACTION_H
#define METAFRONTENDACTION_H

#include <clang/Frontend/FrontendAction.h>

#include "MetaASTConsumer.h"

class MetaFrontenAction : public clang::ASTFrontendAction {
public:
  virtual std::unique_ptr<clang::ASTConsumer>
  CreateASTConsumer(clang::CompilerInstance &CI,
                    llvm::StringRef file) override {
    return std::unique_ptr<MetaASTConsumer>(new MetaASTConsumer);
  }
};

#endif
