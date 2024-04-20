/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-luan.bourbier
** File description:
** ASnake
*/

#ifndef ASNAKE_HPP_
#define ASNAKE_HPP_
#include "../../include/IGame.hpp"
#include <vector>
#include <string>
#include <ncurses.h>


class ASnake : public IGame {
    private:
    
    std::string _line = "          ";

    public:
    ASnake();
    virtual ~ASnake();
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
    protected:
};

#endif /* !ASNAKE_HPP_ */
