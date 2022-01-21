//
// Created by benja on 17/01/2022.
//
#include "GameManager.h"
#include "../Exceptions/GameExceptions.h"
#include "../BehaviourTree/BehaviourTree.h"
#include "../BehaviourTree/BTTemplates.h"

//private shortcut getters
GameMap& GameManager::map(){return gameData.map;}
std::vector<int>& GameManager::alivePlayerList(){return gameData.alivePlayerList;}
std::vector<Player>& GameManager::allPlayerList(){return gameData.allPlayersList;}
std::map<int, Coordinate>& GameManager::playerPositions(){return gameData.newPlayerPositions;}



GameManager::GameManager() : turnManager{gameData}{
    gameData.map = GameMap(GameMap::getMap1());
    turnManager.registerListener(textHandler);
    init_game();
}

GameManager::GameManager(GameMap& setMap) : turnManager{gameData}{
    gameData.map = setMap;
    turnManager.registerListener(textHandler);
    init_game();
}


const GameMap& GameManager::getMap() const{
    return gameData.map;
}

void GameManager::printMap(bool showSpawn){
    std::string ret {getMap().printMap(showSpawn)};
    char playerNr = '0';
    for(int posNr : alivePlayerList()){
        Coordinate coord{playerPositions().at(posNr)};
        ret.at(coord.x + (map().sizeX + 1) * coord.y) = playerNr++;
    }
    std::cout << ret;

    for(int posNr : alivePlayerList()){
        std::cout << posNr << "=" << allPlayerList().at(posNr).name << ",  ";
    }
    std::cout<<std::endl;
    std::cout<<std::endl;
}



void GameManager::init_game(){
    int counter {0};
    for(int y {0}; y < map().sizeY; ++y){
        for(int x {0}; x < map().sizeX; ++x){
            if(map().getTileAt(x,y)->isSpawn()){
                playerPositions().emplace(counter++,Coordinate(x,y));
            }
        }
    }
}



void GameManager::registerPlayer(const Player& p){
    if(started) throw game_started_error();
    if(allPlayerList().size() == 6) throw generic_game_error("already max amount of players");
    else{
        BehaviourTree tree {BTTemplates::testTree_Move_and_Attack(gameData)};
        int nr = allPlayerList().size();
        allPlayerList().push_back(p);
        alivePlayerList().push_back(nr);
        allPlayerList().at(nr).addBehaviour(tree, nr);
    }
}

void GameManager::registerPlayer(std::initializer_list<const Player> l){
    for(auto& p : l) {
        registerPlayer(p);
    }
}

void GameManager::removePlayer(int index) {
    if(started) throw game_started_error();
    if(allPlayerList().size() <= index){
        throw generic_game_error("tried to remove Player from GameManager at invalid Index");
    }
    allPlayerList().erase(allPlayerList().begin() + index);
}


void GameManager::printEvents(){
    textHandler.printEvents();
}

void GameManager::tick() {
    started = true;
    textHandler.clearEvents();
    for(int nr : alivePlayerList()){
        turnManager.queueInstruction(nr, allPlayerList().at(nr).tick());
    }

    turnManager.handleTurn();
    textHandler.printEvents();
    printMap(false);
    std::cout << std::endl;
}


