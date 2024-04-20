#include "../include/NCURSES.hpp"
#include <memory>
#include <stdlib.h>

/**
 * @brief Constructeur par défaut de la classe NCURSES.
 */

NCURSES::NCURSES()
{
    ;
}

/**
 * @brief Destructeur par défaut de la classe NCURSES.
 */

NCURSES::~NCURSES()
{
    ;
}

/**
 * @brief Initialise et configure la fenêtre du terminal pour le jeu ou l'application.
 * 
 * Cette fonction configure l'environnement NCURSES pour démarrer l'affichage dans le terminal. Elle active
 * le mode cbreak (lecture immédiate des caractères), désactive l'écho (les entrées clavier ne sont pas affichées),
 * permet l'utilisation des touches spéciales via keypad et configure le terminal pour ne pas bloquer sur les entrées clavier.
 */

void NCURSES::createWindow()
{
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
}

/**
 * @brief Ferme et nettoie la fenêtre du terminal.
 * 
 * Cette fonction efface le contenu de l'écran et termine la session NCURSES, rétablissant le comportement normal du terminal.
 */

void NCURSES::destroyWindow()
{
    clear();
    endwin();
}

/**
 * @brief Affiche un texte dans le terminal.
 * 
 * @param text Le texte à afficher.
 */

void NCURSES::draw_text(char *text)
{
    printw(text);
}

/**
 * @brief Boucle d'affichage qui dessine l'état courant du jeu ou de l'application dans le terminal.
 * 
 * @param window Vecteur de paires d'entiers représentant la fenêtre.
 * @param map Vecteur de paires d'entiers représentant la carte du jeu.
 * @param entity Vecteur de paires d'entiers représentant les entités sur la carte.
 * 
 * Cette fonction prépare et affiche la fenêtre, la carte et les entités du jeu dans le terminal en utilisant NCURSES.
 */

void NCURSES::display_loop(std::vector<std::pair<int, int>> window, std::vector<std::pair<int, int>> map, std::vector<std::pair<int, int>> entity)
{
    int x_max = 0;
    int y_max = 0;

    clear();

    for (std::pair<int, int> pair : window) {
        if (pair.first > y_max)
            y_max = pair.first;
        if (pair.second > x_max)
            x_max = pair.second;
    }
    for (std::pair<int, int> pair : map) {
        if (pair.first > y_max)
            y_max = pair.first;
        if (pair.second > x_max)
            x_max = pair.second;
    }
    for (std::pair<int, int> pair : entity) {
        if (pair.first > y_max)
            y_max = pair.first;
        if (pair.second > x_max)
            x_max = pair.second;
    }
    char **tab = (char **)malloc(sizeof(char *) * (y_max + 1));
    for (int i = 0; i < y_max + 1; i++)
        tab[i] = (char *)malloc(sizeof(char) * (x_max + 1));

    for (int i = 0; i < y_max + 1; i++) {
        for (int o = 0; o < x_max + 1; o++) {
            tab[i][o] = ' ';
        }
    }


    for (std::pair<int, int> pair : window)
        tab[pair.first][pair.second] = '+';
    for (std::pair<int, int> pair : map)
        tab[y_max - pair.first - 1][pair.second] = 'O';
    for (std::pair<int, int> pair : entity)
        tab[y_max - pair.first - 1][pair.second] = 'O';
    for (int i = 0; i < y_max + 1; i++) {
        printw(tab[i]);
        printw("\n");
        free(tab[i]);
    }
    refresh();
    free(tab);
}

/**
 * @brief Crée une instance partagée de NCURSES.
 * 
 * @return std::shared_ptr<NCURSES> Un pointeur partagé vers une instance de NCURSES.
 */

extern "C" std::shared_ptr<NCURSES> entry_point(void)
{
    return std::make_shared<NCURSES>();
}