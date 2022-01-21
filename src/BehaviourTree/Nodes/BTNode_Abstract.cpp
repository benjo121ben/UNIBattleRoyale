//
// Created by benja on 20/01/2022.
//
#include "BTNode_Abstract.h"
void BTNode_Abstract::reset() {
    if(state == ready) return;
    state = ready;
}
BTNodestatus BTNode_Abstract::traverse(BTBlackboard* board){
    if(state != running && state != ready) reset();
    return state;
}