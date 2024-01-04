cmake_minimum_required(VERSION 3.15)

project(main)

list(APPEND CMAKE_PREFIX_PATH output/lib/cmake/math_lib)

find_package(math_lib 1.0.0 REQUIRED)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE math_lib::math_lib)
