//
// Created by benja on 21/01/2022.
//

#include "BTActionNode_Attack.h"



BTNodestatus BTActionNode_Attack::traverse(BTBlackboard *board) {
    BTNode_Abstract::traverse(board);
    auto targetNR = board->getValue<int>(BlackboardKeys::ATTACKTARGETID());
    if(board->alivePlayerList().count(targetNR)) {
        board->tickInfo = TickInfo(TickInfo::attack, targetNR);
        return success;
    }
    else{
        return failure;
    }
}

BTNode_Abstract *BTActionNode_Attack::getCopy() const {
    return new BTActionNode_Attack();
}
