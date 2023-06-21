cmake_minimum_required(VERSION 3.20)

set(ROOT_PROJECT_NAME smart_pointers)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

project(${ROOT_PROJECT_NAME})

include(../shared/CMakeOptions.cmake)

add_executable(${PROJECT_NAME} main.cpp)
