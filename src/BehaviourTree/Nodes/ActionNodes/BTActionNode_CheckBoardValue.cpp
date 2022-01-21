//
// Created by benja on 21/01/2022.
//

#include "BTActionNode_CheckBoardValue.h"
template<typename T>
BTActionNode_CheckBoardValue<T>::BTActionNode_CheckBoardValue(std::string key, BTActionNode_CheckBoardValue::comparisonType compType, T comparisonValue) :
        key{std::move(key)}, compType{compType}, comparisonValue{comparisonValue}{}

template<typename T>
BTNode_Abstract *BTActionNode_CheckBoardValue<T>::getCopy() const {
    return new BTActionNode_CheckBoardValue(key, compType, comparisonValue);
}

template<typename T>
void BTActionNode_CheckBoardValue<T>::reset() {
    BTNode_Abstract::reset();
}

template<typename T>
BTNodestatus BTActionNode_CheckBoardValue<T>::traverse(BTBlackboard *board) {
    BTNode_Abstract::traverse(board);
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
    throw generic_behaviour_tree_exception("BTActionNode_CheckBoardValue::traverse", "Tried to execute an impossible compType");
}

