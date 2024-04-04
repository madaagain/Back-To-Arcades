cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 20)

add_library(arcade_tetris SHARED
    src/ATetris.cpp
)

set_target_properties(arcade_tetris PROPERTIES PREFIX "")

target_include_directories(arcade_tetris PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/Games/Include
)

add_custom_command(TARGET ncurses POST_BUILD
        COMMAND cp arcade_tetris.so ${PROJECT_SOURCE_DIR}/lib)