//
// Created by benja on 19/01/2022.
//

#ifndef GAME_BTNODE_H
#define GAME_BTNODE_H
#include "../Blackboard/BTBlackboard.h"
enum BTNodestatus{
    failure, success, running,ready
};

class BTNode_Abstract{
protected:
    BTNodestatus state = ready;
public:
    virtual void reset();
    virtual BTNodestatus traverse(BTBlackboard* board);
    virtual BTNode_Abstract* getCopy() const = 0;
    virtual ~BTNode_Abstract() = default;
};
#endif //GAME_BTNODE_H
