//
// Created by benja on 19/01/2022.
//

#ifndef GAME_BTACTIONNODE_MOVETOWARDSDIR_H
#define GAME_BTACTIONNODE_MOVETOWARDSDIR_H

#include "../BTNode_Abstract.h"

class BTActionNode_MoveTowardsDir : public BTNode_Abstract{
public:
    BTNodestatus traverse(BTBlackboard* board) override;
    BTNode_Abstract* getCopy() const override;
};
#endif //GAME_BTACTIONNODE_MOVETOWARDSDIR_H
