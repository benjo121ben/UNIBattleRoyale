//
// Created by benja on 19/01/2022.
//
#include "MoveNode.h"
#include "../../../MapInfo/cardinal_directions.h"
#include "../../../Random.h"

BTstatus MoveNode::traverse(BTBlackboard* board) {
    auto dir = static_cast<cardinal_directions>(Random::get_random_Int(4));
    board->tickInfo = {TickInfo::move, std::make_any<cardinal_directions>(dir)};
    return success;
}

BTNodeInterface* MoveNode::getCopy() const{
    return new MoveNode();
}

