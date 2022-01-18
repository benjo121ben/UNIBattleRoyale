//
// Created by benja on 18/01/2022.
//

#include "EventHandler.h"
#include<iostream>



void EventHandler::registerEvent(const BaseEvent& e){
    this->events.push_back(e);
}

void EventHandler::printEvents(){
    for(const BaseEvent& e : events){
        std::cout << e.getEventText();
    }
    events.clear();
}