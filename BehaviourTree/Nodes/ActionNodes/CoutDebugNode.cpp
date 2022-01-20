//
// Created by benja on 20/01/2022.
//

#include "CoutDebugNode.h"

#include <utility>
#include <iostream>


CoutDebugNode::CoutDebugNode(std::string outputString, BTNodestatus outputState) : outputstring{std::move(outputString)}{
    this->outputState = outputState;
}

AbstractBTNode *CoutDebugNode::getCopy() const {
    return new CoutDebugNode(outputstring, state);
}

BTNodestatus CoutDebugNode::traverse(BTBlackboard *board) {
    AbstractBTNode::traverse(board);
    if(state == running){
        std::cout << "Debug/" << state_toString() << ": " << outputstring << "was run again" <<std::endl;
    }
    else{
        std::cout << "Debug/" << state_toString() << ": " << outputstring << "was run first time" <<std::endl;
    }
    state = outputState;
    return state;
}

void CoutDebugNode::reset() {
    std::cout << "Debug/" << state_toString() << ": " << outputstring << "was reset" <<std::endl;
    state = ready;
}

std::string CoutDebugNode::state_toString() {
    switch (outputState) {
        case failure: return "failure";
        case success: return "success";
        case running: return "running";
        default: break;
    }
    throw generic_behaviour_tree_exception("debug node somehow tried to interpret an impossible/ready BTNodestatus" + std::to_string(state));
}


