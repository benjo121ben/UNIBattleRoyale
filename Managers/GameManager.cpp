//
// Created by benja on 17/01/2022.
//
#include "GameManager.h"
#include "../Exceptions/GameExceptions.h"
#include "../BehaviourTree/BehaviourTree.h"

GameMap& GameManager::map(){return gameData.map;}
std::vector<Player>& GameManager::playerList(){return gameData.playerList;}
std::vector<Coordinate>& GameManager::playerPositions(){return gameData.playerPositions;}



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
    std::string ret {gameData.map.printMap(showSpawn)};
    char playerNr = '0';
    for(int posNr{0}; posNr < gameData.playerList.size(); ++posNr){
        Coordinate coord{gameData.playerPositions.at(posNr)};
        ret.at(coord.x + (gameData.map.sizeX + 1) * coord.y) = playerNr++;
    }
    std::cout << ret;

    for(int posNr{0}; posNr < gameData.playerList.size(); ++posNr){
        std::cout << posNr << "=" << gameData.playerList.at(posNr).name << ",  ";
    }
    std::cout<<std::endl;
    std::cout<<std::endl;
}



void GameManager::init_game(){
    for(int y {0}; y < gameData.map.sizeY; ++y){
        for(int x {0}; x < gameData.map.sizeX; ++x){
            if(gameData.map.getTileAt(x,y)->isSpawn()){
                gameData.playerPositions.emplace_back(x,y);
            }
        }
    }
}



void GameManager::registerPlayer(const Player& p){
    if(started) throw game_started_error();
    if(playerList().size() == 6) throw generic_game_error("already max amount of players");
    else{
        BehaviourTree tree{gameData};
        playerList().push_back(p);
        auto nr = playerList().size()-1;
        playerList().at(nr).addBehaviour(tree, nr);
    }
}

void GameManager::registerPlayer(std::initializer_list<const Player> l){
    for(auto p : l) {
        registerPlayer(p);
    }
}

void GameManager::removePlayer(int index) {
    if(started) throw game_started_error();
    if(playerList().size() <= index){
        throw generic_game_error("tried to remove Player from GameManager at invalid Index");
    }
    playerList().erase(playerList().begin()+index);
}


void GameManager::printEvents(){
    textHandler.printEvents();
}

void GameManager::tick() {
    started = true;
    textHandler.clearEvents();
    for(const Player& p : playerList()){
        turnManager.queueInstruction(p.tick());
    }

    turnManager.handleTurn();
    textHandler.printEvents();
    printMap(false);
    std::cout << std::endl;
}


