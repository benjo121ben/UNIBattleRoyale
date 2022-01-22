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
    int id;
public:
    enum SkillCheckType{
        testType
    };

    std::string name;
    std::string weapon;
    Pronouns pronouns;
    BehaviourTree* bt = nullptr;

    Player(std::string name, std::string weapon, Pronouns pronouns);
    int getID() const;
    int fight(const Player& other);
    void addBehaviour(const BehaviourTree& bt, int id);
    TickInfo tick() const;

    int skillCheck(SkillCheckType);
};

bool operator==(const Player& p1, const Player& p2);


#endif //GAME_PLAYER_H
