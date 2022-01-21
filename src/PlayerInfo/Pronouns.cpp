//
// Created by benja on 16/01/2022.
//
#include "Pronouns.h"

#include <utility>

Pronouns::Pronouns(std::string subjective, std::string objective, std::string possessive) : subjective{std::move(subjective)}, objective{std::move(objective)}, possessive{std::move(possessive)}{}

Pronouns Pronouns::masculine(){
    return {"he", "him", "his"};
}
Pronouns Pronouns::feminine(){
    return {"she", "her", "her"};
}
Pronouns Pronouns::neutral(){
    return {"they", "them", "their"};
}