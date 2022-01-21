//
// Created by benja on 19/01/2022.
//
#include "BTActionNode_MoveTowardsDir.h"
#include "../../../MapInfo/cardinal_directions.h"
#include "../../../Random.h"
#include "../../Blackboard/BlackboardKeys.h"

BTNodestatus BTActionNode_MoveTowardsDir::traverse(BTBlackboard* board) {
    BTNode_Abstract::traverse(board);
    if(board->isSet(BlackboardKeys::PLAYERMOVEDIR())) {
        auto dir = board->getValue<cardinal_directions>(BlackboardKeys::PLAYERMOVEDIR());
        board->tickInfo = {TickInfo::move, std::make_any<cardinal_directions>(dir)};
        return success;
    }
    else{
        return failure;
    }
}

BTNode_Abstract* BTActionNode_MoveTowardsDir::getCopy() const{
    return new BTActionNode_MoveTowardsDir();
}


