/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-luan.bourbier
** File description:
** ATetris
*/

#include "../include/ATetris.hpp"
#include <random>
#include <chrono>
#include <ncurses.h> 
#include <string>
#include <algorithm>
#include <utility>

ATetris::ATetris()
{
    ;
}

ATetris::~ATetris()
{
    ;
}

void ATetris::init()
{
    setWindow();
    summon();
}

void ATetris::setWindow()
{
    int x = 11;
    int y = 21;
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

bool ATetris::checkLoose()
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

bool ATetris::checkWin()
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

void ATetris::getKey()
{
    ;
}

void ATetris::move()
{
    ;
}

void ATetris::getScore()
{
    ;
}

void ATetris::action()
{
    ;
}

void ATetris::summon()
{
    for (std::pair<int, int> pair : _entity) {
        _map.push_back(pair);
    }
    std::random_device rand;
    std::mt19937 gen(rand());
    std::uniform_int_distribution<> distrib(0, 5);
    int id = distrib(gen);

    if (id == 0) {
        _entity.clear();
        _entity.push_back({19, 4});
        _entity.push_back({19, 5});
        _entity.push_back({19, 6});
        _entity.push_back({18, 5});
    }
    if (id == 1) {
        _entity.clear();
        _entity.push_back({19, 4});
        _entity.push_back({19, 5});
        _entity.push_back({18, 4});
        _entity.push_back({18, 5});
    }
    if (id == 2) {
        _entity.clear();
        _entity.push_back({19, 4});
        _entity.push_back({19, 5});
        _entity.push_back({18, 5});
        _entity.push_back({18, 6});
    }
    if (id == 3) {
        _entity.clear();
        _entity.push_back({19, 5});
        _entity.push_back({19, 6});
        _entity.push_back({18, 6});
        _entity.push_back({18, 7});
    }
    if (id == 4) {
        _entity.clear();
        _entity.push_back({19, 4});
        _entity.push_back({19, 5});
        _entity.push_back({18, 4});
        _entity.push_back({17, 4});
    }
    if (id == 5) {
        _entity.clear();
        _entity.push_back({19, 4});
        _entity.push_back({19, 5});
        _entity.push_back({18, 5});
        _entity.push_back({17, 5});
    }
}

void ATetris::gameRun()
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

extern "C" std::shared_ptr<ATetris> entry_point(void)
{
    return std::make_shared<ATetris>();
}