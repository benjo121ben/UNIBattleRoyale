//
// Created by benja on 25/01/2022.
//

#include "EventTextStorageContainer.h"
#include "TextVariables.h"
#include "TextVariableLambdas.h"
#include "../../Random.h"

using Lambdas = TextVariableLambdas;
using Vars = TextVariables;


std::string makeQuery(std::string mainKeyWord, std::string subKeyWord, bool list){
    if(list){
        return "{["+mainKeyWord+"," + "(" + subKeyWord +")]}";
    }
    return "{"+mainKeyWord+"," + "(" + subKeyWord +")}";
}

std::string makeQuery(std::string mainKeyWord){

    return "{"+mainKeyWord+"}";
}

std::string EventTextStorageContainer::manySurvivorSkirmish() {
    static Random rand;
    static std::vector<std::string> ret{

            "Some Participants run into eachother:\n"
            "Hesitantly, " + makeQuery(Vars::KEY_SURVIVORLIST(), Lambdas::LM_PLAYERNAME(), true) +
            " team up and kill " + makeQuery(Vars::KEY_DEADLIST(), Lambdas::LM_PLAYERNAME(), true) + "\n"
    };
    return ret.at(rand.get_random_Int(ret.size()));
}

std::string EventTextStorageContainer::soleSurvivorSkirmish() {
    static Random rand;
    static std::vector<std::string> ret{

            "As a fight breaks out" +
            makeQuery(Vars::KEY_DEADLIST(), Lambdas::LM_PLAYERNAME(), true) +
            " are killed in the skirmish, leaving " "" +
            makeQuery(Vars::KEY_SURVIVORLIST(), Lambdas::LM_PLAYERNAME(), true) +
            " as the lone survivor\n",

    };
    return ret.at(rand.get_random_Int(ret.size()));
}

std::string EventTextStorageContainer::oneVone() {
    static Random rand;
    static std::vector<std::string> ret{

            makeQuery(Vars::KEY_PLAYER(), Lambdas::LM_PLAYERNAME())
            + " manages to slay " +
            makeQuery(Vars::KEY_TARGETPLAYER(), Lambdas::LM_PLAYERNAME())
            + " with " +
            makeQuery(Vars::KEY_PLAYER(), Lambdas::LM_PLAYER_POSESSIVE()) +
            makeQuery(Vars::KEY_PLAYER(), Lambdas::LM_PLAYERWEAPON())
            + ".\n",
    };
    return ret.at(rand.get_random_Int(ret.size()));
}