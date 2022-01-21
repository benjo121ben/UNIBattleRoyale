//
// Created by benja on 21/01/2022.
//

#include "CheckBoardValueNode.h"
template<typename T>
CheckBoardValueNode<T>::CheckBoardValueNode(std::string key, CheckBoardValueNode::comparisonType compType, T comparisonValue) :
        key{std::move(key)}, compType{compType}, comparisonValue{comparisonValue}{}

template<typename T>
AbstractBTNode *CheckBoardValueNode<T>::getCopy() const {
    return new CheckBoardValueNode(key,compType, comparisonValue);
}

template<typename T>
void CheckBoardValueNode<T>::reset() {
    AbstractBTNode::reset();
}

template<typename T>
BTNodestatus CheckBoardValueNode<T>::traverse(BTBlackboard *board) {
    AbstractBTNode::traverse(board);
    if(!board->isSet(key)) return failure;
    T value = board->template getValue<T>(key);
    switch (compType) {
        case equal: return (comparisonValue == value) ? success : failure;
        case notEqual: return (comparisonValue != value) ? success : failure;
        case greater_than_compValue: return (comparisonValue < value) ? success : failure;
        case smaller_than_compValue: return (comparisonValue > value) ? success : failure;
        case greater_equal_than_compValue: return (comparisonValue <= value) ? success : failure;
        case smaller_equal_than_compValue: return (comparisonValue >= value) ? success : failure;
    }
    throw generic_behaviour_tree_exception("CheckBoardValueNode::traverse", "Tried to execute an impossible compType");
}

