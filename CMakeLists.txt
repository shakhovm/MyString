cmake_minimum_required(VERSION 3.12)
project(TheString)

set(CMAKE_CXX_STANDARD 11)
add_subdirectory(googletest-master/googletest)
include_directories(googletest-master/googletest/include)

set(SOURCE_FILES main.cpp MyString.h)
add_executable(TheString ${SOURCE_FILES})
target_link_libraries(TheString gtest gtest_main)