//
// Created by benja on 19/01/2022.
//

#ifndef GAME_BEHAVIOURTREE_H
#define GAME_BEHAVIOURTREE_H
#include "Nodes/AbstractBTNode.h"
#include "Blackboard/BTBlackboard.h"
#include "../PlayerInfo/TickInfo.h"
#include "BehaviourTreeExceptions.h"
class BehaviourTree{
    AbstractBTNode* rootNode = nullptr;
    BTBlackboard blackboard;
public:
    explicit BehaviourTree(const BTBlackboard& blackboard);
    explicit BehaviourTree(const GameData& data);
    TickInfo traverse();

    void setPlayerId(int id);
    BehaviourTree* getCopy() const;
    AbstractBTNode* convertToSubtree() const;
};

#endif //GAME_BEHAVIOURTREE_H
