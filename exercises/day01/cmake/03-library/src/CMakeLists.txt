
# Note that headers are optional, and do not affect add_library, but they will not
# show up in IDEs unless they are listed in add_library.
# Optionally glob, but only for CMake 3.12 or later:
# file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${ModernCMakeExample_SOURCE_DIR}/inc/test/*.h")
# set(HEADER_LIST "${ModernCMakeExample_SOURCE_DIR}/inc/test/test.h")

# make an automatic library - will be static or dynamic based on user setting
#add_library(test_library test.cpp ${HEADER_LIST})

add_library(test)

set(SOURCES "./test.cpp")
set(APIDIR "../inc")

target_sources(test PRIVATE ${SOURCES})


# we need this directory, and users of our library will need it too
target_include_directories(test PUBLIC ${APIDIR})

# this may depends on another library
# target_link_libraries(test_library PRIVATE other_library)



                           