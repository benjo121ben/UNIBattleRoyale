//
// Created by benja on 16/01/2022.
//

#ifndef GAME_GAMEMAP_H
#define GAME_GAMEMAP_H

#include<string>
#include "TileMap.h"



class GameMap : public TileMap<BRTile>{

public:
    static GameMap getMap1();
    static GameMap getMap2();
    static GameMap getMultifightTestMap();

    GameMap();
    GameMap(const GameMap& map);
    explicit GameMap(const std::string& mapString);

    GameMap& operator=(const GameMap& map);

    std::string printMap(bool showSpawns) const override;

};


#endif //GAME_GAMEMAP_H
