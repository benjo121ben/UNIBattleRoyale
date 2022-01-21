//
// Created by benja on 19/01/2022.
//

#ifndef GAME_BTTEMPLATES_H
#define GAME_BTTEMPLATES_H
#include<vector>
#include "../Managers/GameData.h"

class BehaviourTree;
class GameMap;
class Player;
class BTTemplates{
public:
    static BehaviourTree move_randomly(const GameData& data);
    static BehaviourTree move_towards_nearest_enemy(const GameData& data);
    static BehaviourTree test_shit(const GameData& data);
};
#endif //GAME_BTTEMPLATES_H
