#include <iostream>
#include "PlayerInfo/Player.h"
#include "MapInfo/GameMap.h"
#include "Managers/GameManager.h"
#include "Pathfinder/Pathfinder.h"
#include "Random.h"


bool handleInput(GameManager &man, const std::string &line);

int main() {
    Player p1("Benji", "Sword", Pronouns::masculine());
    Player p2("Lena", "Axe", Pronouns::feminine());
    Player p3("Froggy", "Tongue", Pronouns::neutral());
    std::cout << p1.fight(p2)<< std::endl;
    GameManager man;


    //Coordinate start(7,1);
    //Coordinate end(9,3);
    //Pathfinder::outputPath(man.getMap(),start,end);

    man.registerPlayer({p1,p2,p3});
    man.printMap();


    std::string line;
    bool running = true;
    while (running && std::getline(std::cin, line)){
        std::cout << "-------------------------------------------\n\n";
        running = handleInput(man, line);

        std::cout << "\n\n";

    }

    return 0;
}

bool handleInput(GameManager &man, const std::string &line) {
    if(line == "q") return false;
    if(line == "t"){
        man.tick();
    }
    else if(line == "m"){
        man.printMap();
    }
    else if(line == "e"){
        man.printEvents();
    }

    return true;

}
