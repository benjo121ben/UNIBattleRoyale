#include <iostream>
#include "PlayerInfo/Player.h"
#include "MapInfo/GameMap.h"
#include "Managers/GameManager.h"
#include "Pathfinder/Pathfinder.h"
#include "Random.h"
#include "BehaviourTree/BehaviourTree.h"
#include "BehaviourTree/allNodes.h"


bool handleInput(GameManager &man, const std::string &line);

void printInputOptions();

int main() {

    Player p1("BigBoi", "Battleaxe", Pronouns::masculine());
    Player p2("Old Asian Man", "Nunchucks", Pronouns::masculine());
    Player p3("Super Woman", "Super Gun", Pronouns::feminine());
    Player p4("Super Worm", "Super Teeth", Pronouns::neutral());
    Player p5("tiny anime character", "Big ass sword", Pronouns::neutral());
    Player p6("big anime character", "small ass sword", Pronouns::neutral());
    GameManager man{GameMap::getMultifightTestMap()};


    man.registerPlayer({p1,p2,p3,p4,p5,p6});
    man.printMap();


    std::string line;
    bool running;
    do{
        std::cout << "-------------------------------------------\n\n";
        running = handleInput(man, line);


        std::cout << "input help: to see all commands." << std::endl;
        std::cout << "input a command to continue:" << std::endl;
    }while (running && std::getline(std::cin, line));

    return 0;
}

void printInputOptions() {

    std::cout << "command/shortcut: command description." << std::endl << std::endl;
    std::cout << "help / h: displays all comands of the menu you are in." << std::endl;
    std::cout << "next / n: advances the game to the next turn." << std::endl;
    std::cout << "events / e: shows current days events." << std::endl;
    std::cout << "map / m: shows current map." << std::endl;
    std::cout << "quit / q: Quits program." << std::endl;
}

bool handleInput(GameManager &man, const std::string &line) {
    if(line == "q" || line == "quit") return false;
    if(line == "next" || line == "n"){
        return man.tick();
    }
    else if(line == "map" || line == "m"){
        man.printMap();
    }
    else if(line == "e" || line == "events"){
        man.printEvents();
    }
    else if(line == "help" || line == "h"){
        printInputOptions();
    }

    return true;

}
