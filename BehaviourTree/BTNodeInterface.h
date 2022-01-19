//
// Created by benja on 19/01/2022.
//

#ifndef GAME_BTNODE_H
#define GAME_BTNODE_H
#include "BTBlackboard.h"
enum BTstatus{
    failure, success, running
};

class BTNodeInterface{
public:
    virtual BTstatus traverse(BTBlackboard* board) = 0;
    virtual void reset() = 0;
    virtual BTNodeInterface* getCopy() const = 0;
};
#endif //GAME_BTNODE_H
