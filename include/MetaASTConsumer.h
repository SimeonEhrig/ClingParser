#ifndef METAASTCONSUMER_H
#define METAASTCONSUMER_H

#include <clang/AST/ASTConsumer.h>
#include <clang/Frontend/CompilerInstance.h>

#include "MetaVisitor.h"

class MetaASTConsumer : public clang::ASTConsumer {
private:
  std::unique_ptr<MetaVisitor> visitor;

public:
  explicit MetaASTConsumer() : visitor(new MetaVisitor) {}

  virtual void HandleTranslationUnit(clang::ASTContext &Context) override;
};

#endif
