cmake_minimum_required(VERSION 3.20)

set(ROOT_PROJECT_NAME lambda_algo_containers)

project(${ROOT_PROJECT_NAME})

include(../shared/CMakeOptions.cmake)

add_executable(${PROJECT_NAME} main.cpp)
