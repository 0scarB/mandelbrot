enable_testing()

set(TEST_TARGET_NAME ${PROJECT_NAME}_test)

find_package(Catch2 REQUIRED)
find_package(SFML ${SFML_VERSION} REQUIRED COMPONENTS window graphics)

add_executable(${TEST_TARGET_NAME} mandelbrot_test.cpp)
target_include_directories(${TEST_TARGET_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(${TEST_TARGET_NAME} PRIVATE -Werror)
target_link_libraries(${TEST_TARGET_NAME} PRIVATE Catch2::Catch2 sfml-window sfml-graphics ${PROJECT_NAME}_gui_lib ${PROJECT_NAME}_lib)

include(CTest)
include(Catch)
catch_discover_tests(${TEST_TARGET_NAME})
