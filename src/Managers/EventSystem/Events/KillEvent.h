//
// Created by benja on 21/01/2022.
//

#ifndef GAME_KILLEVENT_H
#define GAME_KILLEVENT_H

#include <vector>
#include "BaseEvent.h"

class KillEvent : public BaseEvent{
public:
    KillEvent(const Player& survivor, const Player& deadPlayer);
    KillEvent(const std::vector<Player>& survivor, const std::vector<Player>& deadPlayer);
};


#endif //GAME_KILLEVENT_H
