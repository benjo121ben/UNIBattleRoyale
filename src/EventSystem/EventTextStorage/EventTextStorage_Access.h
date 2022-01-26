//
// Created by benja on 24/01/2022.
//

#ifndef GAME_EVENTTEXTSTORAGE_ACCESS_H
#define GAME_EVENTTEXTSTORAGE_ACCESS_H


#include <string>
#include "TextVariables.h"

class EventTextStorage_Access {

public:
    static std::string getKill(const TextVariables& vars, bool groupFight);

};


#endif //GAME_EVENTTEXTSTORAGE_ACCESS_H
