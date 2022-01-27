//
// Created by benja on 18/01/2022.
//

#include "GameEventTextHandler.h"
#include<iostream>



void GameEventTextHandler::handleEvent(const BaseEvent& e){
    this->events.push_back(e);
}

void GameEventTextHandler::printEvents(){
    std::cout << "\nEVENTS:" << std::endl;
    for(const BaseEvent& e : events){
        std::cout <<"* " << e.getEventText();
    }
    std::cout << std::endl;
}

void GameEventTextHandler::clearEvents(){
    events.clear();
}