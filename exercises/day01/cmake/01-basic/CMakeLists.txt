# set the minimum required version of CMake to be 3.20
cmake_minimum_required(VERSION 3.20)

# create a project named demo01
project(demo01)

# impose default compilation mode to be Debug
# you can override with:
# > ccmake .. -DCMAKE_BUILD_TYPE=Release
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Debug" CACHE STRING
      "Choose the type of build, options are: Debug Release RelWithDebInfo MinSizeRel."
      FORCE)
endif()

# impose c++ standard to be strict c++98. so far you cannot override it
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# add a single file
add_executable(demo01 src/main.cpp)

