//
// Created by benja on 19/01/2022.
//

#include<any>
#include "BTBlackboard.h"
#include "../BehaviourTreeExceptions.h"

BTBlackboard::BTBlackboard(const GameMap& m,const std::vector<Player>& pList) : map{m}, playerList{pList}{}

bool BTBlackboard::isSet(std::string key){
    return blackboardMap.count(key) != 0;
}


BTBlackboard BTBlackboard::getCopy() const{
    return {map,playerList};
}

