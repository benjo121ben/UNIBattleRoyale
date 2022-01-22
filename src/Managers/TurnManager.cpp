//
// Created by benja on 18/01/2022.
//
#include "TurnManager.h"
#include "../Exceptions/GameExceptions.h"
#include "EventSystem/Events/Events.h"

TurnManager::TurnManager(GameData& dataObject) :
        allPlayerList{dataObject.allPlayersList}, alive2PlayersList{dataObject.alivePlayerList}, playerPositions{dataObject.playerPositions}, map{dataObject.map} {}

void TurnManager::queueInstruction(int playerID, const TickInfo& t){
    if(instructions.size() <allPlayerList.size()) {
        instructions.emplace(playerID, t);
    }
    else{
        throw generic_game_error("tried to queue new Turn instruction with full list");
    }
}
void TurnManager::handleTurn(){

    while (!instructions.empty()){
        //checks if a players action was interupted by another player
        bool interrupted = false;
        auto elem = instructions.begin();
        int playerNr = elem->first;
        for(auto id : interruptedList){
            if(id == playerNr) interrupted = true;
        }
        if(interrupted || alive2PlayersList.count(playerNr) == 0) {
            instructions.erase(elem);
            continue;
        }
        auto& tickInfo {elem->second};

        switch (tickInfo.type) {
            case TickInfo::move: {
                handleMove(playerNr, tickInfo);
                break;
            }
            case TickInfo::flee:
                break;
            case TickInfo::recover:
                break;
            case TickInfo::attack:{
                handleFight(playerNr, tickInfo);
                break;
            }
            case TickInfo::scout:
                break;
            case TickInfo::gather:
                break;
            case TickInfo::reinforce:
                break;
        }
        instructions.erase(elem);
    }
    interruptedList.clear();
}

void TurnManager::handleMove(int playerNr, const TickInfo &t) {
    auto dir {t.getData<cardinal_directions>()};
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
        fireEvent(MoveEvent(allPlayerList.at(playerNr), dir));
        auto end = playerPositions.end();
        for(auto playerPos {playerPositions.begin()}; alive2PlayersList.count(playerNr) != 0 && playerPos != end; playerPos++){
            if(playerPos->first != playerNr && playerPos->second == coord){
                interruptedList.push_back(playerPos->first);
                if(handleFight(playerNr, playerPos->first)){
                    playerPos = playerPositions.begin();
                    end = playerPositions.end();
                }
            }
        }
    }
}

bool TurnManager::handleFight(int p1ID, const TickInfo& t) {
    return handleFight(p1ID, t.getData<int>());
}

bool TurnManager::handleFight(int p1ID, int p2ID) {
    if(!alive2PlayersList.count(p1ID) || !alive2PlayersList.count(p2ID)) return false;
    int winner = (allPlayerList.at(p1ID).fight(allPlayerList.at(p2ID)) == -1) ? p1ID : p2ID;
    auto looser = (winner == p1ID) ? p2ID : p1ID;
    fireEvent(KillEvent(allPlayerList.at(winner), allPlayerList.at(looser)));
    killPlayer(looser);
    return true;
}

void TurnManager::killPlayer(int looser) {
    interruptedList.push_back(looser);
    alive2PlayersList.erase(looser);
    playerPositions.erase(looser);
}
