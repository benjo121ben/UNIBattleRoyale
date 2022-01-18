#include <iostream>
#include "PlayerInfo/Player.h"
#include "MapInfo/GameMap.h"
#include "GameManager.h"
#include "Pathfinder/Pathfinder.h"



int main() {
    Player p1("Benji", "Sword", Pronouns::masculine());
    Player p2("Lena", "Axe", Pronouns::feminine());
    std::cout << p1.fight(p2)<< std::endl;
    GameManager man;
    std::cout << man.printMap();

    Coordinate start(7,1);
    Coordinate end(9,3);
    Pathfinder::outputPath(man.getMap(),start,end);
    return 0;
}
