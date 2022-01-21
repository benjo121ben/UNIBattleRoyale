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
    return publicData.playerPositions.at(index);
}

Coordinate BTBlackboard::getCurrentPlayerPosition() const {
    return publicData.playerPositions.at(getValue<int>(BlackboardKeys::PLAYERID()));
}

const Player& BTBlackboard::getAnyPlayerInfo(int index) const{
    return publicData.playerList.at(index);
}

const Player& BTBlackboard::getCurrentPlayerInfo() const{
    return publicData.playerList.at(getValue<int>(BlackboardKeys::PLAYERID()));
}


BTBlackboard BTBlackboard::getCopy() const{
    return BTBlackboard(publicData);
}

const std::vector<Coordinate> &BTBlackboard::getPlayerPositionList() {
    return publicData.playerPositions;
}

const std::vector<Player> &BTBlackboard::getPlayerList() {
    return publicData.playerList;
}

const GameMap &BTBlackboard::getMap() const {
    return publicData.map;
}



