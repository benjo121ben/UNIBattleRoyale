//
// Created by benja on 20/01/2022.
//

#include "Sequence.h"

BTNodestatus Sequence::traverse(BTBlackboard *board) {
    AbstractBTNode::traverse(board);
    int startIndex {(runningChildIndex != -1) ? runningChildIndex : 0};
    for(int index{startIndex}; index < children.size(); ++index){
        BTNodestatus retState = children.at(index)->traverse(board);
        switch (retState) {
            case failure:{
                runningChildIndex = -1;
                reset();
                return failure;
            }
            case running:{
                runningChildIndex = index;
                return running;
            }
            case success:{
                runningChildIndex = -1;
            }
        }
    }
    reset();
    return success;
}

AbstractBTNode *Sequence::getCopy() const {
    auto s = new Sequence();
    for(auto child : children){
        s->push_back_child(child->getCopy());
    }
    return s;
}

void Sequence::reset() {
    CompositeNode::reset();
    runningChildIndex = -1;
}
