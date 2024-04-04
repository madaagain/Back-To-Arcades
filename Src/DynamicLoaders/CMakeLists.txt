cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 20)

add_library(DynamicLoaders SHARED
    DynamicLoaders/DLLoader.cpp
    DynamicLoaders/Exception.cpp
)

target_include_directories(DynamicLoaders PUBLIC
    ${PROJECT_SOURCE_DIR}/Include/DynamicLoaders
)
