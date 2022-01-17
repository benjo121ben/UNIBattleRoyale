//
// Created by benja on 16/01/2022.
//

#ifndef GAME_GAMEMAP_H
#define GAME_GAMEMAP_H

#include<string>
#include "TileMap.h"



class GameMap : public TileMap<BRTile>{

public:

    GameMap();
    explicit GameMap(const std::string& mapString);
    static std::string getMap1();
};


#endif //GAME_GAMEMAP_H
