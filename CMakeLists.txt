cmake_minimum_required(VERSION 3.15)

project(math_lib VERSION 1.1.0)

get_property(IS_MULTI_CONFIG GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)

if(CMAKE_BUILD_TYPE STREQUAL "" AND NOT IS_MULTI_CONFIG)
    message(STATUS "Default build type: Release")
    set(CMAKE_BUILD_TYPE "Release")
endif()

set(PROJECT_ROOT ${PROJECT_SOURCE_DIR})
set(PROJECT_EXPORT ${PROJECT_NAME}Targets)

add_subdirectory(src)
