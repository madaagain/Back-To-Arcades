#ifndef AAA
#define AAA

#include <iostream>
#include <memory>
#include <vector> 
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class IrenderLibrary {
public:
    IrenderLibrary() {};
    virtual ~IrenderLibrary() = default;
    virtual void createWindow() = 0;
    virtual void destroyWindow() = 0;
    virtual void display_loop(std::vector<std::pair<int, int>>, std::vector<std::pair<int, int>>, std::vector<std::pair<int, int>>) = 0;
    virtual void draw_text(char *) = 0;
protected:
    std::unique_ptr<sf::RenderWindow> _win;
};

#endif /* AAA */
