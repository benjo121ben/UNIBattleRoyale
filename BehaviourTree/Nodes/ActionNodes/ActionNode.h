//
// Created by benja on 19/01/2022.
//

#ifndef GAME_ACTIONNODE_H
#define GAME_ACTIONNODE_H
#include "../BTNodeInterface.h"
class ActionNode : public BTNodeInterface{
    bool started = false;
    BTstatus state;
    virtual BTstatus traverse(BTBlackboard* board) = 0;
    virtual void reset() override;
};
#endif //GAME_ACTIONNODE_H
