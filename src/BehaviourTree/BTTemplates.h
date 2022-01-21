//
// Created by benja on 19/01/2022.
//

#ifndef GAME_BTTEMPLATES_H
#define GAME_BTTEMPLATES_H
#include<vector>
#include "../Managers/GameData.h"

class BehaviourTree;

class BTTemplates{
public:
    static BehaviourTree move_randomly(const GameData& data);
    static BehaviourTree move_towards_nearest_enemy(const GameData& data);
    static BehaviourTree attack_if_enemy_nearby(const GameData& data);
    static BehaviourTree testTree_Move_and_Attack(const GameData& data);
};
#endif //GAME_BTTEMPLATES_H
