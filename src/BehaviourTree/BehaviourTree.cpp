//
// Created by benja on 19/01/2022.
//

#include "BehaviourTree.h"
#include "BehaviourTreeExceptions.h"

#include <utility>
#include "allNodes.h"
#include "../MapInfo/GameMap.h"
#include "../PlayerInfo/Player.h"
#include "../Managers/GameData.h"
#include "Blackboard/BlackboardKeys.h"
#include "Blackboard/BTBlackboard.h"

BTNode_Abstract* BehaviourTree::move_BT_to_Subtree(BehaviourTree* bt){
    auto ret =  (bt->rootNode) ? bt->rootNode->getCopy() : nullptr;
    delete bt;
    return ret;
}


BehaviourTree::BehaviourTree(const BehaviourTree &other) : blackboard{other.blackboard}{

}

BehaviourTree::BehaviourTree(const BTBlackboard& blackB) : blackboard{blackB}{std::cout << "consCalled\n";}

BehaviourTree::BehaviourTree(const GameData& data) : blackboard{data}{std::cout << "consCalled\n";}

BehaviourTree::~BehaviourTree(){
    delete this->rootNode;
    std::cout << "desCalled\n";
}

TickInfo BehaviourTree::traverse(){
    if(rootNode == nullptr){
        throw called_nullptr_child_BT_exception("BehaviourTree::traverse");
    }
    rootNode->traverse(&blackboard);
    return blackboard.tickInfo;
}

void BehaviourTree::setPlayerInfo(int id){
    blackboard.setValue(BlackboardKeys::PLAYERID(), id);
}
BehaviourTree* BehaviourTree::getCopy() const{
    BehaviourTree* ret { new BehaviourTree(blackboard)};
    ret->setRootNode(rootNode->getCopy());
    return ret;
}

void BehaviourTree::setRootNode(BTNode_Abstract * node) {
    rootNode = node;
}


