# set the minimum required version of CMake to be 3.20
cmake_minimum_required(VERSION 3.20)

# create a project named demo02
project(demo02)

# set debug mode
set(CMAKE_BUILD_TYPE Debug)

# impose c++11
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# add include path
include_directories(inc)

# define a variable holding all the source files
file(GLOB SOURCES "src/*.cpp")

# add the files to the project
add_executable(demo02 ${SOURCES})
                           