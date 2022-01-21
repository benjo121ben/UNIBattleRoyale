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
        BehaviourTree/Nodes/ActionNodes/MoveNode.cpp
        BehaviourTree/Blackboard/BlackboardKeys.cpp
        BehaviourTree/BTTemplates.cpp
        BehaviourTree/Nodes/ActionNodes/SetEnemyDirNode.cpp
        BehaviourTree/Nodes/CompositeNode/CompositeNode.cpp
        BehaviourTree/Nodes/CompositeNode/Selector.cpp
        BehaviourTree/Nodes/CompositeNode/Sequence.cpp
        BehaviourTree/Nodes/ActionNodes/CoutDebugNode.cpp
        BehaviourTree/Nodes/AbstractBTNode.cpp
        BehaviourTree/Nodes/ActionNodes/SetRandomMoveDirNode.cpp
        BehaviourTree/Nodes/ActionNodes/CheckBoardValueNode.cpp BehaviourTree/Nodes/ActionNodes/CheckBoardValueNode.h)
