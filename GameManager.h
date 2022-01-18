//
// Created by benja on 17/01/2022.
//

#ifndef GAME_GAMEMANAGER_H
#define GAME_GAMEMANAGER_H
#include "MapInfo/GameMap.h"
#include "PlayerInfo/Player.h"
#include "TurnManager.h"

class GameManager{
    bool started = false;
    std::vector<Player> playerList;
    std::vector<Coordinate> playerPositions;
    GameMap map;
    TurnManager turnManager;

    void init_game();
public:

    GameManager();
    explicit GameManager(GameMap& map);

    const GameMap& getMap() const;
    [[nodiscard]] std::string printMap(bool showSpawn = false);

    void registerPlayer(const Player& p);
    void registerPlayer(std::initializer_list<const Player> l);
    void removePlayer(int index);
    void tick();
};
#endif //GAME_GAMEMANAGER_H
