cmake_minimum_required(VERSION 2.8)

find_package(GTest REQUIRED)

if(GTEST_FOUND)
    include_directories(${GTEST_INCLUDE_DIRS})

    add_executable(point point.cpp)
    target_link_libraries(point ${GTEST_BOTH_LIBRARIES})
    add_test(gest_point point)
endif()
