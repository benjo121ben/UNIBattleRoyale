//
// Created by benja on 18/01/2022.
//
#include "TurnManager.h"
#include "../Exceptions/GameExceptions.h"
#include "EventSystem/Events/Events.h"

TurnManager::TurnManager(GameData& dataObject) :
        allPlayerList{dataObject.allPlayersList}, playerList{dataObject.alivePlayerList}, playerPositions{dataObject.newPlayerPositions}, map{dataObject.map} {}

void TurnManager::queueInstruction(int playerID, const TickInfo& t){
    if(instructions.size() <6) {
        instructions.emplace(playerID, t);
    }
    else{
        throw generic_game_error("tried to queue new Turn instruction with full list");
    }
}
void TurnManager::handleTurn(){

    for(int playerNr {0}; playerNr < instructions.size(); ++playerNr){
        //checks if a players action was interupted by another player
        bool interrupted = false;
        for(auto id : interruptedList){
            if(id == playerNr) interrupted = true;
        }
        if(interrupted) continue;

        const TickInfo& t = instructions.at(playerNr);
        switch (t.type) {
            case TickInfo::move: {
                handleMove(playerNr, t);
                break;
            }
            case TickInfo::flee:
                break;
            case TickInfo::recover:
                break;
            case TickInfo::attack:
                break;
            case TickInfo::scout:
                break;
            case TickInfo::gather:
                break;
            case TickInfo::reinforce:
                break;
        }
    }
    instructions.clear();
}

void TurnManager::handleMove(int playerNr, const TickInfo &t) {
    auto dir = std::any_cast<cardinal_directions>(t.data);
    Coordinate coord = playerPositions.at(playerNr);
    switch(dir){
        case north:
            coord = Coordinate(coord.x, coord.y-1);
            break;
        case south:
            coord = Coordinate(coord.x, coord.y+1);
            break;
        case west:
            coord = Coordinate(coord.x-1, coord.y);
            break;
        case east:
            coord = Coordinate(coord.x+1, coord.y);
            break;
    }

    if(map.existsTileAt(coord)){
        for(int index{0}; index < playerPositions.size(); ++index){
            if(playerPositions.at(index) == coord){
                interruptedList.push_back(index);
                handleFight(playerList.at(playerNr), playerList.at(playerNr));
            }
        }
        playerPositions.at(playerNr) = coord;
        fireEvent(MoveEvent(allPlayerList.at(playerNr), dir));
    }
}

void TurnManager::handleFight(int p1ID, int p2ID) {
    /*auto winner = (playerList.at(p1ID).fight(allPlayerList.at(p2ID)) == -1) ? p1ID : p2ID;
    auto looser = (winner == p2ID) ? p2ID : p1ID;
    interruptedList.push_back(looser);
    fireEvent(MoveEvent(alivePlayerList.at(playerNr), dir));*/
}
