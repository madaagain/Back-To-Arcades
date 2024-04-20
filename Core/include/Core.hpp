/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-luan.bourbier [WSL: Ubuntu]
** File description:
** Core
*/

#ifndef CORE_HPP_
    #define CORE_HPP_
    #include "DLLoader.hpp"
    #include "../../lib/Graphic/include/IRender.hpp"
    #include "../../lib/Games/include/IGame.hpp"

namespace arcade
{
    class Core {
        public:
            Core(int ac, char **av);
            void libSwitch(int id);
            IrenderLibrary *extract_lib_graph();
            IGame *extract_lib_game();
            void game_loop();
            ~Core() = default;
        private:
            int lastKey;
            IrenderLibrary *_lib_graph;
            IGame *_lib_game;
            const char *_path_lib1 = "lib/Graphic/NCURSES/arcade_ncurses.so";
            const char *_path_lib2 = "lib/Graphic/SFML/arcade_sfml.so";
            const char *_path_lib3 = "lib/Graphic/SDL2/arcade_sdl2.so";
    };
}

#endif /* !CORE_HPP_ */