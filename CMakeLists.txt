cmake_minimum_required(VERSION 3.0)

if(NOT CMAKE_BUILD_TYPE)
    message("** CMAKE_BUILD_TYPE not passed. Assuming Debug")
    set(CMAKE_BUILD_TYPE "Debug")
endif()

if(ENABLE_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif(ENABLE_TESTS)
