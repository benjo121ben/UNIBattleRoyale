//
// Created by benja on 17/01/2022.
//

#ifndef GAME_GAMEMANAGER_H
#define GAME_GAMEMANAGER_H
#include "TurnManager.h"
#include "GameData.h"


class GameMap;

class GameManager{
    bool started = false;
    GameData gameData;
    TurnManager turnManager;
    GameEventTextHandler textHandler;

    GameMap& map();
    std::set<int>& alivePlayerList();
    const std::set<int>& alivePlayerList() const;
    std::vector<Player>& allPlayerList();
    const std::vector<Player>& allPlayerList() const;
    std::map<int,Coordinate>& playerPositions();
    const std::map<int,Coordinate>& playerPositions() const;

    void init_game();
public:

    GameManager();
    explicit GameManager(GameMap&& map);
    explicit GameManager(GameMap& map);

    const GameMap& getMap() const;
    int getMaxPlayers() const;
    void printMap(bool showSpawn = false);

    void registerPlayer(const Player& p);
    void registerPlayer(std::initializer_list<const Player> l);
    void registerPlayer(std::vector<Player> l);
    void removePlayer(int index);
    void printEvents();
    bool tick();


    void startGame();
};
#endif //GAME_GAMEMANAGER_H
