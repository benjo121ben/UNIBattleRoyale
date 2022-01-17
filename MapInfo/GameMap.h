//
// Created by benja on 16/01/2022.
//

#ifndef GAME_GAMEMAP_H
#define GAME_GAMEMAP_H

#include<string>
#include "TileMap.h"



class GameMap : public TileMap<BRTile>{

public:
    static std::string getMap1();

    GameMap();
    explicit GameMap(const std::string& mapString);

    std::string printMap(bool showSpawns) override;

};


#endif //GAME_GAMEMAP_H
