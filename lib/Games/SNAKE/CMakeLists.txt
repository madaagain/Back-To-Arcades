cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_STANDARD 20)

add_library(arcade_snake SHARED
    src/ASnake.cpp
)

set_target_properties(arcade_snake PROPERTIES PREFIX "")

target_include_directories(arcade_snake PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/Games/Include
)

add_custom_command(TARGET ncurses POST_BUILD
        COMMAND cp arcade_snake.so ${PROJECT_SOURCE_DIR}/lib)