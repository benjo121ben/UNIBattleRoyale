//
// Created by benja on 19/01/2022.
//

#ifndef GAME_GAMEDATA_H
#define GAME_GAMEDATA_H
#include <vector>
#include <unordered_set>
#include "../PlayerInfo/Player.h"
#include "../MapInfo/GameMap.h"
struct GameData{

    std::vector<Player> allPlayersList;
    std::unordered_set<int> alivePlayerList;
    std::map<int,Coordinate> playerPositions;
    GameMap map;

};
#endif //GAME_GAMEDATA_H
