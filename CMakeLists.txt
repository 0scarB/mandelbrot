include(ExternalProject)

cmake_minimum_required(VERSION 3.8)

project(mandelbrot VERSION 0.1
                   LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(EXTERNAL_DEPENDENCIES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/extern)
set(CATCH_VERSION 2.7.2)
set(SFML_VERSION 2.5.1)
set(SFML_DIR ${EXTERNAL_DEPENDENCIES_DIR}/SFML-${SFML_VERSION}/lib/cmake/SFML)
set(CATCH_DIR ${EXTERNAL_DEPENDENCIES_DIR}/Catch2)

option(BUILD_TESTS "Build mandelbrottest target" ON)

add_subdirectory(src/mandelbrot_gui)
add_subdirectory(app)
if(BUILD_TESTS)
    add_subdirectory(test)
endif()
