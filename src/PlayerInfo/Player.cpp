//
// Created by benja on 16/01/2022.
//
#include "Player.h"
#include<iostream>
#include <utility>
#include "../Random.h"
#include "../MapInfo/cardinal_directions.h"
#include "../BehaviourTree/BehaviourTree.h"




Player::Player(std::string name, std::string weapon, Pronouns pronouns) :
    name{std::move(name)}, weapon{std::move(weapon)}, pronouns{std::move(pronouns)} {}

Player::Player(const Player& other) :
    name{other.name},
    weapon{other.weapon},
    pronouns{other.pronouns}
    {
        if (other.bt != nullptr) {
            bt = other.bt->getCopy();
        }
    }


Player::~Player(){
    if(bt != nullptr){
        delete bt;
    }
}


int Player::fight(const Player& other){
    return Random::get_random_Int(2) -1;
}

void Player::addBehaviour(BehaviourTree* bt, int id){
    this->bt = bt;
    this->bt->setPlayerInfo(id);
    this->id = id;
}

TickInfo Player::tick() const{
    return bt->traverse();
}

int Player::skillCheck(SkillCheckType type){
    return 0;
}

int Player::getID() const{
    return id;
}




bool operator==(const Player& p1, const Player& p2){
    return p1.getID() == p2.getID();
}