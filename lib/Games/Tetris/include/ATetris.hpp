#ifndef A5B634E5_3D93_44EF_8E4C_294E5BDC1A68
#define A5B634E5_3D93_44EF_8E4C_294E5BDC1A68

#include "../../include/IGame.hpp"
#include <vector>
#include <string>
#include <ncurses.h>


class ATetris : public IGame {
private:

    std::string _line = "          ";

public:
    ATetris();
    virtual ~ATetris();
    virtual void init();
    virtual bool checkLoose();
    virtual bool checkWin();
    virtual void getKey();
    virtual void move();
    virtual void getScore();
    virtual void action();
    virtual void summon();
    virtual void gameRun();
    virtual void setWindow();
};

#endif /* DE60478A_8E85_4E76_B5AE_CEA18A6BE8C7 */
