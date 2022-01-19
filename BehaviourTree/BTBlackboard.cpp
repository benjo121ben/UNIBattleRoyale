//
// Created by benja on 19/01/2022.
//

#include "BTBlackboard.h"

BTBlackboard::BTBlackboard(const GameMap& m,const std::vector<Player>& pList) : map{m}, playerList{pList}{}

bool BTBlackboard::isSet(std::string key){
    return blackboardMap.count(key) != 0;
}

std::any BTBlackboard::getValue(const std::string& key){
    return blackboardMap.at(key);
}



void BTBlackboard::setValue(const std::string& key, std::any value){
    blackboardMap.insert_or_assign(key, value);
}

BTBlackboard BTBlackboard::getCopy() const{
    return {map,playerList};
}

std::string BTBlackboard::PLAYERMOVEDIR(){
    static std::string PLAYERMOVEDIR = "PLAYERMOVEDIR";
    return PLAYERMOVEDIR;
}