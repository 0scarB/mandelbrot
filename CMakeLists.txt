cmake_minimum_required (VERSION 3.0)
project (mandelbrot)
file(GLOB SOURCES "src/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})
install (TARGETS ${PROJECT_NAME}
    DESTINATION bin)
