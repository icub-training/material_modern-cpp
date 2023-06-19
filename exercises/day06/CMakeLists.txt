cmake_minimum_required(VERSION 3.20)

set(ROOT_PROJECT_NAME smart_pointers)

project(${ROOT_PROJECT_NAME})

include(../shared/CMakeOptions.cmake)

add_executable(${PROJECT_NAME} main.cpp)
