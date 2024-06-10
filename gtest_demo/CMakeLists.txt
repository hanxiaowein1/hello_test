cmake_minimum_required(VERSION 3.10.0)

project(gtest_demo)

# find_package(gtest REQUIRED)
find_library(gtest_location NAMES libgtest.a)
add_library(gtest STATIC IMPORTED)
message(STATUS ${gtest_location})
# find_library(gtest_main_location NAMES libgtest_main.a)
# add_library(gtest_main STATIC IMPORTED)
set_target_properties(gtest PROPERTIES IMPORTED_LOCATION ${gtest_location})

add_executable(${PROJECT_NAME} main.cpp)

if(BUILD_TESTING)
    add_definitions(-DGTEST_ENABLED=1)
else()
endif()

# target_link_libraries(gtest gtest_main)
target_link_libraries(${PROJECT_NAME} gtest)
