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


int Player::fight(const Player& other){
    return Random::get_random_Int(2) -1;
}

void Player::addBehaviour(const BehaviourTree& bt, int id){
    this->bt = bt.getCopy();
    this->bt->setPlayerInfo(id);
}

TickInfo Player::tick() const{
    return bt->traverse();
}


bool operator==(const Player& p1, const Player& p2){
    return p1.name == p2.name;
}