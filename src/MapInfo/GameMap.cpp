//
// Created by benja on 16/01/2022.
//

#include "GameMap.h"
#include<iostream>

std::string GameMap::getMap1() {
    const static std::string map1(  "~~~~~~~~~~~~~~~~~~~~\n"
                                    "~~~~~~~pp##p~~~pp~~~\n"
                                    "~~~~~p0#######p0~~~~\n"
                                    "~~~~pp~~~##~~~~pppp~\n"
                                    "~~~~~pp#MMMM##pp~~~~\n"
                                    "~~~~~p0#MMM~~##0p~~~\n"
                                    "~~~~~pp##MMM~#pp~~~~\n"
                                    "~~~~~~~pp#M##p0~~~~~\n"
                                    "~~~~~~~~0pp~~~~~~~~~\n"
                                    "~~~~~~~~~~~~~~~~~~~~\n");
    return map1;
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

