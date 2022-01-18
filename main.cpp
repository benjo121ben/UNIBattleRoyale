#include <iostream>
#include "PlayerInfo/Player.h"
#include "MapInfo/GameMap.h"
#include "Managers/GameManager.h"
#include "Pathfinder/Pathfinder.h"
#include "Random.h"



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
    try {
        man.tick();
    }catch (std::exception& e){
        std::cout << e.what();
    }

    man.printMap();
    man.tick();
    man.printMap();
    man.tick();
    man.printMap();

    return 0;
}
