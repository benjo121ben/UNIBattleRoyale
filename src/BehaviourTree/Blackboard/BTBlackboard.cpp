//
// Created by benja on 19/01/2022.
//


#include "BTBlackboard.h"
#include "../BehaviourTreeExceptions.h"
#include "../../Managers/GameData.h"
#include "BlackboardKeys.h"

BTBlackboard::BTBlackboard(const GameData& insertData) : publicData{insertData}{}

bool BTBlackboard::isSet(std::string key) const{
    return blackboardMap.count(key) != 0;
}

Coordinate BTBlackboard::getAnyPlayerCoordinate(int index) const{
    return publicData.newPlayerPositions.at(index);
}

Coordinate BTBlackboard::getCurrentPlayerPosition() const {
    return publicData.newPlayerPositions.at(getValue<int>(BlackboardKeys::PLAYERID()));
}

const Player& BTBlackboard::getAnyPlayerInfo(int index) const{
    return publicData.allPlayersList.at(index);
}

const Player& BTBlackboard::getCurrentPlayerInfo() const{
    return publicData.allPlayersList.at(getValue<int>(BlackboardKeys::PLAYERID()));
}


BTBlackboard BTBlackboard::getCopy() const{
    return BTBlackboard(publicData);
}

const std::map<int, Coordinate> &BTBlackboard::getPlayerPositionList() {
    return publicData.newPlayerPositions;
}

const std::vector<int> &BTBlackboard::alivePlayerList() {
    return publicData.alivePlayerList;
}

const std::vector<Player>& BTBlackboard::allPlayerList() {
    return publicData.allPlayersList;
}

const GameMap &BTBlackboard::getMap() const {
    return publicData.map;
}





