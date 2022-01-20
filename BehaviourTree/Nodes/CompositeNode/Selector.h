//
// Created by benja on 20/01/2022.
//

#ifndef GAME_SELECTOR_H
#define GAME_SELECTOR_H
#include "CompositeNode.h"

class Selector : public CompositeNode{
public:
    BTNodestatus traverse(BTBlackboard *board) override;
    AbstractBTNode *getCopy() const override;
    void reset() override;

};


#endif //GAME_SELECTOR_H
