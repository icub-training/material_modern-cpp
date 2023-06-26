
cmake_minimum_required(VERSION 3.20)

set(ROOT_PROJECT_NAME mpimpl)

project(
  ${ROOT_PROJECT_NAME}
  VERSION 0.1.0.0
  
  DESCRIPTION "Modern C++, Use of PIMPL"
  LANGUAGES CXX)

include(../../shared/CMakeOptions.cmake)


include_directories(include)

# define a variable holding all the source files
file(GLOB SOURCES "src/*.cpp")

# add the files to the project
add_executable(${ROOT_PROJECT_NAME} ${SOURCES})

