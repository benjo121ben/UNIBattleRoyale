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
    static std::vector<std::string> ret{

            "Some Participants run into eachother:\n"
                "Hesitantly, " + makeQuery(Vars::KEY_SURVIVORLIST(), Lambdas::LM_PLAYERNAME(), true) +
                " team up and kill " + makeQuery(Vars::KEY_DEADLIST(), Lambdas::LM_PLAYERNAME(), true) +
                " before they run from eachother in fear.\n",

            makeQuery(Vars::KEY_SURVIVORLIST(), Lambdas::LM_PLAYERNAME(), true) +
                " encounter eachother in the forest. They decide on a temporary truce since they both have information on the location of " +
                makeQuery(Vars::KEY_DEADLIST(), Lambdas::LM_PLAYERNAME(), true) + ".\n" +
                "They strike at night, while " +
                makeQuery(Vars::KEY_DEADLIST(), Lambdas::LM_PLAYERNAME(), true) +
                " are sleeping and though it may not be a noble victory, " +
                makeQuery(Vars::KEY_SURVIVORLIST(), Lambdas::LM_PLAYERNAME(), true) +
                " walk away alive.\n"
    };
    return ret.at(Random::get_random_Int(ret.size()));
}

std::string EventTextStorageContainer::soleSurvivorSkirmish() {
    static std::vector<std::string> ret{

            "As a fight breaks out" +
                makeQuery(Vars::KEY_DEADLIST(), Lambdas::LM_PLAYERNAME(), true) +
                " are killed in the skirmish, leaving " +
                makeQuery(Vars::KEY_SURVIVORLIST(), Lambdas::LM_PLAYERNAME(), true) +
                " as the lone survivor.\n",


            makeQuery(Vars::KEY_DEADLIST(), Lambdas::LM_PLAYERNAME(), true) +
                " start to fight amongst themselves, but " +
                makeQuery(Vars::KEY_SURVIVORLIST(), Lambdas::LM_PLAYERNAME(), true) +
                " uses their moment of distraction to kill them.\n",


            "As " +
                makeQuery(Vars::KEY_SURVIVORLIST(), Lambdas::LM_PLAYERNAME(), true) +
                " takes a short break next to a river." +
                makeQuery(Vars::KEY_SURVIVORLIST(), Lambdas::LM_PLAYER_SUBJECTIVE(), true) +
                " is ambushed by " +
                makeQuery(Vars::KEY_DEADLIST(), Lambdas::LM_PLAYERNAME(), true) + ".\n" +
                "They take away his " +
                makeQuery(Vars::KEY_DEADLIST(), Lambdas::LM_PLAYERWEAPON(), true) +
                " hoping that would be enough, but " +
                makeQuery(Vars::KEY_SURVIVORLIST(), Lambdas::LM_PLAYER_SUBJECTIVE(), true) +
                " overwhelms them. Killing one with his bare hands and throwing the other into the raging river.\n",


            makeQuery(Vars::KEY_SURVIVORLIST(), Lambdas::LM_PLAYERNAME(), true) +
                " poisons " +
                makeQuery(Vars::KEY_DEADLIST(), Lambdas::LM_PLAYERNAME(), true) +
                " with a box of beer " +
                makeQuery(Vars::KEY_SURVIVORLIST(), Lambdas::LM_PLAYER_SUBJECTIVE(), true) +
                " found in one of the islands hidden stashes.\n",


            makeQuery(Vars::KEY_SURVIVORLIST(), Lambdas::LM_PLAYERNAME(), true) +
                " attracts a bunch of survivors with a fire." +
                makeQuery(Vars::KEY_SURVIVORLIST(), Lambdas::LM_PLAYER_SUBJECTIVE(), true) +
                "then causes a avalanche with " +
                makeQuery(Vars::KEY_SURVIVORLIST(), Lambdas::LM_PLAYER_POSESSIVE(), true) + " " +
                makeQuery(Vars::KEY_SURVIVORLIST(), Lambdas::LM_PLAYERWEAPON(), true) +
                ", burying " +
                makeQuery(Vars::KEY_DEADLIST(), Lambdas::LM_PLAYERNAME(), true) +
                " under a big pile of dirt, stones and thrown over trees.\n"


    };
    return ret.at(Random::get_random_Int(ret.size()));
}

std::string EventTextStorageContainer::oneVone() {
    static std::vector<std::string> ret{

            makeQuery(Vars::KEY_PLAYER(), Lambdas::LM_PLAYERNAME())
                + " manages to slay " +
                makeQuery(Vars::KEY_TARGETPLAYER(), Lambdas::LM_PLAYERNAME())
                + " with " +
                makeQuery(Vars::KEY_PLAYER(), Lambdas::LM_PLAYER_POSESSIVE())
                + " " +
                makeQuery(Vars::KEY_PLAYER(), Lambdas::LM_PLAYERWEAPON())
                + ".\n",

            "A slight breeze touches " +
                makeQuery(Vars::KEY_TARGETPLAYER(), Lambdas::LM_PLAYERNAME()) +
                "'s exposed belly as "+
                makeQuery(Vars::KEY_TARGETPLAYER(), Lambdas::LM_PLAYER_SUBJECTIVE()) +
                " lies in the warm seawater.\n" +
                makeQuery(Vars::KEY_TARGETPLAYER(), Lambdas::LM_PLAYER_SUBJECTIVE()) +
                "The salt's sting quickly fades while the water takes on a red tinge as" +
                makeQuery(Vars::KEY_TARGETPLAYER(), Lambdas::LM_PLAYER_SUBJECTIVE()) +
                " bleeds out from the wound inflicted by " +
                makeQuery(Vars::KEY_PLAYER(), Lambdas::LM_PLAYERNAME()) + "'s " +
                makeQuery(Vars::KEY_PLAYER(), Lambdas::LM_PLAYERWEAPON()) + ".\n",


            makeQuery(Vars::KEY_PLAYER(), Lambdas::LM_PLAYERNAME()) +
                " finds " +
                makeQuery(Vars::KEY_TARGETPLAYER(), Lambdas::LM_PLAYERNAME()) +
                "'s body. It looks like " +
                makeQuery(Vars::KEY_TARGETPLAYER(), Lambdas::LM_PLAYER_SUBJECTIVE()) +
                " died from starvation.\n",


            makeQuery(Vars::KEY_TARGETPLAYER(), Lambdas::LM_PLAYERNAME()) +
                " leans down to the river water, as " +
                makeQuery(Vars::KEY_TARGETPLAYER(), Lambdas::LM_PLAYER_POSESSIVE()) + " " +
                " neck is shattered by " +
                makeQuery(Vars::KEY_TARGETPLAYER(), Lambdas::LM_PLAYER_POSESSIVE()) + " own " +
                makeQuery(Vars::KEY_TARGETPLAYER(), Lambdas::LM_PLAYERWEAPON()) + ".\n" +
                makeQuery(Vars::KEY_PLAYER(), Lambdas::LM_PLAYERNAME()) +
                " had snuck up from behind.\n",


            makeQuery(Vars::KEY_TARGETPLAYER(), Lambdas::LM_PLAYERNAME()) +
                " creeps through the woods, as one of " +
                makeQuery(Vars::KEY_PLAYER(), Lambdas::LM_PLAYERNAME()) +
                "'s rogue " +
                makeQuery(Vars::KEY_PLAYER(), Lambdas::LM_PLAYERWEAPON()) +
                "s hits him in the back.\n He bleeds out shortly after.\n",

            "It is almost midnight as " +
                makeQuery(Vars::KEY_TARGETPLAYER(), Lambdas::LM_PLAYERNAME()) +
                " is awoken by a loud crack.\n" +
                makeQuery(Vars::KEY_TARGETPLAYER(), Lambdas::LM_PLAYER_SUBJECTIVE()) +
                " only has moments before " +
                makeQuery(Vars::KEY_TARGETPLAYER(), Lambdas::LM_PLAYER_SUBJECTIVE()) +
                " sees " +
                makeQuery(Vars::KEY_PLAYER(), Lambdas::LM_PLAYERNAME()) + "'s " +
                makeQuery(Vars::KEY_PLAYER(), Lambdas::LM_PLAYERWEAPON()) +
                " dropping from the tree, as the weapon crushes " +
                makeQuery(Vars::KEY_TARGETPLAYER(), Lambdas::LM_PLAYER_POSESSIVE()) +
                " skull.\n",

            makeQuery(Vars::KEY_TARGETPLAYER(), Lambdas::LM_PLAYERNAME()) +
                " has " +
                makeQuery(Vars::KEY_TARGETPLAYER(), Lambdas::LM_PLAYER_POSESSIVE()) + " " +
                makeQuery(Vars::KEY_TARGETPLAYER(), Lambdas::LM_PLAYERWEAPON()) +
                " in hand as " +
                makeQuery(Vars::KEY_TARGETPLAYER(), Lambdas::LM_PLAYER_SUBJECTIVE()) +
                " faces off against " +
                makeQuery(Vars::KEY_PLAYER(), Lambdas::LM_PLAYERNAME()) +
                ".\nThe two of them have a honorable battle, but eventually " +
                makeQuery(Vars::KEY_TARGETPLAYER(), Lambdas::LM_PLAYERNAME()) +
                " succumbs to " +
                makeQuery(Vars::KEY_TARGETPLAYER(), Lambdas::LM_PLAYERNAME()) + "'s " +
                makeQuery(Vars::KEY_TARGETPLAYER(), Lambdas::LM_PLAYERWEAPON()) +
                ".\n",




    };
    return ret.at(Random::get_random_Int(ret.size()));
}