//
// Created by benja on 18/01/2022.
//

#ifndef GAME_BASEEVENT_H
#define GAME_BASEEVENT_H
#include<string>
#include "../../PlayerInfo/Player.h"
class BaseEvent {
protected:
    std::string eventType;
    std::string eventText;
public:
    BaseEvent() = default;
    BaseEvent(const BaseEvent& e) = default;
    virtual std::string getEventType() const;
    virtual std::string getEventText() const;

};
#endif //GAME_BASEEVENT_H
