//
// Created by benja on 19/01/2022.
//

#include "SetEnemyDirNode.h"
#include "../../Blackboard/BlackboardKeys.h"
#include "../../Blackboard/BTBlackboard.h"
#include "../../../Managers/GameData.h"
#include "../../../PlayerInfo/Player.h"
#include "../../../MapInfo/Tileable.h"
#include "../../../MapInfo/cardinal_directions.h"
#include "../../../Pathfinder/Pathfinder.h"

BTNodestatus SetEnemyDirNode::traverse(BTBlackboard *board) {
    AbstractBTNode::traverse(board);
    Coordinate target{Coordinate::invalidCoords()};
    int selfIndex = board->getValue<int>(BlackboardKeys::PLAYERID());
    Coordinate selfPos = board->getPlayerCoordinate(selfIndex);

    const std::vector<Player> pList = board->publicData.playerList;
    const std::vector<Coordinate> posList = board->publicData.playerPositions;

    for(int index{0}; index < pList.size(); ++index){
        if(index != selfIndex){
            Coordinate targetPosition {board->getPlayerCoordinate(index)};
            if(target == Coordinate::invalidCoords()){
                target = targetPosition;
            }
            else if (stepDistance(selfPos, target) > stepDistance(selfPos, targetPosition)){
                target = targetPosition;
            }
        }
    }
    std::string dir;
    if(Pathfinder::getDirection(board->publicData.map, selfPos, target,dir)){
        board->setValue(BlackboardKeys::PLAYERMOVEDIR(), string_to_dir(dir));
        return success;
    }
    return failure;
}

AbstractBTNode *SetEnemyDirNode::getCopy() const {
    return new SetEnemyDirNode();
}


