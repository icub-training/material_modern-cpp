

# unless you run:
# > ccmake .. -DCMAKE_BUILD_TYPE=Debug/Release/...
# the default compilation mode will be Debug
if(NOT CMAKE_BUILD_TYPE)
set(CMAKE_BUILD_TYPE "Debug" CACHE STRING
    "Choose the type of build, options are: Debug Release RelWithDebInfo MinSizeRel."
    FORCE)
endif()

# unless you run:
# > ccmake .. -DCMAKE_CXX_STANDARD=11
# with values taken from https://cmake.org/cmake/help/latest/prop_gbl/CMAKE_CXX_KNOWN_FEATURES.html#prop_gbl:CMAKE_CXX_KNOWN_FEATURES
# we just use 11
if(NOT CMAKE_CXX_STANDARD)
set(CMAKE_CXX_STANDARD "11" CACHE STRING
    "Choose the c++, options are: 98 11 14 17 20."
    FORCE)
endif()


# https://cmake.org/cmake/help/latest/manual/cmake-compile-features.7.html#requiring-language-standards
# at least ... but maybe more
# target_compile_features(test_library PRIVATE ${CXXSTD})
# so i will use: 
#set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
                           