//
// Created by benja on 18/01/2022.
//
#include"../../Random.h"
#include "MoveEvent.h"
#include "../EventTextStorage/EventTextStorage_Access.h"
MoveEvent::MoveEvent(const Player& p, cardinal_directions dir, moveEventType type) : direction{dir}{
    //if(rand.get_random_Int())
    eventType = "Movement";
    if(type == failed_flee){
        eventText = "";
    }
    else{
        TextVariables vars;
        vars.setValue(TextVariables::KEY_PLAYER(), p);
        vars.setValue(TextVariables::MOVE_DIR(), dir);
        eventText = EventTextStorage_Access::getMove(vars);
    }
}