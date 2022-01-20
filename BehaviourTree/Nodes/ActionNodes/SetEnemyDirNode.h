//
// Created by benja on 19/01/2022.
//

#ifndef GAME_SETENEMYDIRNODE_H
#define GAME_SETENEMYDIRNODE_H

#include "../AbstractBTNode.h"

class SetEnemyDirNode : public AbstractBTNode{
public:

    BTNodestatus traverse(BTBlackboard *board) override;
    [[nodiscard]] AbstractBTNode *getCopy() const override;
};


#endif //GAME_SETENEMYDIRNODE_H
