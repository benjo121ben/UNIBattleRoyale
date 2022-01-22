//
// Created by benja on 21/01/2022.
//

#include "KillEvent.h"

KillEvent::KillEvent(const Player &survivor, const Player &deadPlayer) {
    eventType = "Kill";
    eventText = "" + survivor.name + " manages to slay " + deadPlayer.name + " with " + survivor.pronouns.possessive + " " + survivor.weapon + ".\n";
}

KillEvent::KillEvent(const std::vector<Player> &survivorList, const std::vector<Player> &deadPlayerList) {
    eventType = "Kill";
    if(survivorList.size() > 1){
        eventText = "As some Participants run into eachother, hesitantly ";
        for(int index{0}; index < survivorList.size(); ++index){
            if(index == survivorList.size()-2 && survivorList.size() > 1){
                eventText += survivorList.at(index).name + " and ";
            }
            else if(index < survivorList.size()-2){
                eventText += survivorList.at(index).name + ", ";
            }
            else {
                eventText += survivorList.at(index).name;
            }
        }
        eventText +=  " team up and kill ";
        for(int index{0}; index < deadPlayerList.size(); ++index){
            if(index == deadPlayerList.size()-2 && deadPlayerList.size() > 1){
                eventText += deadPlayerList.at(index).name + " and ";
            }
            else if(index < deadPlayerList.size()-2){
                eventText += deadPlayerList.at(index).name + ", ";
            }
            else {
                eventText += deadPlayerList.at(index).name;
            }
        }
        eventText += "\n";

    }
    else{
        eventText = "As a fight breaks out ";
        for(int index{0}; index < deadPlayerList.size(); ++index){
            if(index == deadPlayerList.size()-2 && deadPlayerList.size() > 1){
                eventText += deadPlayerList.at(index).name + " and ";
            }
            else if(index < deadPlayerList.size()-2){
                eventText += deadPlayerList.at(index).name + ", ";
            }
            else {
                eventText += deadPlayerList.at(index).name;
            }
        }
        eventText += " are killed in the skirmish, leaving " + survivorList.at(0).name + " as the lone survivor";
        eventText += "\n";
    }
}
