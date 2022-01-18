//
// Created by benja on 18/01/2022.
//

#include "MoveEvent.h"
MoveEvent::MoveEvent(const Player& p, cardinal_directions dir) : BaseEvent(p), direction{dir}{
    eventType = "Movement";
    eventText = "" + p.name + " continued " + p.pronouns.possessive + " journey " + dir_to_string(dir) + ".\n";
}