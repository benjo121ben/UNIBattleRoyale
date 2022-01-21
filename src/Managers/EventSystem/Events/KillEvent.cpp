//
// Created by benja on 21/01/2022.
//

#include "KillEvent.h"

KillEvent::KillEvent(const Player &player, const Player &target) : BaseEvent(player), target{target}{
    eventType = "Kill";
    eventText = "" + player.name + " manages to slay " + target.name + " with " + player.pronouns.possessive + " " + player.weapon + ".\n";
}
