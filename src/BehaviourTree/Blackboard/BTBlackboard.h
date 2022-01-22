//
// Created by benja on 19/01/2022.
//

#ifndef GAME_BTBLACKBOARD_H
#define GAME_BTBLACKBOARD_H
#include<map>
#include<any>
#include<string>
#include<vector>
#include<unordered_set>
#include "../../PlayerInfo/TickInfo.h"
#include "../BehaviourTreeExceptions.h"
#include "../../MapInfo/Tileable.h"

class GameMap;
class Player;
class GameData;

class BTBlackboard{
    std::map<std::string, std::any> blackboardMap;
    const GameData& publicData;
public:
    TickInfo tickInfo;


    explicit BTBlackboard(const GameData& data);
    bool isSet(std::string key) const;
    Coordinate getAnyPlayerCoordinate(int index) const;
    Coordinate getCurrentPlayerPosition() const;
    const Player& getAnyPlayerInfo(int index) const;
    const Player& getCurrentPlayerInfo() const;
    const GameMap& getMap() const;
    const std::vector<Player>& allPlayerList();
    const std::unordered_set<int>& alivePlayerList();
    const std::map<int,Coordinate>& getPlayerPositionList();

    template <typename T> T getValue(const std::string& key) const;
    template <typename T> void setValue(const std::string& key, T value);

    BTBlackboard getCopy() const;



};

#include "BTBlackboard.tci"
#include "BlackboardKeys.h"

#endif //GAME_BTBLACKBOARD_H
