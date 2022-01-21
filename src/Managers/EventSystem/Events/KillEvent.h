//
// Created by benja on 21/01/2022.
//

#ifndef GAME_KILLEVENT_H
#define GAME_KILLEVENT_H
#include "BaseEvent.h"

class KillEvent : public BaseEvent{
    const Player& target;
public:
    KillEvent(const Player& player, const Player& target);
};


#endif //GAME_KILLEVENT_H
