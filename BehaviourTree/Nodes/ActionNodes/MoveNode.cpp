//
// Created by benja on 19/01/2022.
//
#include "MoveNode.h"
#include "../../../MapInfo/cardinal_directions.h"
#include "../../../Random.h"
#include "../../Blackboard/BlackboardKeys.h"

BTNodestatus MoveNode::traverse(BTBlackboard* board) {
    AbstractBTNode::traverse(board);
    if(board->isSet(BlackboardKeys::PLAYERMOVEDIR())) {
        auto dir = board->getValue<cardinal_directions>(BlackboardKeys::PLAYERMOVEDIR());
        board->tickInfo = {TickInfo::move, std::make_any<cardinal_directions>(dir)};
        return success;
    }
    else{
        return failure;
    }
}

AbstractBTNode* MoveNode::getCopy() const{
    return new MoveNode();
}


