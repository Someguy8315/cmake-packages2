cmake_minimum_required(VERSION 3.15)

project(main)

list(APPEND CMAKE_PREFIX_PATH output/lib/cmake/math_lib)

find_package(math_lib 1.2.0 REQUIRED)

message("math_lib_VERSION = ${math_lib_VERSION}")

add_executable(main main.cpp)

target_link_libraries(main PRIVATE math_lib::math_lib)

if(WIN32)
    add_custom_command(TARGET main POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:math_lib::math_lib>
        $<TARGET_FILE_DIR:main>
    )
endif()
