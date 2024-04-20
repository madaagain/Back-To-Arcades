/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-luan.bourbier
** File description:
** ASnake
*/

#include "../include/ASnake.hpp"
#include <random>
#include <chrono>
#include <ncurses.h> 
#include <string>
#include <algorithm>
#include <utility>

ASnake::ASnake()
{
    ;
}

ASnake::~ASnake()
{
    ;
}

void ASnake::init()
{
    setWindow();
    summon();
}

void ASnake::setWindow()
{
    int x = 20;
    int y = 20;
    int i = 0;
    int o = 0;

    for (; i != x; i++)
        _window.push_back({o, i});
    for (; o != y; o++)
        _window.push_back({o, i});
    for (; i != 0; i--)
        _window.push_back({o, i});
    for (;o != 0; o--)
        _window.push_back({o, i});
}

bool ASnake::checkLoose()
{
    for (std::pair<int, int> pair1 : _map) {
        for (std::pair<int, int> pair2 : _entity) {
            if (pair1 == pair2) {
                _loose = true;
                return true;
            }
        }
    }
    return false;
}

bool ASnake::checkWin()
{
    int nb = 1;
    std::vector<std::pair<int, int>> tmp;

    for (std::pair<int, int> pair1 : _map) {
        for (std::pair<int, int> pair2 : _map) {
            if (pair1.second == pair2.second)
                nb++;
        }
        if (nb == 10)
            for (int i = 0; _map.size(); i++) {
                if (_map[i].second != nb)
                    if (_map[i].second > pair1.second)
                        tmp.push_back({_map[i].first, _map[i].second - 1});
                    else
                        tmp.push_back({_map[i].first, _map[i].second});
            }
    }
    _map = tmp;
    return false;
}

void ASnake::getKey()
{
    ;
}

void ASnake::move()
{
    ;
}

void ASnake::getScore()
{
    ;
}

void ASnake::action()
{
    ;
}

void ASnake::summon()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> disX(1, 18);
    std::uniform_int_distribution<> disY(1, 18);

    _entity.clear();
    _map.clear();

    int serpentX, serpentY;
    serpentX = disX(gen);
    serpentY = disY(gen);
    _entity.push_back(std::make_pair(serpentY, serpentX));

    int appleX, appleY;
    do {
        appleX = disX(gen);
        appleY = disY(gen);
    } while (appleX == serpentX && appleY == serpentY);
    _map.push_back(std::make_pair(appleY, appleX));

}

void ASnake::gameRun()
{
    std::vector<std::pair<int, int>> tmp;

    for (std::pair<int, int> pair : _entity) {
        if (pair.first == 0) {
            summon();
            return;
        }
        tmp.push_back({pair.first - 1, pair.second});
    }
    for (std::pair<int, int> pair1 : _map) {
        for (std::pair<int, int> pair2 : tmp) {
            if (pair1 == pair2) {
                summon();
                return;
            }
        }
    }
    _entity = tmp;
}

extern "C" std::shared_ptr<ASnake> entry_point(void)
{
    return std::make_shared<ASnake>();
}