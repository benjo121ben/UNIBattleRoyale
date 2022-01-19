//
// Created by benja on 19/01/2022.
//

#ifndef GAME_BEHAVIOURTREE_H
#define GAME_BEHAVIOURTREE_H
#include "BTNodeInterface.h"
#include "BTBlackboard.h"
#include "../PlayerInfo/TickInfo.h"
class BehaviourTree{
    BTNodeInterface* rootNode = nullptr;
    BTBlackboard blackboard;
public:
    explicit BehaviourTree(const BTBlackboard& blackboard);
    explicit BehaviourTree(const GameMap& m,const std::vector<Player>& pList);
    TickInfo traverse();
    BehaviourTree* getCopy() const;
};
#endif //GAME_BEHAVIOURTREE_H
