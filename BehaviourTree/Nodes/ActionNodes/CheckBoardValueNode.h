//
// Created by benja on 21/01/2022.
//

#ifndef GAME_CHECKBOARDVALUENODE_H
#define GAME_CHECKBOARDVALUENODE_H
#include "../AbstractBTNode.h"

template<typename T>
class CheckBoardValueNode : public AbstractBTNode{
    enum comparisonType{
        equal, notEqual, greater_than_compValue, smaller_than_compValue, greater_equal_than_compValue, smaller_equal_than_compValue
    };

    std::string key;
    comparisonType compType;
    T comparisonValue;
public:
    CheckBoardValueNode(std::string key, comparisonType compType, T comparisonValue);
    void reset() override;
    BTNodestatus traverse(BTBlackboard *board) override;
    AbstractBTNode *getCopy() const override;
};


#endif //GAME_CHECKBOARDVALUENODE_H
