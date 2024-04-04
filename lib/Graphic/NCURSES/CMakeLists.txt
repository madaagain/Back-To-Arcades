cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 20)

add_library(ncurses SHARED
        src/ANcurses.cpp)

set_target_properties(ncurses PROPERTIES PREFIX "arcade_")

target_link_libraries(ncurses PRIVATE curses)

target_include_directories(ncurses PRIVATE
        ${PROJECT_SOURCE_DIR}/lib/Graphic/NCURSES/include
        ${PROJECT_SOURCE_DIR}/lib/Graphic/include
        ${PROJECT_SOURCE_DIR}/include)

add_custom_command(TARGET ncurses POST_BUILD
        COMMAND cp arcade_ncurses.so ${PROJECT_SOURCE_DIR}/lib)