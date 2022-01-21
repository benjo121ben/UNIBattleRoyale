//
// Created by benja on 19/01/2022.
//

#ifndef GAME_SET_RANDOM_MOVEDIR_NODE_H
#define GAME_SET_RANDOM_MOVEDIR_NODE_H

#include "../AbstractBTNode.h"

class SetRandomMoveDirNode : public AbstractBTNode{
public:

    BTNodestatus traverse(BTBlackboard *board) override;
    [[nodiscard]] AbstractBTNode *getCopy() const override;
};


#endif //GAME_SET_RANDOM_MOVEDIR_NODE_H
