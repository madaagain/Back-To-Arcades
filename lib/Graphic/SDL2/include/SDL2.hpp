#ifndef SDL_HPP_
#define SDL_HPP_

#include "../../include/IRender.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <memory>

class SDL2 : public IrenderLibrary {
    private:
        SDL_Window* _window = nullptr;
        SDL_Renderer* _renderer = nullptr;
        TTF_Font* _font = nullptr;
    public:
        SDL2();
        virtual ~SDL2();
        void createWindow();
        void destroyWindow();
        void display_loop(std::vector<std::pair<int, int>>, std::vector<std::pair<int, int>>, std::vector<std::pair<int, int>>);
        void draw_text(char *);
};

#endif /* !SDL_HPP_ */