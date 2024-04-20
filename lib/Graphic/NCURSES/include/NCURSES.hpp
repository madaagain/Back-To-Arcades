#ifndef AF8F6D56_6205_48AF_857E_59845C2083B7
#define AF8F6D56_6205_48AF_857E_59845C2083B7

#include "../../include/IRender.hpp"
#include <ncurses.h> 


class NCURSES : public IrenderLibrary {
    public:
        NCURSES();
        ~NCURSES();

        void createWindow();
        void destroyWindow();
        void display_loop(std::vector<std::pair<int, int>>, std::vector<std::pair<int, int>>, std::vector<std::pair<int, int>>);
        void draw_text(char *);
};

#endif /* AF8F6D56_6205_48AF_857E_59845C2083B7 */
