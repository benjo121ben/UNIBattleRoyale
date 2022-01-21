cmake_minimum_required(VERSION 3.21)
project(Game)

set(CMAKE_CXX_STANDARD 17)

add_executable(Game
        main.cpp
        PlayerInfo/Player.cpp
        PlayerInfo/Pronouns.cpp
        MapInfo/GameMap.cpp
        MapInfo/Tileable.cpp
        Managers/GameManager.cpp
        Managers/TurnManager.cpp
        Pathfinder/Pathfinder.cpp
        PlayerInfo/TickInfo.cpp
        Random.cpp
        Managers/EventSystem/GameEventTextHandler.cpp
        Managers/EventSystem/Events/MoveEvent.cpp
        Managers/EventSystem/Events/BaseEvent.cpp
        MapInfo/cardinal_directions.cpp
        Managers/EventSystem/EventAnnouncer.cpp
        BehaviourTree/Blackboard/BTBlackboard.cpp
        BehaviourTree/BehaviourTree.cpp
        BehaviourTree/BehaviourTree.h
        BehaviourTree/Nodes/ActionNodes/BTActionNode_MoveTowardsDir.cpp
        BehaviourTree/Blackboard/BlackboardKeys.cpp
        BehaviourTree/BTTemplates.cpp
        BehaviourTree/Nodes/ActionNodes/BTActionNode_SetEnemyDir.cpp
        BehaviourTree/Nodes/CompositeNode/BTNode_CompositeNode.cpp
        BehaviourTree/Nodes/CompositeNode/CompNode_Selector.cpp
        BehaviourTree/Nodes/CompositeNode/CompNode_Sequence.cpp
        BehaviourTree/Nodes/ActionNodes/BTActionNode_CoutDebug.cpp
        BehaviourTree/Nodes/BTNode_Abstract.cpp
        BehaviourTree/Nodes/ActionNodes/BTActionNode_SetRandomMoveDir.cpp
        BehaviourTree/Nodes/ActionNodes/BTActionNode_CheckBoardValue.cpp BehaviourTree/Nodes/ActionNodes/BTActionNode_CheckBoardValue.h BehaviourTree/Nodes/ActionNodes/BTActionNode_CheckEnemyOnSameCoordinate.cpp BehaviourTree/Nodes/ActionNodes/BTActionNode_CheckEnemyOnSameCoordinate.h)
