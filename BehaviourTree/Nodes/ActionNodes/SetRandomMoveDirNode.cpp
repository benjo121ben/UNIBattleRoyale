//
// Created by benja on 20/01/2022.
//

#include "SetRandomMoveDirNode.h"
#include "../../Blackboard/BlackboardKeys.h"
#include "../../../Random.h"
#include "../../../MapInfo/cardinal_directions.h"

BTNodestatus SetRandomMoveDirNode::traverse(BTBlackboard *board) {
    auto dir = static_cast<cardinal_directions>(Random::get_random_Int(4));
    board->setValue(BlackboardKeys::PLAYERMOVEDIR(), dir);
    return success;
}

AbstractBTNode *SetRandomMoveDirNode::getCopy() const {
    return new SetRandomMoveDirNode();
}



