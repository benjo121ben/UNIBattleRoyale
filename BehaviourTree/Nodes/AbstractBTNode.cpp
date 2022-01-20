//
// Created by benja on 20/01/2022.
//
#include "AbstractBTNode.h"
void AbstractBTNode::reset() {
    state = ready;
}
BTNodestatus AbstractBTNode::traverse(BTBlackboard* board){
    if(state != running && state != ready) reset();
    return state;
}