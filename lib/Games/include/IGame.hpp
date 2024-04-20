/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** IGame
*/

#ifndef CBB67FE2_0A1D_4911_9922_CB5D5A691BBC
#define CBB67FE2_0A1D_4911_9922_CB5D5A691BBC


#include "../../Graphic/include/IRender.hpp"

#include <string>
#include <vector>
#include <memory>
#include <cstdint>


class IGame
{
public:
    virtual void init() = 0;
    virtual bool checkLoose() = 0;
    virtual bool checkWin() = 0;
    virtual void getKey() = 0;
    virtual void move() = 0;
    virtual void getScore() = 0;
    virtual void action() = 0;
    virtual void summon() = 0;
    virtual void gameRun() = 0;
    virtual void setWindow() = 0;
protected:
    virtual ~IGame() = default;
public:
    bool _win = false;
    bool _loose = false;
    std::vector<std::pair<int, int>> _map;
    std::vector<std::pair<int, int>> _entity;
    std::vector<std::pair<int, int>> _window;
    enum _currentDirection { UP, DOWN, LEFT, RIGHT };
};



#endif /* CBB67FE2_0A1D_4911_9922_CB5D5A691BBC */
