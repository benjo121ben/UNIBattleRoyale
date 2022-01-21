//
// Created by benja on 21/01/2022.
//

#ifndef GAME_BTACTIONNODE_ATTACK_H
#define GAME_BTACTIONNODE_ATTACK_H
#include "../BTNode_Abstract.h"

class BTActionNode_Attack : public BTNode_Abstract{
public:

    BTNodestatus traverse(BTBlackboard *board) override;

    BTNode_Abstract *getCopy() const override;
};


#endif //GAME_BTACTIONNODE_ATTACK_H
