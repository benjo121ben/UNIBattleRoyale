//
// Created by benja on 19/01/2022.
//

#ifndef GAME_BTBLACKBOARD_H
#define GAME_BTBLACKBOARD_H
#include<map>
#include<any>
#include<string>
#include<vector>
#include "../../PlayerInfo/TickInfo.h"
#include "../BehaviourTreeExceptions.h"

class GameMap;
class Player;

class BTBlackboard{
    std::map<std::string, std::any> blackboardMap;
public:
    const GameMap& map;
    const std::vector<Player>& playerList;
    TickInfo tickInfo;


    BTBlackboard(const GameMap& m,const std::vector<Player>& pList);
    bool isSet(std::string key);

    template <typename T> T getValue(const std::string& key);
    template <typename T> void setValue(const std::string& key, T value);

    BTBlackboard getCopy() const;



};

#include "BTBlackboard.tci"

#endif //GAME_BTBLACKBOARD_H
