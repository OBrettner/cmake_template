cmake_minimum_required(VERSION 3.27.1)

project(cmake_template)

set (CMAKE_CXX_STANDARD 23)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(libs/demo_lib)

find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init --recursive failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

if(NOT EXISTS "${PROJECT_SOURCE_DIR}/src/glfw/CMakeLists.txt")
    message(FATAL_ERROR "The submodules were not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()

add_subdirectory(src/glfw)
add_subdirectory(src/glm)

find_package(Vulkan REQUIRED)

target_include_directories(${PROJECT_NAME} 
        PUBLIC libs/demo_lib 
        PUBLIC src/glfw/include
    )

target_link_directories(${PROJECT_NAME} 
        PRIVATE libs/demo_lib
        PRIVATE src/glfw/src
    )

target_link_libraries(${PROJECT_NAME} demo_lib glm Vulkan::Vulkan glfw)