//
// Created by benja on 17/01/2022.
//
#include "GameManager.h"
#include "../Exceptions/GameExceptions.h"
#include "../BehaviourTree/BehaviourTree.h"
#include "../BehaviourTree/BTTemplates.h"

//private shortcut getters
GameMap& GameManager::map(){return gameData.map;}
std::unordered_set<int>& GameManager::alivePlayerList(){return gameData.alivePlayerList;}
std::vector<Player>& GameManager::allPlayerList(){return gameData.allPlayersList;}
std::map<int, Coordinate>& GameManager::playerPositions(){return gameData.playerPositions;}



GameManager::GameManager() : turnManager{gameData}{
    gameData.map = GameMap(GameMap::getMap1());
    turnManager.registerListener(textHandler);
    init_game();
}

GameManager::GameManager(GameMap&& setMap) : turnManager{gameData}{
    gameData.map = setMap;
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
    char playerNr[10] = {'0','1','2','3','4','5','6','7','8','9'};
    std::string ret {getMap().printMap(showSpawn)};
    /*for(int posNr : alivePlayerList()){
        Coordinate coord{playerPositions().at(posNr)};
        ret.at(coord.x + (map().sizeX + 1) * coord.y) = playerNr[posNr];
    }
    std::cout << ret;

    for(int posNr : alivePlayerList()){
        std::cout << posNr << "=" << allPlayerList().at(posNr).name << ",  ";
    }*/
    std::map<Coordinate, std::vector<int>> registeredCoords;
    for(auto posNr : alivePlayerList()){
        Coordinate coord{playerPositions().at(posNr)};
        if(registeredCoords.count(coord)){
            registeredCoords.at(coord).push_back(posNr);
        }
        else{
            ret.at(coord.x + (map().sizeX + 1) * coord.y) = playerNr[posNr];
            std::vector<int> playerList;
            playerList.push_back(posNr);
            registeredCoords.insert_or_assign(coord, playerList);
        }
    }

    std::cout << ret;

    for(auto& entry : registeredCoords){
        auto& presentPlayers {entry.second};
        std::cout << playerNr[presentPlayers.at(0)] << "=";

        for(int index{0}; index < presentPlayers.size(); ++index){
            Player& p = allPlayerList().at(presentPlayers.at(index));
            if(index != 0){
                std::cout << ", " << p.name;
            }
            else {
                std::cout << p.name;
            }
        }
        std::cout << "   ";
    }

    std::cout<<std::endl;
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
    if(allPlayerList().size() == playerPositions().size()) throw generic_game_error("already max amount of players");
    else{
        BehaviourTree tree {BTTemplates::testTree_Move_and_Attack(gameData)};
        int nr = allPlayerList().size();
        allPlayerList().push_back(p);
        alivePlayerList().emplace(nr);
        allPlayerList().at(nr).addBehaviour(tree, nr);
    }
}

void GameManager::registerPlayer(std::initializer_list<const Player> l){
    for(auto& p : l) {
        registerPlayer(p);
    }
}
void GameManager::registerPlayer(std::vector<Player> l){
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

bool GameManager::tick() {
    if(!started) startGame();
    started = true;
    textHandler.clearEvents();
    for(int nr : alivePlayerList()){
        turnManager.queueInstruction(nr, allPlayerList().at(nr).tick());
    }

    turnManager.handleTurn();
    printMap(false);
    textHandler.printEvents();
    if(alivePlayerList().size() == 1){
        std::cout << allPlayerList().at(*alivePlayerList().begin()).name << " has won the game." << std::endl;
        return false;
    }
    std::cout << std::endl;
    return true;
}

void GameManager::startGame() {
    int countPlayers = allPlayerList().size();
    int maxPlayers = playerPositions().size();
    for(int index = countPlayers; index < maxPlayers; ++index){
        playerPositions().erase(index);
    }
}


