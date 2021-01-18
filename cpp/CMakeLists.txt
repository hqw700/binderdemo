# for clion
cmake_minimum_required(VERSION  3.5)
project(binderdemo)
set(CMAKE_CXX_STANDARD 14)
set(ANDROID_ROOT W:/home/huangqw/code/aosp)

include_directories(include)
include_directories(${ANDROID_ROOT}/frameworks/native/include)
include_directories(${ANDROID_ROOT}/system/core/include)
include_directories(${ANDROID_ROOT}/frameworks/base/include)

file (GLOB_RECURSE BINDER_SOURCE ${ANDROID_ROOT}/frameworks/native/libs/binder/*.cpp)
file (GLOB_RECURSE SM_SOURCE ${ANDROID_ROOT}/frameworks/native/cmds/servicemanager/*.c)
add_library(servicemanager ${SM_SOURCE})
add_library(libbinder ${BINDER_SOURCE})
add_executable(binderdemo ITest.cpp main.cpp)
