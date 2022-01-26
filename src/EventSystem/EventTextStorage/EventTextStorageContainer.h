//
// Created by benja on 25/01/2022.
//

#ifndef GAME_EVENTTEXTSTORAGECONTAINER_H
#define GAME_EVENTTEXTSTORAGECONTAINER_H
#include<string>

std::string makeQuery(std::string mainKeyWord, std::string subKeyWord, bool list = false);
std::string makeQuery(std::string mainKeyWord);

class EventTextStorageContainer {
public:
    static std::string manySurvivorSkirmish();

    static std::string soleSurvivorSkirmish();

    static std::string oneVone();
};



#endif //GAME_EVENTTEXTSTORAGECONTAINER_H
