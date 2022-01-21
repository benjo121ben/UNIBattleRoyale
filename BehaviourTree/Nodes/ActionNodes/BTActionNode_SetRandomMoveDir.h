//
// Created by benja on 19/01/2022.
//

#ifndef GAME_SET_RANDOM_MOVEDIR_NODE_H
#define GAME_SET_RANDOM_MOVEDIR_NODE_H

#include "../BTNode_Abstract.h"

class BTActionNode_SetRandomMoveDir : public BTNode_Abstract{
public:

    BTNodestatus traverse(BTBlackboard *board) override;
    [[nodiscard]] BTNode_Abstract *getCopy() const override;
};


#endif //GAME_SET_RANDOM_MOVEDIR_NODE_H
