//
// Created by benja on 21/01/2022.
//

#ifndef GAME_BTACTIONNODE_CHECKBOARDVALUE_H
#define GAME_BTACTIONNODE_CHECKBOARDVALUE_H
#include "../BTNode_Abstract.h"

template<typename T>
class BTActionNode_CheckBoardValue : public BTNode_Abstract{
    enum comparisonType{
        equal, notEqual, greater_than_compValue, smaller_than_compValue, greater_equal_than_compValue, smaller_equal_than_compValue
    };

    std::string key;
    comparisonType compType;
    T comparisonValue;
public:
    BTActionNode_CheckBoardValue(std::string key, comparisonType compType, T comparisonValue);
    BTNodestatus traverse(BTBlackboard *board) override;
    BTNode_Abstract *getCopy() const override;
};


#endif //GAME_BTACTIONNODE_CHECKBOARDVALUE_H
