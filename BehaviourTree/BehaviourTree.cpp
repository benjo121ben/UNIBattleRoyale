//
// Created by benja on 19/01/2022.
//

#include "BehaviourTree.h"

#include <utility>
#include "../MapInfo/GameMap.h"
#include "../PlayerInfo/Player.h"
#include "allNodes.h"
#include "Blackboard/BlackboardKeys.h"

BehaviourTree::BehaviourTree(const BTBlackboard& blackB) : blackboard{std::move(blackB.getCopy())}{
    rootNode = nullptr;
}

BehaviourTree::BehaviourTree(const GameData& data) : blackboard{data}{
    rootNode = nullptr;
}



TickInfo BehaviourTree::traverse(){
    if(rootNode == nullptr){
        throw generic_behaviour_tree_exception("Tree rootNode is nullptr");
    }
    rootNode->traverse(&blackboard);
    return blackboard.tickInfo;
}

void BehaviourTree::setPlayerId(int id){
    blackboard.setValue(BlackboardKeys::PLAYERID(), id);
}
BehaviourTree* BehaviourTree::getCopy() const{
    BehaviourTree* ret { new BehaviourTree(blackboard)};
    ret->setRootNode(rootNode->getCopy());
    return ret;
}

AbstractBTNode* BehaviourTree::convertToSubtree()const {
    return (rootNode) ? rootNode->getCopy() : nullptr;
}

void BehaviourTree::setRootNode(AbstractBTNode * node) {
    rootNode = node;
}
