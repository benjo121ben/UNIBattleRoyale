//
// Created by benja on 19/01/2022.
//

#include "BTTemplates.h"
#include "BehaviourTree.h"
#include "allNodes.h"

BehaviourTree* BTTemplates::move_randomly(const GameData& data){
    auto bt = new BehaviourTree(data);
    auto s = new CompNode_Sequence();
    s->push_back_child(new BTActionNode_SetRandomMoveDir());
    s->push_back_child(new BTActionNode_MoveTowardsDir());
    bt->setRootNode(s);
    return bt;
}

BehaviourTree* BTTemplates::move_towards_nearest_enemy(const GameData& data){
    auto bt = new BehaviourTree(data);
    auto s = new CompNode_Sequence();
    s->push_back_child(new BTActionNode_SetEnemyDir());
    s->push_back_child(new BTActionNode_MoveTowardsDir());
    bt->setRootNode(s);
    return bt;
}

BehaviourTree* BTTemplates::attack_if_enemy_nearby(const GameData& data) {
    auto bt = new BehaviourTree(data);
    auto s = new CompNode_Sequence();
    s->push_back_child(new BTActionNode_CheckEnemyInAttackRange());
    s->push_back_child(new BTActionNode_Attack());
    bt->setRootNode(s);
    return bt;
}

BehaviourTree* BTTemplates::testTree_Move_and_Attack(const GameData &data) {
    auto bt = new BehaviourTree(data);
    auto s = new CompNode_Selector();
    bt->setRootNode(s);
    s->push_back_child(BehaviourTree::move_BT_to_Subtree(attack_if_enemy_nearby(data)));
    s->push_back_child(BehaviourTree::move_BT_to_Subtree(move_towards_nearest_enemy(data)));
    return bt;
}
