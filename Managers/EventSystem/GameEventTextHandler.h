//
// Created by benja on 18/01/2022.
//

#ifndef GAME_GAMEEVENTTEXTHANDLER_H
#define GAME_GAMEEVENTTEXTHANDLER_H
#include<vector>
#include "Events/BaseEvent.h"
#include "EventListenerInterface.h"

class GameEventTextHandler : public EventListenerInterface{
    std::vector<BaseEvent>events;
public:
    GameEventTextHandler() = default;
    void handleEvent(const BaseEvent& e) override;
    void printEvents();
    void clearEvents();

};


#endif //GAME_GAMEEVENTTEXTHANDLER_H
