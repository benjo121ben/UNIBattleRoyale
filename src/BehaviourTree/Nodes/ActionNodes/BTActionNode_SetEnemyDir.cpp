//
// Created by benja on 19/01/2022.
//

#include "BTActionNode_SetEnemyDir.h"
#include "../../Blackboard/BTBlackboard.h"
#include "../../../Managers/GameData.h"
#include "../../../PlayerInfo/Player.h"
#include "../../../MapInfo/Tileable.h"
#include "../../../MapInfo/cardinal_directions.h"
#include "../../../Pathfinder/Pathfinder.h"

BTNodestatus BTActionNode_SetEnemyDir::traverse(BTBlackboard *board) {
    BTNode_Abstract::traverse(board);
    Coordinate target{Coordinate::invalidCoords()};
    int selfIndex = board->getValue<int>(BlackboardKeys::PLAYERID());
    Coordinate selfPos = board->getCurrentPlayerPosition();

    auto& posList = board->getPlayerPositionList();

    for(auto& elem : board->getPlayerPositionList()){
        if(elem.first != selfIndex){

            if (target == Coordinate::invalidCoords() ||
                        stepDistance(selfPos, target) > stepDistance(selfPos, elem.second))
            {
                target = elem.second;
            }
        }
    }
    std::string dir;
    if(Pathfinder::getDirection(board->getMap(), selfPos, target,dir)){
        board->setValue(BlackboardKeys::PLAYERMOVEDIR(), string_to_dir(dir));
        return success;
    }
    return failure;
}

BTNode_Abstract *BTActionNode_SetEnemyDir::getCopy() const {
    return new BTActionNode_SetEnemyDir();
}


