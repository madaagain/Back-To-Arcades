# Back To The Past Arcade

![Logo de mon projet](https://64.media.tumblr.com/1040639574a1dd9af3ea125f49acb51b/cec82584e8af4765-f8/s1280x1920/df9c28323e5dc7fc6c56b366d10a9d31412d8912.gif)

Welcome to the Arcade Project, an Epitech graphical platform designed to emulate classic arcade games with a modern twist. This project leverages modular architecture to allow for the easy integration of various games and graphical rendering libraries such as SFML, SDL2, and NCurses.

# Contributors:
- Ylianne Gentelet
- Luan Bourbier
- Adam Zerrouk

## Features

- Modular Design: Easily switch between different graphical libraries and games at runtime.

- Extensible: Add new games and graphical libraries without extensive modifications to the existing codebase.

- Dynamic Loading: Utilize shared libraries for games and rendering engines to enhance flexibility.

## Prerequisites

C++17 compatible compiler
Makefile or CMake version 3.14 or higher
Relevant libraries for your platform (SDL2, SFML, NCurses)

# Table of contents

- [Installation](#installation)
- [Utilisation](#utilisation)
- [Documentation](https://madsdocs.gitbook.io/aracde-documentation/technical-documentation/doc-on-modules-and-and-classes)

# Installation

To install the repository: `git@github.com:EpitechPromo2027/B-OOP-400-PAR-4-1-arcade-luan.bourbier.git`

## Quick Usage

Before trying anything run the command: `make` to properly compile the code and be able to test the program

For a usage exemple, use the following command:

- 1/ `make` to compile your code
- 2/ Usage `../arcade <path_to_rendering_lib> <path_to_game_lib>`
