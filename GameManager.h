//
// Created by benja on 17/01/2022.
//

#ifndef GAME_GAMEMANAGER_H
#define GAME_GAMEMANAGER_H
#include "MapInfo/GameMap.h"
#include "PlayerInfo/Player.h"

class GameManager{
public:
    GameMap map;
    std::vector<Player> playerList;
    std::vector<Coordinate> playerPositions;

    void init_game();
public:
    GameManager();
    explicit GameManager(GameMap& map);
    std::string printMap();
};
#endif //GAME_GAMEMANAGER_H
