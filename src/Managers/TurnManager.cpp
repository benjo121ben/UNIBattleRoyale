//
// Created by benja on 18/01/2022.
//
#include <algorithm>
#include "TurnManager.h"
#include "../Exceptions/GameExceptions.h"
#include "../EventSystem/Events/Events.h"
#include "../Random.h"

TurnManager::TurnManager(GameData& dataObject) :
        allPlayerList{dataObject.allPlayersList},
        alivePlayersList{dataObject.alivePlayerList},
        playerPositions{dataObject.playerPositions},
        map{dataObject.map} {}

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
        auto elem = instructions.begin();
        int playerNr = elem->first;
        if(interruptedList.count(playerNr) || alivePlayersList.count(playerNr) == 0) {
            instructions.erase(elem);
            continue;
        }
        auto& tickInfo {elem->second};

        switch (tickInfo.type) {
            case TickInfo::move: {
                handleMove(playerNr, tickInfo);
                break;
            }
            case TickInfo::recover:
                break;
            case TickInfo::attack:{
                scheduleFight(playerPositions.at(playerNr));
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
    resolveAllFights();
}

void TurnManager::handleMove(int playerNr, const TickInfo &t) {
    moveEventType type = normal;
    auto dir {t.getData<cardinal_directions>()};
    Coordinate coord = playerPositions.at(playerNr);
    if(isFightOnCoord(coord)){
        if(!allPlayerList.at(playerNr).skillCheck(Player::testType)){
            //fireEvent(MoveEvent(allPlayerList.at(playerNr), dir, failed_flee));
            return;
        }
        else{
            type = flee;
        }
    }
    switch(dir){
        case north:
            coord = Coordinate(coord.x, coord.y-1); break;
        case south:
            coord = Coordinate(coord.x, coord.y+1); break;
        case west:
            coord = Coordinate(coord.x-1, coord.y); break;
        case east:
            coord = Coordinate(coord.x+1, coord.y); break;
    }

    if(map.existsTileAt(coord)){
        playerPositions.at(playerNr) = coord;
        if(anotherPlayerOnTile(playerNr)){
            scheduleFight(coord);
            type = charge;
        }
        //fireEvent(MoveEvent(allPlayerList.at(playerNr), dir, type));
    }
}



bool TurnManager::handleFight(int p1ID, int p2ID) {
    if(!alivePlayersList.count(p1ID) || !alivePlayersList.count(p2ID)) return false;
    int winner = (allPlayerList.at(p1ID).fight(allPlayerList.at(p2ID)) == -1) ? p1ID : p2ID;
    auto looser = (winner == p1ID) ? p2ID : p1ID;
    fireEvent(KillEvent(allPlayerList.at(winner), allPlayerList.at(looser)));
    killPlayer(looser);
    return true;
}

void TurnManager::killPlayer(int looser) {
    interruptedList.insert(looser);
    alivePlayersList.erase(looser);
    playerPositions.erase(looser);
}

void TurnManager::scheduleFight(Coordinate coordinate) {
    for(auto& listCoord : scheduledFightsList){
        if(listCoord == coordinate) return;
    }
    scheduledFightsList.push_back(coordinate);
}

bool TurnManager::isFightOnCoord(Coordinate coordinate) {
    return std::any_of(scheduledFightsList.begin(), scheduledFightsList.end(), [coordinate](const Coordinate& checkCoord)-> bool {return checkCoord == coordinate;});
}

bool TurnManager::anotherPlayerOnTile(int playerNr) {
    auto coord = playerPositions.at(playerNr);
    for(auto playerPos {playerPositions.begin()}; playerPos != playerPositions.end(); playerPos++) {
        if (playerPos->first != playerNr && alivePlayersList.count(playerPos->first) && playerPos->second == coord) {
            return true;
        }
    }
    return false;
}

void TurnManager::resolveAllFights() {
    for(const auto& coord : scheduledFightsList){
        std::vector<int> playerList;
        for(const auto& elem : playerPositions){
            if(elem.second ==coord) playerList.push_back(elem.first);
        }
        if(playerList.size() == 2){
            handleFight(playerList.at(0), playerList.at(1));
        }
        else if(playerList.size() > 2){
            handleSkirmish(playerList);
        }
    }
    scheduledFightsList.clear();
}

bool TurnManager::handleSkirmish(std::vector<int> &participantIndices) {
    std::vector<const Player*> survivors;
    for(auto& index : participantIndices){
        survivors.push_back(&allPlayerList.at(index));
    }
    int deadAmount = Random::get_random_Int(survivors.size() - 2) + 1;
    std::vector<const Player*> deadList;
    while (deadAmount > 0){
        int index = Random::get_random_Int(survivors.size());
        deadList.push_back(survivors.at(index));
        survivors.erase(survivors.begin() + index);
        --deadAmount;
    }
    killPlayer(deadList);
    fireEvent(KillEvent(survivors, deadList));
    return true;
}



void TurnManager::killPlayer(const std::vector<const Player*> &looserList) {
    for(auto& looser : looserList){
        killPlayer(looser->getID());
    }
}
