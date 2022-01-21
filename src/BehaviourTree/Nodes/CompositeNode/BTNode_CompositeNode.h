//
// Created by benja on 20/01/2022.
//

#ifndef GAME_BTNODE_COMPOSITENODE_H
#define GAME_BTNODE_COMPOSITENODE_H
#include "../BTNode_Abstract.h"
#include<deque>

class BTNode_CompositeNode : public BTNode_Abstract{
protected:
    int runningChildIndex = -1;
    std::deque<BTNode_Abstract *> children;

public:
    void push_back_child(BTNode_Abstract * child);
    void push_front_child(BTNode_Abstract * child);
    void reset() override;
};


#endif //GAME_BTNODE_COMPOSITENODE_H
