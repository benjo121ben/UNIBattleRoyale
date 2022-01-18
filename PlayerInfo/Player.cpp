//
// Created by benja on 16/01/2022.
//
#include "Player.h"
#include<cstdlib>
#include <utility>
#include<iostream>


std::string Player::fight(const Player& other){
    srand(time(NULL));
    int erg = rand() % 2;
    if(erg == 0){
        return this->name + " killed " + other.name + " with " + this->pronouns.possessive + " " +  this->weapon;
    }
    else{
        return other.name + " killed " + this->name + " with " + other.pronouns.possessive + " " +  other.weapon;
    }
}

Player::Player(std::string name, std::string weapon, Pronouns pronouns) : name{std::move(name)}, weapon{std::move(weapon)},pronouns{std::move(pronouns)}{}

TickInfo Player::tick() const{
    return {TickInfo::move, std::make_any<cardinal_directions>(north)};
}