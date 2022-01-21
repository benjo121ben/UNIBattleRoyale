//
// Created by benja on 19/01/2022.
//

#ifndef GAME_EVENTANNOUNCER_H
#define GAME_EVENTANNOUNCER_H
#include "Events/BaseEvent.h"
#include "EventListenerInterface.h"
#include<vector>
class EventAnnouncer{
    std::vector<EventListenerInterface *> listeners;
public:
    void registerListener(EventListenerInterface& e);
    void fireEvent(const BaseEvent& e);
};
#endif //GAME_EVENTANNOUNCER_H
