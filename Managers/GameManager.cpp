//
// Created by benja on 17/01/2022.
//
#include "GameManager.h"
#include "../Exceptions/GameExceptions.h"
#include "../BehaviourTree/BehaviourTree.h"
#include "../BehaviourTree/BTTemplates.h"

//private shortcut getters
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
    std::string ret {getMap().printMap(showSpawn)};
    char playerNr = '0';
    for(int posNr{0}; posNr < playerList().size(); ++posNr){
        Coordinate coord{playerPositions().at(posNr)};
        ret.at(coord.x + (map().sizeX + 1) * coord.y) = playerNr++;
    }
    std::cout << ret;

    for(int posNr{0}; posNr < playerList().size(); ++posNr){
        std::cout << posNr << "=" << playerList().at(posNr).name << ",  ";
    }
    std::cout<<std::endl;
    std::cout<<std::endl;
}



void GameManager::init_game(){
    for(int y {0}; y < map().sizeY; ++y){
        for(int x {0}; x < map().sizeX; ++x){
            if(map().getTileAt(x,y)->isSpawn()){
                playerPositions().emplace_back(x,y);
            }
        }
    }
}



void GameManager::registerPlayer(const Player& p){
    if(started) throw game_started_error();
    if(playerList().size() == 6) throw generic_game_error("already max amount of players");
    else{
        BehaviourTree tree {BTTemplates::move_towards_nearest_enemy(gameData)};
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


