//
// Created by benja on 20/01/2022.
//

#ifndef GAME_COMPOSITENODE_H
#define GAME_COMPOSITENODE_H
#include "../AbstractBTNode.h"
#include<deque>

class CompositeNode : public AbstractBTNode{
protected:
    int runningChildIndex = -1;
    std::deque<AbstractBTNode *> children;

public:
    void push_back_child(AbstractBTNode * child);
    void push_front_child(AbstractBTNode * child);
    void reset() override;
};


#endif //GAME_COMPOSITENODE_H
