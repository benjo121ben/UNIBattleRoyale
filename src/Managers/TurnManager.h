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
    std::vector<int> interruptedList;
    std::vector<Player>& allPlayerList;
    std::vector<int> &playerList;
    std::map<int, Coordinate> &playerPositions;
    GameMap &map;

    std::map<int, TickInfo> instructions;

    void handleMove(int playerNr, const TickInfo &t);
    void handleFight(int p1ID, int p2ID);
public:
    TurnManager(GameData& dataObject);
    void queueInstruction(int playerID, const TickInfo& t);
    void handleTurn();
};


#endif //GAME_TURNMANAGER_H
