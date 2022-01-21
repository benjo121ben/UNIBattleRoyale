//
// Created by benja on 20/01/2022.
//

#include "BTNode_CompositeNode.h"

void BTNode_CompositeNode::push_back_child(BTNode_Abstract * child){
    children.push_back(child);
}

void BTNode_CompositeNode::push_front_child(BTNode_Abstract * child){
    children.push_front(child);
}

void BTNode_CompositeNode::reset() {
    BTNode_Abstract::reset();
    for(auto& child : children){
        child->reset();
    }
}


