//
// Created by benja on 19/01/2022.
//

#include "BTTemplates.h"
#include "BehaviourTree.h"
#include "allNodes.h"

BehaviourTree BTTemplates::move_randomly(const GameData& data){
    return BehaviourTree(data);
}

BehaviourTree BTTemplates::move_towards_nearest_enemy(const GameData& data){
    return BehaviourTree(data);
}

BehaviourTree BTTemplates::test_shit(const GameData& data) {
    return BehaviourTree (data);
}
