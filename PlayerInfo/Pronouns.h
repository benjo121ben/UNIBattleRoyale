//
// Created by benja on 15/01/2022.
//

#ifndef GAME_PRONOUNS_H
#define GAME_PRONOUNS_H

#include<string>

class Pronouns{
public:
    std::string subjective;
    std::string objective;
    std::string possessive;

    Pronouns(std::string subjective, std::string objective, std::string possessive);
    static Pronouns masculine();
    static Pronouns feminine();
    static Pronouns neutral();
};

#endif //GAME_PRONOUNS_H
