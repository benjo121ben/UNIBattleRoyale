//
// Created by benja on 19/01/2022.
//

#ifndef GAME_BLACKBOARDKEYS_H
#define GAME_BLACKBOARDKEYS_H
#include<string>
struct BlackboardKeys{

    //keys for map
    static std::string PLAYERID();
    static std::string PLAYERMOVEDIR();
    static std::string ATTACKTARGETID();
};
#endif //GAME_BLACKBOARDKEYS_H
