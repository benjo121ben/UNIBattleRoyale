//
// Created by benja on 20/01/2022.
//

#ifndef GAME_BTACTIONNODE_COUTDEBUG_H
#define GAME_BTACTIONNODE_COUTDEBUG_H

#include <string>
#include "../BTNode_Abstract.h"

class BTActionNode_CoutDebug : public BTNode_Abstract{
    BTNodestatus outputState;
    std::string outputstring;
    std::string state_toString();
public:
    BTActionNode_CoutDebug(std::string outputString, BTNodestatus outputState);
    BTNode_Abstract *getCopy() const override;
    BTNodestatus traverse(BTBlackboard *board) override;

    void reset() override;


};
#endif //GAME_BTACTIONNODE_COUTDEBUG_H
