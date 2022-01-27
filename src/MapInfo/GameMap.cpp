//
// Created by benja on 16/01/2022.
//

#include "GameMap.h"
#include<iostream>

GameMap GameMap::getMap1() {
    return  GameMap(
               "~~~~~~~~~~~~~~~~~~~~\n"
                        "~~~~~~~pp##p~~~pp~~~\n"
                        "~~~~~p0#######p0~~~~\n"
                        "~~~~pp~~~##~~~~pppp~\n"
                        "~~~~~pp#MMMM##pp~~~~\n"
                        "~~~~~p0#MMM~~##0p~~~\n"
                        "~~~~~pp##MMM~#pp~~~~\n"
                        "~~~~~~~pp#M##p0~~~~~\n"
                        "~~~~~~~~0pp~~~~~~~~~\n"
                        "~~~~~~~~~~~~~~~~~~~~\n"
    );
}

GameMap GameMap::getMap2() {
    return  GameMap(
   "~~~~~~~~~~~~~~~~~~~~\n"
            "~~~~~pp###0##pp~~~~~\n"
            "~~~~pp0pp###0###~~~~\n"
            "~~~~~pp#MMMM##pp~~~~\n"
            "~~~~~p0#MMM####0p~~~\n"
            "~~~~~~p##M0M~#pp~~~~\n"
            "~~~~~~~~p#M##pp~~~~~\n"
            "~~~~~~~~~~~~~~~~~~~~\n"
    );
}

GameMap GameMap::getMultifightTestMap() {
    return GameMap(
            "000\n"
                     "p00\n"
                     "p0p\n"
    );
}

GameMap::GameMap(){}

GameMap::GameMap(const GameMap& map){
    this->sizeX = map.sizeX;
    this->sizeY = map.sizeY;
    for(int y{0}; y < sizeY; ++y) {
        for (int x{0}; x < sizeX; ++x) {
            add(new BRTile( *map.getTileAt(x,y)));
        }
    }
}

GameMap& GameMap::operator=(const GameMap& map){
    this->sizeX = map.sizeX;
    this->sizeY = map.sizeY;
    for(int y{0}; y < sizeY; ++y) {
        for (int x{0}; x < sizeX; ++x) {
            add(new BRTile( *map.getTileAt(x,y)));
        }
    }
    return *this;
}

GameMap::GameMap(const std::string& mapString) {
    int x = 0;
    int y = 0;
    for (const auto& ch: mapString){
        switch (ch) {
            case '~': add(new BRTile(x,y,Tile::water)); x++; break;
            case 'p': add(new BRTile(x,y,Tile::plains)); x++; break;
            case '#': add(new BRTile(x,y,Tile::forest)); x++; break;
            case 'M': add(new BRTile(x,y,Tile::mountain)); x++; break;
            case '0': add(new BRTile(x,y,Tile::plains, true)); x++; break;
            case '\n' : y++; x = 0; break;
            default: break;
        }
    }
}

std::string GameMap::printMap(bool showSpawns) const{
    return TileMap::printMap(showSpawns);
}

