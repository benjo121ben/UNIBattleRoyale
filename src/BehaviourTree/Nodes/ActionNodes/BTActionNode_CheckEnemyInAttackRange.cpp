//
// Created by benja on 21/01/2022.
//

#include "BTActionNode_CheckEnemyInAttackRange.h"

BTNode_Abstract *BTActionNode_CheckEnemyInAttackRange::getCopy() const {
    return new BTActionNode_CheckEnemyInAttackRange();
}

BTNodestatus BTActionNode_CheckEnemyInAttackRange::traverse(BTBlackboard *board) {
    BTNode_Abstract::traverse(board);
    auto myPlayerNr = board->getValue<int>(BlackboardKeys::PLAYERID());
    auto myCoords = board->getCurrentPlayerPosition();
    for(int index{0}; index < board->getPlayerPositionList().size(); ++index){
        if(index != myPlayerNr && myCoords == board->getAnyPlayerCoordinate(index)){
            board->setValue(BlackboardKeys::ATTACKTARGETID(), index);
            return success;
        }
    }
    return failure;
}
