//
// Created by benja on 19/01/2022.
//

#ifndef GAME_MOVENODE_H
#define GAME_MOVENODE_H
#include "ActionNode.h"
class MoveNode : public ActionNode{
    virtual BTstatus traverse(BTBlackboard* board) override;
    virtual BTNodeInterface* getCopy() const override;
};
#endif //GAME_MOVENODE_H
