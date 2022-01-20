//
// Created by benja on 20/01/2022.
//

#include "CompositeNode.h"

void CompositeNode::push_back_child(AbstractBTNode * child){
    children.push_back(child);
}

void CompositeNode::push_front_child(AbstractBTNode * child){
    children.push_front(child);
}

void CompositeNode::reset() {
    AbstractBTNode::reset();
    for(auto& child : children){
        child->reset();
    }
}


