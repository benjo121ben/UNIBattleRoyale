//
// Created by benja on 24/01/2022.
//

#ifndef GAME_TEXTVARIABLELAMBDAS_H
#define GAME_TEXTVARIABLELAMBDAS_H
#include<string>
#include<any>
#include<functional>

class Player;
class TextVariableLambdas{
    enum playerInfoType{
        name, weapon, pronoun_sub, pronoun_obj,pronoun_poss
    };
    static std::string getPlayerInfo(const std::any& an, playerInfoType type);
    static std::string getPlayerName(const std::any& p);
    static std::string getPlayerWeapon(const std::any& p);
    static std::string getPlayerPronoun_subjective(const std::any& p);
    static std::string getPlayerPronoun_possessive(const std::any& p);
    static std::string getPlayerPronoun_objective(const std::any& p);

public:
    static std::function<std::string(std::any)> getLambda(std::string);

    //KEYS TO ACCESS THE FUNCTIONS
    static std::string LM_PLAYERNAME(){return "LAMBDA_PLAYERNAME";}
    static std::string LM_PLAYERWEAPON(){return "LAMBDA_PLAYERWEAPON";}
    static std::string LM_PLAYER_SUBJECTIVE(){return "LAMBDA_PLAYER_SUBJECTIVE";}
    static std::string LM_PLAYER_OBJECTIVE(){return "LAMBDA_PLAYER_OBJECTIVE";}
    static std::string LM_PLAYER_POSESSIVE(){return "LAMBDA_PLAYER_POSSESSIVE";}


};

#endif //GAME_TEXTVARIABLELAMBDAS_H
