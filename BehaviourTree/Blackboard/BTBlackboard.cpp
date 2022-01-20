//
// Created by benja on 19/01/2022.
//

#include<any>
#include "BTBlackboard.h"
#include "../BehaviourTreeExceptions.h"
#include "../../Managers/GameData.h"

BTBlackboard::BTBlackboard(const GameData& insertData) : publicData{insertData}{}

bool BTBlackboard::isSet(std::string key){
    return blackboardMap.count(key) != 0;
}

Coordinate BTBlackboard::getPlayerCoordinate(int index){
    return publicData.playerPositions.at(index);
}

const Player& BTBlackboard::getPlayerInfo(int index){
    return publicData.playerList.at(index);
}


BTBlackboard BTBlackboard::getCopy() const{
    return BTBlackboard(publicData);
}

