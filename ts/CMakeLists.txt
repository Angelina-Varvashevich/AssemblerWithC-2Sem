cmake_minimum_required(VERSION 3.20)
project(ts)

set(CMAKE_CXX_STANDARD 20)

add_executable(ts main.cpp DynamicArray.h DynamicArray.cpp)
