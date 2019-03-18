cmake_minimum_required(VERSION 3.4.3)

# add llvm dependencies based on this tutorial:
# http://llvm.org/docs/CMake.html#embedding-llvm-in-your-project

find_package(LLVM 5.0 REQUIRED CONFIG)
Find_Package(Clang REQUIRED CONFIG HINTS "${LLVM_INSTALL_PREFIX}/lib/cmake/clang")

project(clingparser)

set (CMAKE_CXX_STANDARD 14)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

message(INCLUDES: ${LLVM_INCLUDE_DIRS})

llvm_map_components_to_libnames(llvm_libs bitreader option profiledata mc
                                mcparser binaryformat support core)

set(clang_libs clangAST clangBasic clangFrontend clangTooling)

include_directories(include/)

add_executable(clingparser lib/main.cpp lib/MetaVisitor.cpp lib/MetaASTConsumer.cpp)
target_link_libraries(clingparser ${llvm_libs} ${clang_libs})

install(TARGETS clingparser RUNTIME DESTINATION bin)
