cmake_minimum_required(VERSION 3.27.1)

project(demo_lib)

set (CMAKE_CXX_STANDARD 23)

add_library(${PROJECT_NAME} ./cpp/adder.cpp)