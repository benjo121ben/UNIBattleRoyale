//
// Created by benja on 19/01/2022.
//

#include "EventAnnouncer.h"

void EventAnnouncer::registerListener(EventListenerInterface& e){
    listeners.push_back(&e);
}

void EventAnnouncer::fireEvent(const BaseEvent& e){
    for(auto listener : listeners){
        listener->handleEvent(e);
    }
}
