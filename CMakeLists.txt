cmake_minimum_required (VERSION 3.0)
project (mandelbrot)
file(GLOB SOURCES "src/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})

set(SFML_DIR "third_party/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML 2.5.1 COMPONENTS window graphics REQUIRED)
target_link_libraries(${PROJECT_NAME} sfml-window sfml-graphics)

install (TARGETS ${PROJECT_NAME}
    DESTINATION bin)
