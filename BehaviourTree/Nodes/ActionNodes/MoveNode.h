//
// Created by benja on 19/01/2022.
//

#ifndef GAME_MOVENODE_H
#define GAME_MOVENODE_H

#include "../AbstractBTNode.h"

class MoveNode : public AbstractBTNode{
public:
    BTNodestatus traverse(BTBlackboard* board) override;
    AbstractBTNode* getCopy() const override;
};
#endif //GAME_MOVENODE_H
