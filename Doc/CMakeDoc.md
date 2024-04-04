# Guide to Adding Files in CMake for the Arcade Project

## Description

This guide provides step-by-step instructions on how to properly add new class files to the Arcade project, specifically focusing on adding to the SNAKE game module. The process for other game modules like TETRIS follows a similar pattern.

## Project Structure

When adding a new class called NewClass, your project structure under the SNAKE module should resemble:

SNAKE/
├── CMakeLists.txt
├── include
│   ├── ASnake.hpp
│   └── NewClass.hpp    # Header file for the NewClass
└── src
    ├── ASnake.cpp
    └── NewClass.cpp    # Source file for the NewClass

## Adding a New File to CMake

To ensure your new .cpp files are correctly compiled and included in the arcade_snake shared library, follow these instructions:

## 1. Modify the CMakeLists.txt File

Open the CMakeLists.txt file located in the SNAKE directory. For each new .cpp file added to the project, you need to add it to the list of files in the add_library command. This instructs CMake to compile these files and include them in the generated shared library.

Here's how to update your CMakeLists.txt after adding NewClass.cpp and potentially other classes like HelperClass.cpp:


add_library(arcade_snake SHARED
    src/ASnake.cpp
    src/NewClass.cpp
    # Add each new .cpp file here to ensure it's compiled into the shared library.
    src/HelperClass.cpp    # Example of adding a new class HelperClass
)

## 2. Specify Include Directories
If your new .cpp files depend on header files located in the include directory or elsewhere, ensure that the path to these directories is specified with target_include_directories in the CMakeLists.txt. This allows the compiler to find all necessary header files during compilation.


target_include_directories(arcade_snake PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    # Add other include paths as necessary
)

## Recompile the Project
After updating the CMakeLists.txt, recompile your project to ensure the changes are taken into account. This can be done by using CMake to regenerate the build files and then using your build system (e.g., make) to compile the project.

By following these steps whenever you add new source files to your project, you ensure that your CMake configuration stays up-to-date and that your project compiles correctly with all new features included.

