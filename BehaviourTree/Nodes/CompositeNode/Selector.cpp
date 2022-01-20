//
// Created by benja on 20/01/2022.
//

#include "Selector.h"

BTNodestatus Selector::traverse(BTBlackboard *board) {
    AbstractBTNode::traverse(board);
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

AbstractBTNode *Selector::getCopy() const {
    auto s = new Selector();
    for(auto child : children){
        s->push_back_child(child->getCopy());
    }
    return s;
}

void Selector::reset() {
    CompositeNode::reset();
    runningChildIndex = -1;
}
