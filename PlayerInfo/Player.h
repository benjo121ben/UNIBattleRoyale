//
// Created by benja on 15/01/2022.
//
#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include <string>
#include"Pronouns.h"

class Pronouns;

class Player{
public:
    std::string name;
    std::string weapon;
    Pronouns pronouns;

    Player(std::string name, std::string weapon, Pronouns pronouns);

    std::string fight(const Player& other);
};


#endif //GAME_PLAYER_H
