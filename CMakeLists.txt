cmake_minimum_required(VERSION 2.8)

include_directories(${CMAKE_SOURCE_DIR})

if(ENABLE_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif(ENABLE_TESTS)
