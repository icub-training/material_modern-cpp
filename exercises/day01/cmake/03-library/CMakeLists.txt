
# https://cmake.org/cmake/help/latest/command/cmake_minimum_required.html?highlight=cmake_minimum_required
#
# set the minimum required version of CMake to be 3.20
cmake_minimum_required(VERSION 3.20)

set(ROOT_PROJECT_NAME ModernC++CMakeExample)

# https://cmake.org/cmake/help/latest/command/project.html
#
# project(<PROJECT-NAME> [<language-name>...])
# project(<PROJECT-NAME>
# [VERSION <major>[.<minor>[.<patch>[.<tweak>]]]]
# [DESCRIPTION <project-description-string>]
# [HOMEPAGE_URL <url-string>]
# [LANGUAGES <language-name>...])
#
# stores in PROJECT_NAME the string ModernCMakeExample (and also in CMAKE_PROJECT_NAME), uses language C++ etc.
project(
  ${ROOT_PROJECT_NAME}
  VERSION 0.1.0.0
  DESCRIPTION "An example project with CMake for Modern C++"
  LANGUAGES CXX)

include(../shared/CMakeOptions.cmake)

# https://cmake.org/cmake/help/latest/command/message.html
# we just print some variables
# message(STATUS "PROJECT_NAME is: " ${PROJECT_NAME})
# message(STATUS "CMAKE_CXX_STANDARD is: " ${CMAKE_CXX_STANDARD})


# the compiled library code is here
add_subdirectory(src)

# the executable code is here
add_subdirectory(app)


                           