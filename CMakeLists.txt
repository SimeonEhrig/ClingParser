cmake_minimum_required(VERSION 3.0)

project(clingparser)

add_executable(clingparser main.cpp)

install(TARGETS clingparser RUNTIME DESTINATION bin)
