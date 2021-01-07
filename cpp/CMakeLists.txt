cmake_minimum_required(VERSION  3.5)
project(binderdemo)
set(CMAKE_CXX_STANDARD 14)

include_directories(include)
add_executable(binderdemo ITest.cpp main.cpp)