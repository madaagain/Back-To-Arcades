
#include "../include/SDL2.hpp"
#include <memory>
#include <stdlib.h>

/**
 * @brief Constructeur par défaut de la classe SDL2.
 * Initialise les membres de la classe.
 */

SDL2::SDL2()
{
    ;
}

/**
 * @brief Destructeur de la classe SDL2.
 * Assure un nettoyage correct des ressources SDL utilisées.
 */

SDL2::~SDL2()
{
    ;
}

/**
 * @brief Crée et initialise la fenêtre ainsi que le rendu SDL et le système de police (TTF).
 * 
 * Cette fonction initialise SDL, crée une fenêtre graphique et un rendu associé. Elle charge également
 * une police pour le rendu de texte. En cas d'échec d'une des opérations, un message d'erreur est enregistré.
 */

void SDL2::createWindow()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return;
    }
    if (TTF_Init() == -1) {
        SDL_Log("Unable to initialize SDL_ttf: %s", TTF_GetError());
        return;
    }

    _window = SDL_CreateWindow("arcade", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, 0);
    if (!_window) {
        SDL_Log("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return;
    }

    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
    if (!_renderer) {
        SDL_Log("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return;
    }

    _font = TTF_OpenFont("path/to/your/font.ttf", 24);
    if (!_font) {
        SDL_Log("Failed to load font: %s", TTF_GetError());
        return;
    }
}

/**
 * @brief Ferme et détruit la fenêtre, le rendu et la police, et quitte correctement SDL.
 * 
 * Cette fonction libère toutes les ressources associées à SDL et à la bibliothèque SDL_ttf, et ferme SDL proprement.
 */

void SDL2::destroyWindow()
{
    if (_renderer) {
        SDL_DestroyRenderer(_renderer);
        _renderer = nullptr;
    }

    if (_window) {
        SDL_DestroyWindow(_window);
        _window = nullptr;
    }

    if (_font) {
        TTF_CloseFont(_font);
        _font = nullptr;
    }

    TTF_Quit();
    SDL_Quit();
}

/**
 * @brief Affiche du texte à l'écran en utilisant SDL_ttf.
 * 
 * @param str La chaîne de caractères à afficher.
 * 
 * Cette fonction crée une surface de texte à partir de la chaîne de caractères donnée, puis crée une texture à partir
 * de cette surface pour l'afficher à l'écran avec le rendu SDL.
 */

void SDL2::draw_text(char *str)
{
    SDL_Color color = {0, 0, 0};
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(_font, str, color);
    SDL_Texture* message = SDL_CreateTextureFromSurface(_renderer, surfaceMessage);

    int textWidth = surfaceMessage->w;
    int textHeight = surfaceMessage->h;
    SDL_FreeSurface(surfaceMessage);

    SDL_Rect message_rect;
    message_rect.x = 100;
    message_rect.y = 100;
    message_rect.w = textWidth; 
    message_rect.h = textHeight;

    SDL_RenderCopy(_renderer, message, NULL, &message_rect);
    SDL_DestroyTexture(message);
}

/**
 * @brief Boucle d'affichage principale qui dessine l'état courant du jeu ou de l'application.
 * 
 * @param window Vecteur de paires d'entiers représentant les éléments de la fenêtre.
 * @param map Vecteur de paires d'entiers représentant les éléments de la carte du jeu.
 * @param entity Vecteur de paires d'entiers représentant les entités sur la carte.
 * 
 * Cette fonction prépare et affiche la fenêtre, la carte, et les entités du jeu en utilisant le rendu SDL.
 */

void SDL2::display_loop(std::vector<std::pair<int, int>> window, std::vector<std::pair<int, int>> map, std::vector<std::pair<int, int>> entity)
{
    SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255); 
    SDL_RenderClear(_renderer);

    SDL_SetRenderDrawColor(_renderer, 128, 128, 128, 255);
    for (auto& pair : window) {
        SDL_Rect rect = {pair.second * 30, pair.first * 30, 30, 30};
        SDL_RenderFillRect(_renderer, &rect);
    }

    SDL_SetRenderDrawColor(_renderer, 0, 255, 0, 255);
    for (auto& pair : entity) {
        SDL_Rect rect = {pair.second * 30, pair.first * 30, 30, 30};
        SDL_RenderFillRect(_renderer, &rect);
    }

    SDL_SetRenderDrawColor(_renderer, 255, 0, 0, 255);
    for (auto& pair : map) {
        SDL_Rect rect = {pair.second * 30, pair.first * 30, 30, 30};
        SDL_RenderFillRect(_renderer, &rect);
    }

    SDL_RenderPresent(_renderer);
}

/**
 * @brief Point d'entrée pour la création de l'instance SDL2 lors du chargement dynamique.
 * 
 * @returns Un pointeur partagé vers une nouvelle instance de SDL2.
 * 
 * Cette fonction est utilisée pour créer dynamiquement une instance de la classe SDL2, principalement lors du chargement
 * de la bibliothèque partagée dans un environnement où plusieurs systèmes de rendu peuvent être interchangeables.
 */
 
extern "C" std::shared_ptr<SDL2> entry_point(void)
{
    return std::make_shared<SDL2>();
}