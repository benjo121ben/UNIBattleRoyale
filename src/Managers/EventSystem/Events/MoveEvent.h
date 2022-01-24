//
// Created by benja on 18/01/2022.
//

#ifndef GAME_MOVEEVENT_H
#define GAME_MOVEEVENT_H
#include "BaseEvent.h"
#include "../../../MapInfo/cardinal_directions.h"


class MoveEvent : public BaseEvent{
    const cardinal_directions direction;
public:
    enum moveEventType{
        normal, mayCauseAttack, flee, flee_back_into_fight
    };
    MoveEvent(const Player& p, cardinal_directions dir, moveEventType type);
};


#endif //GAME_MOVEEVENT_H
