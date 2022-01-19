//
// Created by benja on 19/01/2022.
//

#ifndef GAME_BTTEMPLATES_H
#define GAME_BTTEMPLATES_H
#include<vector>
class BehaviourTree;
class GameMap;
class Player;
class BTTemplates{
    static BehaviourTree move_randomly(const GameMap& m,const std::vector<Player>& pList);
    static BehaviourTree move_towards_nearest_enemy(const GameMap& m,const std::vector<Player>& pList);
};
#endif //GAME_BTTEMPLATES_H
