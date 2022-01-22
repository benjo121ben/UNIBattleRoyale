//
// Created by benja on 20/01/2022.
//

#include "BTActionNode_SetRandomMoveDir.h"
#include "../../Blackboard/BlackboardKeys.h"
#include "../../../Random.h"
#include "../../../MapInfo/cardinal_directions.h"

BTNodestatus BTActionNode_SetRandomMoveDir::traverse(BTBlackboard *board) {
    Random rand;
    auto dir = static_cast<cardinal_directions>(rand.get_random_Int(4));
    board->setValue(BlackboardKeys::PLAYERMOVEDIR(), dir);
    return success;
}

BTNode_Abstract *BTActionNode_SetRandomMoveDir::getCopy() const {
    return new BTActionNode_SetRandomMoveDir();
}



