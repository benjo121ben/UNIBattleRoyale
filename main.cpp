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
    /*Pathfinder b(&man.map);
    Coordinate start(3,3);
    Coordinate end(4,6);
    b.outputPath(start,end);*/
    return 0;
}
