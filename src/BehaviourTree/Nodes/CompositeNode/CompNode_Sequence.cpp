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
                state = failure;
                return failure;
            }
            case running:{
                runningChildIndex = index;
                state = running;
                return running;
            }
            case success:{
                runningChildIndex = -1;
                break;
            }
            case ready: throw generic_behaviour_tree_exception("CompNode_Sequence::traverse", "an invalid ready sate was returned.");
        }
    }
    state = success;
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
    if(state == ready)return;
    runningChildIndex = -1;
}
