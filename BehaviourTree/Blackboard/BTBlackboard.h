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
#include "../../MapInfo/Tileable.h"

class GameMap;
class Player;
class GameData;

class BTBlackboard{
    std::map<std::string, std::any> blackboardMap;
public:
    const GameData& publicData;
    TickInfo tickInfo;


    explicit BTBlackboard(const GameData& data);
    bool isSet(std::string key);
    Coordinate getPlayerCoordinate(int index);
    const Player& getPlayerInfo(int index);
    const Player& getCurrentPlayerInfo();

    template <typename T> T getValue(const std::string& key);
    template <typename T> void setValue(const std::string& key, T value);

    BTBlackboard getCopy() const;



};

#include "BTBlackboard.tci"
#include "BlackboardKeys.h"

#endif //GAME_BTBLACKBOARD_H
