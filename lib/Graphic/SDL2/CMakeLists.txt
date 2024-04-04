cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 20)

add_library(sdl2 SHARED
        src/ASdl2.cpp)

set_target_properties(sfml PROPERTIES PREFIX "arcade_")

target_link_libraries(arcade_sdl2 PRIVATE
        ${SDL2_LIBRARIES})

target_include_directories(arcade_sdl2 PRIVATE
        ${SDL2_INCLUDE_DIRS}
        ${PROJECT_SOURCE_DIR}/lib/Graphic/include
        ${PROJECT_SOURCE_DIR}/include)

add_custom_command(TARGET sdl2 POST_BUILD
        COMMAND cp arcade_sdl2.so ${PROJECT_SOURCE_DIR}/lib)
