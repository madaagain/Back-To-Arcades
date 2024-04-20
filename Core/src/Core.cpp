#include "../include/Core.hpp"
#include "../../lib/Games/include/IGame.hpp"
#include <thread>


/**
 * @brief Exécute la boucle principale du jeu.
 * 
 * Cette fonction gère la boucle de jeu principale, mettant à jour et affichant le jeu tant que la condition de défaite n'est pas rencontrée.
 * Après chaque itération, elle fait une pause d'une seconde pour synchroniser le déroulement du jeu, puis exécute une mise à jour du jeu.
 */

void arcade::Core::game_loop()
{
    while(_lib_game->checkLoose() == false) {
        _lib_graph->display_loop(_lib_game->_window, _lib_game->_map, _lib_game->_entity);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        _lib_game->gameRun();
    }
    _lib_graph->destroyWindow();
}

/**
 * @brief Constructeur de la classe Core qui initialise les bibliothèques de jeu et graphique et lance la boucle de jeu.
 * 
 * @param ac Le nombre d'arguments passés au programme.
 * @param av Un tableau de chaînes de caractères contenant les arguments.
 * 
 * Ce constructeur charge les bibliothèques graphique et de jeu à partir des chemins fournis en arguments du programme,
 * initialise le jeu, crée la fenêtre graphique, et lance la boucle de jeu.
 */

arcade::Core::Core(int ac, char **av)
{
    DLLoader<IrenderLibrary> loader_graph(av[1]);
    DLLoader<IGame> loader_game(av[2]);

    _lib_graph = loader_graph.getLib().get();
    _lib_game = loader_game.getLib().get();

    _lib_game->init();
    _lib_graph->createWindow();
    game_loop();
}

/**
 * @brief Change la bibliothèque graphique à la volée.
 * 
 * @param id L'identifiant de la nouvelle bibliothèque graphique à charger.
 * 
 * Cette méthode permet de changer la bibliothèque graphique utilisée par le jeu en fonction de l'identifiant passé en paramètre.
 * Elle charge la nouvelle bibliothèque graphique en utilisant le chemin correspondant stocké dans l'instance de la classe.
 */

void arcade::Core::libSwitch(int id)
{
    if (id == 1) {
        DLLoader<IrenderLibrary> loader(_path_lib1);
        _lib_graph = loader.getLib().get();
    }
    if (id == 2) {
        DLLoader<IrenderLibrary> loader(_path_lib2);
        _lib_graph = loader.getLib().get();
    }
    if (id == 3) {
        DLLoader<IrenderLibrary> loader(_path_lib3);
        _lib_graph = loader.getLib().get();
    }
}

/**
 * @brief Récupère la bibliothèque graphique actuellement utilisée.
 * 
 * @return Un pointeur vers l'interface de la bibliothèque graphique actuellement utilisée.
 * 
 * Cette méthode permet d'extraire et d'accéder à l'interface de la bibliothèque graphique actuellement chargée et utilisée par le jeu.
 */

IrenderLibrary *arcade::Core::extract_lib_graph()
{
    return _lib_graph;
}

/**
 * @brief Récupère la bibliothèque de jeu actuellement utilisée.
 * 
 * @return Un pointeur vers l'interface de la bibliothèque de jeu actuellement utilisée.
 * 
 * Cette méthode permet d'extraire et d'accéder à l'interface de la bibliothèque de jeu actuellement chargée et utilisée par le jeu.
 */

IGame *arcade::Core::extract_lib_game()
{
    return _lib_game;
}