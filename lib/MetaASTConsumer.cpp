#include "MetaASTConsumer.h"

void MetaASTConsumer::HandleTranslationUnit(clang::ASTContext &Context) {
  // Traversing the translation unit decl via a RecursiveASTVisitor
  // will visit all nodes in the AST.
  visitor->TraverseDecl(Context.getTranslationUnitDecl());
}
