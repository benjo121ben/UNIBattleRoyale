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
    std::unordered_set<int>& alivePlayerList();
    std::vector<Player>& allPlayerList();
    std::map<int,Coordinate>& playerPositions();

    void init_game();
public:

    GameManager();
    explicit GameManager(GameMap&& map);
    explicit GameManager(GameMap& map);

    const GameMap& getMap() const;
    void printMap(bool showSpawn = false);

    void registerPlayer(const Player& p);
    void registerPlayer(std::initializer_list<const Player> l);
    void removePlayer(int index);
    void printEvents();
    bool tick();


    void startGame();
};
#endif //GAME_GAMEMANAGER_H
