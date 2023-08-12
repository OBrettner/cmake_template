cmake_minimum_required(VERSION 3.27.1)

project(cmake_template)

set (CMAKE_CXX_STANDARD 23)

add_executable(${PROJECT_NAME} main.cpp)

target_link_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/libs/demo_lib/build)

target_link_libraries(${PROJECT_NAME} demo_lib)