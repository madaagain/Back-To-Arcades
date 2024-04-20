#include "../include/SFML.hpp"

/**
 * @brief Constructeur par défaut de la classe SFML.
 */

SFML::SFML()
{
    ;
}

/**
 * @brief Destructeur par défaut de la classe SFML.
 */

SFML::~SFML()
{
    ;
}

/**
 * @brief Crée et initialise la fenêtre graphique pour le jeu ou l'application.
 * 
 * Cette fonction configure une fenêtre graphique SFML de 800x800 pixels avec le titre "arcade".
 */

void SFML::createWindow()
{
    _win = std::make_unique<sf::RenderWindow>(sf::VideoMode(800, 800), "arcade");
}

/**
 * @brief Ferme la fenêtre graphique.
 * 
 * Cette fonction ferme proprement la fenêtre graphique SFML.
 */

void SFML::destroyWindow()
{
    _win.get()->close();
}

void text_set(sf::Text& text, char *str)
{
    text.setString(str);
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::Black);
    text.setPosition(100, 100);

}

/**
 * @brief Configure et affiche un texte dans la fenêtre graphique.
 * 
 * @param str La chaîne de caractères à afficher.
 */


void SFML::draw_text(char *str)
{
    sf::Text text;
    text_set(text, str);
    _win.get()->draw(text);
}

/**
 * @brief Boucle d'affichage qui dessine l'état courant du jeu ou de l'application dans la fenêtre graphique.
 * 
 * @param window Vecteur de paires d'entiers représentant la fenêtre.
 * @param map Vecteur de paires d'entiers représentant la carte du jeu.
 * @param entity Vecteur de paires d'entiers représentant les entités sur la carte.
 * 
 * Cette fonction prépare et affiche la fenêtre, la carte, et les entités du jeu dans une fenêtre graphique SFML.
 */

void SFML::display_loop(std::vector<std::pair<int, int>> window, std::vector<std::pair<int, int>> map, std::vector<std::pair<int, int>> entity)
{
    int x_max = 0;
    int y_max = 0;

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

    _win.get()->clear();
    sf::RectangleShape square_map(sf::Vector2f(30, 30));
    square_map.setFillColor(sf::Color(128, 128, 128));

    sf::RectangleShape square_game(sf::Vector2f(30, 30));
    square_game.setFillColor(sf::Color(0, 255, 0));

    for (std::pair<int, int> pair : window) {
        square_map.setPosition(800 - (200 + (pair.second * 30)), 800 - (50 + (pair.first * 30)) - 30);
        _win.get()->draw(square_map);
    }
    for (std::pair<int, int> pair : entity) {
        square_game.setPosition(800 - (200 + (pair.second * 30)), 800 - (50 + (pair.first * 30)) - 60);
        _win.get()->draw(square_game);
    }
    for (std::pair<int, int> pair : map) {
        square_game.setPosition(800 - (200 + (pair.second * 30)), 800 - (50 + (pair.first * 30)) - 60);
        _win.get()->draw(square_game);
    }
    _win.get()->display();
}

extern "C" std::shared_ptr<SFML> entry_point(void)
{
    return std::make_shared<SFML>();
}