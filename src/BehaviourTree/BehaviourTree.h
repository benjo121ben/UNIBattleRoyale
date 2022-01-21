//
// Created by benja on 19/01/2022.
//

#ifndef GAME_BEHAVIOURTREE_H
#define GAME_BEHAVIOURTREE_H
#include "Blackboard/BTBlackboard.h"
class BTNode_Abstract;

class BehaviourTree{
    BTNode_Abstract* rootNode = nullptr;
    BTBlackboard blackboard;
public:
    BehaviourTree(const BehaviourTree& other);
    explicit BehaviourTree(const BTBlackboard& blackboard);
    explicit BehaviourTree(const GameData& data);
    TickInfo traverse();

    void setPlayerInfo(int id);
    void setRootNode(BTNode_Abstract * node);
    BehaviourTree* getCopy() const;
    BTNode_Abstract* convertToSubtree() const;
};

#endif //GAME_BEHAVIOURTREE_H
