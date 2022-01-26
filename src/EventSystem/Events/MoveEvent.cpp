//
// Created by benja on 18/01/2022.
//
#include"../../Random.h"
#include "MoveEvent.h"
MoveEvent::MoveEvent(const Player& p, cardinal_directions dir, moveEventType type) : direction{dir}{
    Random rand;
    //if(rand.get_random_Int())
    eventType = "Movement";
    eventText = "" + p.name + " continued " + p.pronouns.possessive + " journey " + dir_to_string(dir) + ".\n";
}