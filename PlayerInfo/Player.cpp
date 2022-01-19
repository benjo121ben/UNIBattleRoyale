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


std::string Player::fight(const Player& other){

    int erg = Random::get_random_Int(2);
    if(erg == 0){
        return this->name + " killed " + other.name + " with " + this->pronouns.possessive + " " +  this->weapon;
    }
    else{
        return other.name + " killed " + this->name + " with " + other.pronouns.possessive + " " +  other.weapon;
    }
}

void Player::addBehaviour(const BehaviourTree& bt){
    this->bt = bt.getCopy();
}

TickInfo Player::tick() const{
    return bt->traverse();
}