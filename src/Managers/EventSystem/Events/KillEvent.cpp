//
// Created by benja on 21/01/2022.
//

#include "KillEvent.h"
#include "TextTranslator/EventTextTranslator.h"

KillEvent::KillEvent(const Player &survivor, const Player &deadPlayer) {
    eventType = "Kill";
    eventText = "" + survivor.name + " manages to slay " + deadPlayer.name + " with " + survivor.pronouns.possessive + " " + survivor.weapon + ".\n";
}

KillEvent::KillEvent(const std::vector<Player> &survivorList, const std::vector<Player> &deadPlayerList) {
    eventType = "Kill";
    if(survivorList.size() > 1){
        eventText = "Some Participants run into eachother:\nHesitantly, ";
        eventText += EventTextTranslator::outputList<Player>(survivorList, [](const Player& p){return p.name;});
        eventText +=  " team up and kill ";
        eventText += EventTextTranslator::outputList<Player>(deadPlayerList, [](const Player& p){return p.name;});
        eventText += "\n";

    }
    else{
        eventText = "As a fight breaks out ";
        eventText += EventTextTranslator::outputList<Player>(deadPlayerList, [](const Player& p){return p.name;});
        eventText += " are killed in the skirmish, leaving " + survivorList.at(0).name + " as the lone survivor";
        eventText += "\n";
    }
}
