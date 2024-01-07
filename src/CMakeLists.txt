add_library(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PRIVATE math_lib.cpp
    PUBLIC FILE_SET HEADERS
    BASE_DIRS ${PROJECT_ROOT}/include
    FILES ${PROJECT_ROOT}/include/math_lib/math_lib.h
)

target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_ROOT}/include)

if(BUILD_SHARED_LIBS)
    message(STATUS "BUILD_SHARED_LIBS=ON")
    include(GenerateExportHeader)
    generate_export_header(${PROJECT_NAME})

    target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
    target_compile_definitions(${PROJECT_NAME} PUBLIC "MATH_LIB_SHARED")

    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/math_lib_export.h
        DESTINATION include/${PROJECT_NAME}
    )
endif()

install(TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_EXPORT}
    FILE_SET HEADERS
)

install(EXPORT ${PROJECT_EXPORT}
    FILE ${PROJECT_NAME}Targets.cmake
    DESTINATION lib/cmake/${PROJECT_NAME}
    NAMESPACE ${PROJECT_NAME}::
)

include(CMakePackageConfigHelpers)

configure_package_config_file(${PROJECT_ROOT}/cmake/config.cmake.in
    ${PROJECT_NAME}Config.cmake
    INSTALL_DESTINATION lib/cmake/${PROJECT_NAME}
)

write_basic_package_version_file(${PROJECT_NAME}ConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
    DESTINATION lib/cmake/${PROJECT_NAME}
)
