#ifndef A7137921_9D5B_4533_9F70_4F4CAC4F67F7
#define A7137921_9D5B_4533_9F70_4F4CAC4F67F7

#include "../../include/IRender.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <memory>

class SFML : public IrenderLibrary {
    private:
        std::unique_ptr<sf::RenderWindow> _window;
    public:
        SFML();
        ~SFML();

        void createWindow();
        void destroyWindow();
        void display_loop(std::vector<std::pair<int, int>>, std::vector<std::pair<int, int>>, std::vector<std::pair<int, int>>);
        void draw_text(char *);
};

#endif /* A7137921_9D5B_4533_9F70_4F4CAC4F67F7 */
