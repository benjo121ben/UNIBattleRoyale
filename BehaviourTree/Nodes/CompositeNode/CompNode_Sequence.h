//
// Created by benja on 20/01/2022.
//

#ifndef GAME_COMPNODE_SEQUENCE_H
#define GAME_COMPNODE_SEQUENCE_H
#include"BTNode_CompositeNode.h"

class CompNode_Sequence : public BTNode_CompositeNode{
public:
    BTNodestatus traverse(BTBlackboard *board) override;
    BTNode_Abstract *getCopy() const override;
    void reset() override;
};


#endif //GAME_COMPNODE_SEQUENCE_H
