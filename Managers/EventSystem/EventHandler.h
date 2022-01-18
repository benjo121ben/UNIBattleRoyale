//
// Created by benja on 18/01/2022.
//

#ifndef GAME_EVENTHANDLER_H
#define GAME_EVENTHANDLER_H
#include<vector>
#include "Events/BaseEvent.h"

class EventHandler {
    std::vector<BaseEvent>events;
public:
    EventHandler() = default;
    void registerEvent(const BaseEvent& e);
    void printEvents();

};


#endif //GAME_EVENTHANDLER_H
