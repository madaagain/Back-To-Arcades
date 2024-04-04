cmake_minimum_required(VERSION 3.17)
project(arcade)

set(CMAKE_CXX_STANDARD 20)

add_compile_options(-Wall -Wextra)

set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES
        ${PROJECT_SOURCE_DIR}/arcade)

add_executable(arcade
        Src/main.cpp
        Src/Core.cpp)

target_link_libraries(arcade PUBLIC dl)

target_include_directories(arcade PUBLIC
        include
        lib/Graphic/Include)

add_subdirectory(lib/Graphic/SFML)
add_subdirectory(lib/Graphic/NCURSES)
add_subdirectory(lib/Graphic/SDL2)
add_subdirectory(Src/DynamicLoaders)
add_subdirectory(lib/Games/TETRIS)
add_subdirectory(lib/Games/SNAKE)

add_dependencies(arcade sfml)

add_custom_command(TARGET arcade POST_BUILD
COMMAND cp arcade ${PROJECT_SOURCE_DIR})

