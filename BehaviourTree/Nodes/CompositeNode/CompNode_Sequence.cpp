//
// Created by benja on 20/01/2022.
//

#include "CompNode_Sequence.h"

BTNodestatus CompNode_Sequence::traverse(BTBlackboard *board) {
    BTNode_Abstract::traverse(board);
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

BTNode_Abstract *CompNode_Sequence::getCopy() const {
    auto s = new CompNode_Sequence();
    for(auto child : children){
        s->push_back_child(child->getCopy());
    }
    return s;
}

void CompNode_Sequence::reset() {
    BTNode_CompositeNode::reset();
    runningChildIndex = -1;
}
