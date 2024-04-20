#include "lib/Graphic/NCURSES/include/NCURSES.hpp"
#include "lib/Graphic/SDL2/include/SDL2.hpp"
#include "lib/Graphic/SFML/include/SFML.hpp"
#include "lib/Games/include/IGame.hpp"
#include "Core/include/DLLoader.hpp"
#include "Core/include/Core.hpp"
#include <cstdlib>

/**
 * @brief Main de notre programme Arcade lance la boucle principal qui est notre Core.
 * 
 * @param ac Le nombre d'arguments passés au programme.
 * @param av Un tableau de chaînes de caractères contenant les arguments.
 * 
 */

int main(int ac, char **av)
{
    arcade::Core core(ac, av);

    return 0;
}