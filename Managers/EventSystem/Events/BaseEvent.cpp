//
// Created by benja on 18/01/2022.
//
#include "BaseEvent.h"
BaseEvent::BaseEvent(const Player& player) : player{player}{}

BaseEvent::BaseEvent(const BaseEvent& e) : eventType{e.eventType}, eventText{e.eventText}, player{e.player}{}

std::string BaseEvent::getEventType() const{
    return eventType;
}
std::string BaseEvent::getEventText() const{
    return eventText;
}
