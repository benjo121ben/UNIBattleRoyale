//
// Created by benja on 20/01/2022.
//

#include "BTActionNode_CoutDebug.h"

#include <utility>
#include <iostream>


BTActionNode_CoutDebug::BTActionNode_CoutDebug(std::string outputString, BTNodestatus outputState) : outputstring{std::move(outputString)}{
    this->outputState = outputState;
}

BTNode_Abstract *BTActionNode_CoutDebug::getCopy() const {
    return new BTActionNode_CoutDebug(outputstring, outputState);
}

BTNodestatus BTActionNode_CoutDebug::traverse(BTBlackboard *board) {
    BTNode_Abstract::traverse(board);
    if(state == running){
        std::cout << "Debug/" << state_toString() << ": " << outputstring << " was run again" <<std::endl;
    }
    else{
        std::cout << "Debug/" << state_toString() << ": " << outputstring << " was run first time" <<std::endl;
    }
    state = outputState;
    return state;
}

void BTActionNode_CoutDebug::reset() {
    BTNode_Abstract::reset();
    if(state == ready)return;
    std::cout << "Debug/" << state_toString() << ": " << outputstring << " was reset" <<std::endl;
    state = ready;
}

std::string BTActionNode_CoutDebug::state_toString() {
    switch (outputState) {
        case failure: return "failure";
        case success: return "success";
        case running: return "running";
        default: break;
    }
    throw generic_behaviour_tree_exception("BTActionNode_CoutDebug::state_toString()", "Somehow tried to interpret an impossible/ready BTNodestatus " + std::to_string(outputState));
}


