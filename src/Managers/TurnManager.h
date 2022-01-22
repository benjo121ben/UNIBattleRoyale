//
// Created by benja on 18/01/2022.
//

#ifndef GAME_TURNMANAGER_H
#define GAME_TURNMANAGER_H
#include<vector>
#include<unordered_set>
#include "../MapInfo/GameMap.h"
#include "../PlayerInfo/Player.h"
#include "EventSystem/GameEventTextHandler.h"
#include "EventSystem/EventAnnouncer.h"
#include "GameData.h"

class TurnManager : public EventAnnouncer{
    std::vector<Player>& allPlayerList;
    std::unordered_set<int> interruptedList;
    std::unordered_set<int> &alive2PlayersList;
    std::vector<Coordinate> scheduledFightsList;
    std::map<int, Coordinate> &playerPositions;
    GameMap &map;

    std::map<int, TickInfo> instructions;

    bool isFightOnCoord(Coordinate coordinate);
    bool anotherPlayerOnTile(int playerID);
    void scheduleFight(Coordinate coordinate);
    void killPlayer(int looser);
    void killPlayer(const std::vector<Player>& looser);

    void handleMove(int playerNr, const TickInfo &t);
    void resolveAllFights();
    bool handleFight(int p1ID, int p2ID);
    bool handleSkirmish(std::vector<int>& participants);
public:
    explicit TurnManager(GameData& dataObject);
    void queueInstruction(int playerID, const TickInfo& t);
    void handleTurn();


};


#endif //GAME_TURNMANAGER_H
