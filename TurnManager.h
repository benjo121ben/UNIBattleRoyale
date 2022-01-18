//
// Created by benja on 18/01/2022.
//

#ifndef GAME_TURNMANAGER_H
#define GAME_TURNMANAGER_H
#include<vector>
#include "MapInfo/GameMap.h"
#include "PlayerInfo/Player.h"

class TurnManager {
    std::vector<Player> &playerList;
    std::vector<Coordinate> &playerPositions;
    GameMap &map;
    std::vector<TickInfo> instructions;
public:
    TurnManager(std::vector<Player> &playerList, std::vector<Coordinate> &playerPositions, GameMap &map);

    void queueInstruction(const TickInfo& t);
    void handleTurn();
};


#endif //GAME_TURNMANAGER_H
