//
// Created by benja on 19/01/2022.
//

#include "BTTemplates.h"
#include "BehaviourTree.h"
#include "allNodes.h"

BehaviourTree BTTemplates::move_randomly(const GameData& data){
    BehaviourTree bt{data};
    auto s = new CompNode_Sequence();
    s->push_back_child(new BTActionNode_SetRandomMoveDir());
    s->push_back_child(new BTActionNode_MoveTowardsDir());
    bt.setRootNode(s);
    return bt;
}

BehaviourTree BTTemplates::move_towards_nearest_enemy(const GameData& data){
    BehaviourTree bt{data};
    auto s = new CompNode_Sequence();
    s->push_back_child(new BTActionNode_SetEnemyDir());
    s->push_back_child(new BTActionNode_MoveTowardsDir());
    bt.setRootNode(s);
    return bt;
}

BehaviourTree BTTemplates::test_shit(const GameData& data) {
    return BehaviourTree (data);
}
