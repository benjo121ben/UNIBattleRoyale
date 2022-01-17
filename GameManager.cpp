//
// Created by benja on 17/01/2022.
//
#include "GameManager.h"
#include "Exceptions/GameExceptions.h"




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

void GameManager::registerPlayer(const Player& p){
    if(started) throw game_started_error();
    if(playerList.size() == 6) throw generic_game_error("already max amount of players");
    else{
        playerList.push_back(p);
    }
}

void GameManager::removePlayer(int index) {
    if(started) throw game_started_error();
    if(playerList.size() <= index){
        throw generic_game_error("tried to remove Player from GameManager at invalid Index");
    }
    playerList.erase(playerList.begin()+index);
}


std::string GameManager::printMap(bool showSpawn){
    std::string ret {map.printMap(showSpawn)};
    char playerNr = '0';
    for(int posNr{0}; posNr < playerList.size(); ++posNr){
        Coordinate coord{playerPositions.at(posNr)};
        ret.at(coord.x + (map.sizeX + 1) * coord.y) = playerNr++;
    }
    return ret;
}