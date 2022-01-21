//
// Created by benja on 19/01/2022.
//

#include<any>
#include "BTBlackboard.h"
#include "../BehaviourTreeExceptions.h"
#include "../../Managers/GameData.h"
#include "BlackboardKeys.h"

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

const Player& BTBlackboard::getCurrentPlayerInfo(){
    if(!isSet(BlackboardKeys::PLAYERID())) throw unavailable_blackboard_key_BT_exception("BTBlackboard::getCurrentPlayerInfo",BlackboardKeys::PLAYERID());
    int nr = getValue<int>(BlackboardKeys::PLAYERID());
    return publicData.playerList.at(nr);
}


BTBlackboard BTBlackboard::getCopy() const{
    return BTBlackboard(publicData);
}

