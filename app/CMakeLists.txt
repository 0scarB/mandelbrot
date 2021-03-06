set(APP_TARGET_NAME ${PROJECT_NAME})

find_package(SFML ${SFML_VERSION} REQUIRED COMPONENTS window graphics)

file(GLOB_RECURSE APP_IMPLEMENTATION_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE APP_HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp)

add_executable(${APP_TARGET_NAME} ${APP_IMPLEMENTATION_FILES} ${APP_HEADER_FILES})
if(BUILD_TESTS)
    add_library(${APP_TARGET_NAME}_lib ${APP_IMPLEMENTATION_FILES} ${APP_HEADER_FILES})
    target_include_directories(${APP_TARGET_NAME}_lib PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_compile_options(${APP_TARGET_NAME}_lib PRIVATE -Werror)
    target_link_libraries(${APP_TARGET_NAME}_lib PRIVATE sfml-window sfml-graphics ${PROJECT_NAME}_gui_lib)
endif()
target_include_directories(${APP_TARGET_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(${APP_TARGET_NAME} PRIVATE -Werror)
target_link_libraries(${APP_TARGET_NAME} PRIVATE sfml-window sfml-graphics ${PROJECT_NAME}_gui_lib)
