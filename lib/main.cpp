#include <clang/Frontend/CompilerInstance.h>

#include <iostream>

int main(int argc, char **argv) {
  clang::CompilerInstance CI;
  std::cout << "Hello, world!" << std::endl;
  return 0;
}
