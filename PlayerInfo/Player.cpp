//
// Created by benja on 16/01/2022.
//
#include "Player.h"
#include<iostream>
#include "../Random.h"


std::string Player::fight(const Player& other){

    int erg = Random::get_random_Int(2);
    if(erg == 0){
        return this->name + " killed " + other.name + " with " + this->pronouns.possessive + " " +  this->weapon;
    }
    else{
        return other.name + " killed " + this->name + " with " + other.pronouns.possessive + " " +  other.weapon;
    }
}

Player::Player(std::string name, std::string weapon, Pronouns pronouns) : name{std::move(name)}, weapon{std::move(weapon)},pronouns{std::move(pronouns)}{}

TickInfo Player::tick() const{


    cardinal_directions dir = static_cast<cardinal_directions>(Random::get_random_Int(4));
    return {TickInfo::move, std::make_any<cardinal_directions>(dir)};
}