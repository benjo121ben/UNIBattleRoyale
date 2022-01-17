//
// Created by benja on 17/01/2022.
//
#include "GameManager.h"




GameManager::GameManager() : map{GameMap(GameMap::getMap1())}{
    init_game();
}

GameManager::GameManager(GameMap& setMap) : map{setMap}{
    init_game();
}


void GameManager::init_game(){
    for(int y {0}; y < map.sizeY; ++y){
        for(int x {0}; x < map.sizeX; ++x){
            if(map.getTileAt(x,y)->isSpawn()){
                playerPositions.emplace_back(x,y);
            }
        }
    }
}

std::string GameManager::printMap(){
    return map.printMap();
}