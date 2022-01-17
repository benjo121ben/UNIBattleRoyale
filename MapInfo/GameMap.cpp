//
// Created by benja on 16/01/2022.
//

#include "GameMap.h"
#include<iostream>

std::string GameMap::getMap1() {
    const static std::string map1("~~~~~~~~~~~~~~~~~~~~\n"
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

GameMap::GameMap(const std::string& mapString) {
    int x = 0;
    int y = 0;
    for (const auto& ch: mapString){
        switch (ch) {
            case '~': add(BRTile(x,y,Tile::water)); x++; break;
            case 'p': add(BRTile(x,y,Tile::plains)); x++; break;
            case '#': add(BRTile(x,y,Tile::forest)); x++; break;
            case 'M': add(BRTile(x,y,Tile::mountain)); x++; break;
            case '0': add(BRTile(x,y,Tile::plains, true)); x++; break;
            case '\n' : y++; x = 0; break;
            default: break;
        }
    }
}

