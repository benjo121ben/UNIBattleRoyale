//
// Created by benja on 18/01/2022.
//

#ifndef GAME_TURNMANAGER_H
#define GAME_TURNMANAGER_H
#include<vector>
#include "../MapInfo/GameMap.h"
#include "../PlayerInfo/Player.h"
#include "EventSystem/EventHandler.h"

class TurnManager {
    std::vector<Player> &playerList;
    std::vector<Coordinate> &playerPositions;
    GameMap &map;
    EventHandler &eventHandler;

    std::vector<TickInfo> instructions;

    void handleMove(int playerNr, const TickInfo &t);
public:
    TurnManager(EventHandler &eventHandler, std::vector<Player> &playerList, std::vector<Coordinate> &playerPositions, GameMap &map);

    void queueInstruction(const TickInfo& t);
    void handleTurn();


};


#endif //GAME_TURNMANAGER_H
