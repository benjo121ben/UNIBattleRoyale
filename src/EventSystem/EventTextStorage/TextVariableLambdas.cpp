//
// Created by benja on 24/01/2022.
//
#include "TextVariableLambdas.h"
#include "../../PlayerInfo/Player.h"
#include "../../MapInfo/cardinal_directions.h"
#include <any>
#include <stdexcept>
#include <map>

std::string TextVariableLambdas::getPlayerInfo(const std::any& an, playerInfoType type){
    auto p = std::any_cast<Player>(an);
    switch (type) {
        case name: return p.name;
        case weapon: return p.weapon;
        case pronoun_sub: return p.pronouns.subjective;
        case pronoun_obj: return p.pronouns.objective;
        case pronoun_poss: return p.pronouns.possessive;
    }
    throw std::runtime_error("error in TextVariableLambdas::getPlayerInfo");
}

std::string TextVariableLambdas::translateCardinalDir(const std::any &anyObj) {
    auto dir = std::any_cast<cardinal_directions>(anyObj);
    return dir_to_string(dir);
}

std::string TextVariableLambdas::getPlayerName(const std::any &p) {
    return getPlayerInfo(p,name);
}

std::string TextVariableLambdas::getPlayerWeapon(const std::any &p) {
    return getPlayerInfo(p,weapon);
}

std::string TextVariableLambdas::getPlayerPronoun_subjective(const std::any &p) {
    return getPlayerInfo(p,pronoun_sub);
}

std::string TextVariableLambdas::getPlayerPronoun_objective(const std::any &p) {
    return getPlayerInfo(p,pronoun_obj);
}

std::string TextVariableLambdas::getPlayerPronoun_possessive(const std::any &p) {
    return getPlayerInfo(p,pronoun_poss);
}

std::function<std::string(std::any)> TextVariableLambdas::getLambda(std::string key) {
    static std::map<std::string, std::function<std::string(std::any)>> functionMap{
            {LM_PLAYERNAME(), getPlayerName},
            {LM_PLAYERWEAPON(), getPlayerWeapon},
            {LM_PLAYER_SUBJECTIVE(), getPlayerPronoun_subjective},
            {LM_PLAYER_POSESSIVE(), getPlayerPronoun_possessive},
            {LM_PLAYER_OBJECTIVE(), getPlayerPronoun_objective},
            {LM_CARDINAL_DIR(), translateCardinalDir}
    };
    if(!functionMap.count(key)) throw std::runtime_error("TextVariableLambdas::getLambda( key invalid: " + key  +")");
    else return functionMap.at(key);
}
