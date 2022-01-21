//
// Created by benja on 18/01/2022.
//

#ifndef GAME_TURNMANAGER_H
#define GAME_TURNMANAGER_H
#include<vector>
#include "../MapInfo/GameMap.h"
#include "../PlayerInfo/Player.h"
#include "EventSystem/GameEventTextHandler.h"
#include "EventSystem/EventAnnouncer.h"
#include "GameData.h"

class TurnManager : public EventAnnouncer{
    std::vector<Player> &playerList;
    std::vector<Coordinate> &playerPositions;
    GameMap &map;

    std::vector<TickInfo> instructions;

    void handleMove(int playerNr, const TickInfo &t);
public:
    TurnManager(GameData& dataObject);

    void queueInstruction(const TickInfo& t);
    void handleTurn();


};


#endif //GAME_TURNMANAGER_H
