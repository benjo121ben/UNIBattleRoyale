//
// Created by benja on 21/01/2022.
//

#include "KillEvent.h"
#include "../EventTextStorage/TextVariables.h"
#include "../EventTextStorage/EventTextStorage_Access.h"

KillEvent::KillEvent(const Player &survivor, const Player &deadPlayer) {
    eventType = "Kill";
    TextVariables vars;
    vars.setValue(TextVariables::KEY_PLAYER(), survivor);
    vars.setValue(TextVariables::KEY_TARGETPLAYER(), deadPlayer);
    eventText = EventTextStorage_Access::getKill(vars, false);
}

KillEvent::KillEvent(const std::vector<Player> &survivorList, const std::vector<Player> &deadPlayerList) {
    eventType = "Kill";
    TextVariables vars;
    vars.setValue<std::vector<Player>>(TextVariables::KEY_SURVIVORLIST(), survivorList);
    vars.setValue<std::vector<Player>>(TextVariables::KEY_DEADLIST(), deadPlayerList);
    eventText = EventTextStorage_Access::getKill(vars, true);
}
