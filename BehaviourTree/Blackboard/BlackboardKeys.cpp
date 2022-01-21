//
// Created by benja on 19/01/2022.
//

#include "BlackboardKeys.h"

std::string BlackboardKeys::PLAYERID(){
    static std::string PLAYERID = "PLAYERID";
    return PLAYERID;
}




std::string BlackboardKeys::PLAYERMOVEDIR(){
    static std::string PLAYERMOVEDIR = "PLAYERMOVEDIR";
    return PLAYERMOVEDIR;
}
