//
// Created by benja on 20/01/2022.
//

#ifndef GAME_COUTDEBUGNODE_H
#define GAME_COUTDEBUGNODE_H

#include <string>
#include "../AbstractBTNode.h"

class CoutDebugNode : public AbstractBTNode{
    BTNodestatus outputState;
    std::string outputstring;
    std::string state_toString();
public:
    CoutDebugNode(std::string outputString, BTNodestatus outputState);
    AbstractBTNode *getCopy() const override;
    BTNodestatus traverse(BTBlackboard *board) override;

    void reset() override;


};
#endif //GAME_COUTDEBUGNODE_H
