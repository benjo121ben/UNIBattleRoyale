//
// Created by benja on 18/01/2022.
//
#include "TurnManager.h"
#include "../Exceptions/GameExceptions.h"
#include "EventSystem/Events/Events.h"

TurnManager::TurnManager(std::vector<Player> &playerList, std::vector<Coordinate> &playerPositions, GameMap &map) :
    playerList{playerList}, playerPositions{playerPositions}, map{map} {}

void TurnManager::queueInstruction(const TickInfo& t){
    if(instructions.size() <6) {
        instructions.push_back(t);
    }
    else{
        throw generic_game_error("tried to queue new Turn instruction with full list");
    }
}
void TurnManager::handleTurn(){

    for(int playerNr {0}; playerNr < instructions.size(); ++playerNr){
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
        playerPositions.at(playerNr) = coord;
        fireEvent(MoveEvent(playerList.at(playerNr), dir));
    }
}
