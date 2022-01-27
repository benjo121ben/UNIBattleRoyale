//
// Created by benja on 18/01/2022.
//

#ifndef GAME_MOVEEVENT_H
#define GAME_MOVEEVENT_H
#include "BaseEvent.h"
#include "../../MapInfo/cardinal_directions.h"

enum moveEventType{
    normal, charge, flee, failed_flee
};

class MoveEvent : public BaseEvent{
    const cardinal_directions direction;
public:

    MoveEvent(const Player& p, cardinal_directions dir, moveEventType type);
};


#endif //GAME_MOVEEVENT_H
