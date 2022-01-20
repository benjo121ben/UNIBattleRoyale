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

    Selector s;
    s.push_back_child(new CoutDebugNode("Test 1", failure));
    s.push_back_child(new CoutDebugNode("Test 2", failure));
    s.push_back_child(new CoutDebugNode("Test 3", running));
    s.push_back_child(new CoutDebugNode("Test 4", success));
    GameData data;
    BTBlackboard bb{data};
    std::cout << s.traverse(&bb) << std::endl;
    std::cout << s.traverse(&bb) << std::endl;

    return 0;
    Player p1("Benji", "Sword", Pronouns::masculine());
    Player p2("Lena", "Axe", Pronouns::feminine());
    Player p3("Froggy", "Tongue", Pronouns::neutral());
    GameManager man;




    //Coordinate start(7,1);
    //Coordinate end(9,3);
    //Pathfinder::outputPath(man.getMap(),start,end);

    man.registerPlayer({p1,p2,p3});
    man.printMap();


    std::string line;
    bool running = true;
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
        man.tick();
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
