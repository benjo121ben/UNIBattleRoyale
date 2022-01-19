//
// Created by benja on 19/01/2022.
//

#include "BehaviourTree.h"

#include <utility>
#include "../MapInfo/GameMap.h"
#include "../PlayerInfo/Player.h"
#include "allNodes.h"
BehaviourTree::BehaviourTree(const BTBlackboard& blackB) : blackboard{std::move(blackB.getCopy())}{
    rootNode = new MoveNode();
}

BehaviourTree::BehaviourTree(const GameMap& m,const std::vector<Player>& pList) : blackboard{m,pList}{
    rootNode = new MoveNode();
}



TickInfo BehaviourTree::traverse(){
    rootNode->traverse(&blackboard);
    return blackboard.tickInfo;
}

BehaviourTree* BehaviourTree::getCopy() const{
    return new BehaviourTree(blackboard);
}