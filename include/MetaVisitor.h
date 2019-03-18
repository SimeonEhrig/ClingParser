#ifndef METAVISITOR_H
#define METAVISITOR_H

#include <clang/AST/RecursiveASTVisitor.h>

class MetaVisitor : public clang::RecursiveASTVisitor<MetaVisitor> {
  // private:
  //
public:
  // is called when a function declaration is found
  virtual bool VisitFunctionDecl(clang::FunctionDecl *func);
  // is called when a class, struct or union declaration is found
  virtual bool VisitCXXRecordDecl(clang::CXXRecordDecl *Declaration);
};

#endif
