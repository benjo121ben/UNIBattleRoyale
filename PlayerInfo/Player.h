//
// Created by benja on 15/01/2022.
//
#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include <string>
#include"Pronouns.h"
#include"TickInfo.h"

class BehaviourTree;

class Player{
public:
    std::string name;
    std::string weapon;
    Pronouns pronouns;
    BehaviourTree* bt = nullptr;

    Player(std::string name, std::string weapon, Pronouns pronouns);

    std::string fight(const Player& other);
    void addBehaviour(const BehaviourTree& bt, int id);
    TickInfo tick() const;

};

bool operator==(const Player& p1, const Player& p2);


#endif //GAME_PLAYER_H
