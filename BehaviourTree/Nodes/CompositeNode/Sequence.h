//
// Created by benja on 20/01/2022.
//

#ifndef GAME_SEQUENCE_H
#define GAME_SEQUENCE_H
#include"CompositeNode.h"

class Sequence : public CompositeNode{
public:
    BTNodestatus traverse(BTBlackboard *board) override;
    AbstractBTNode *getCopy() const override;
    void reset() override;
};


#endif //GAME_SEQUENCE_H
