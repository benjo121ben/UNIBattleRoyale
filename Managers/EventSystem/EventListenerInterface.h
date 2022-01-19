//
// Created by benja on 19/01/2022.
//

#ifndef GAME_EVENTHANDLER_H
#define GAME_EVENTHANDLER_H
#include "Events/BaseEvent.h"
class EventListenerInterface{
public:
    virtual void handleEvent(const BaseEvent& event) = 0;
};
#endif //GAME_EVENTHANDLER_H
