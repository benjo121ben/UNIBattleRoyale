//
// Created by benja on 20/01/2022.
//

#include "CompNode_Selector.h"

BTNodestatus CompNode_Selector::traverse(BTBlackboard *board) {
    BTNode_Abstract::traverse(board);
    for(int index{0}; index < children.size(); ++index){
        BTNodestatus retState = children.at(index)->traverse(board);
        if(retState == success){
            if(runningChildIndex != -1){
                children.at(runningChildIndex)->reset();
                runningChildIndex = -1;
            }
            reset();
            state = success;
            return state;
        }
        else if(retState == running){
            if(runningChildIndex != -1 && index != runningChildIndex){
                children.at(runningChildIndex)->reset();
                runningChildIndex = index;
            }
            state = running;
            return running;
        }
    }
    state = failure;
    return failure;
}

BTNode_Abstract *CompNode_Selector::getCopy() const {
    auto s = new CompNode_Selector();
    for(auto child : children){
        s->push_back_child(child->getCopy());
    }
    return s;
}

void CompNode_Selector::reset() {
    BTNode_CompositeNode::reset();
    runningChildIndex = -1;
}
