cmake_minimum_required(VERSION 3.16.2)
project(Game)

set(CMAKE_CXX_STANDARD 17)

add_executable(Game
        src/main.cpp
        src/PlayerInfo/Player.cpp
        src/PlayerInfo/Pronouns.cpp
        src/MapInfo/GameMap.cpp
        src/MapInfo/Tileable.cpp
        src/Managers/GameManager.cpp
        src/Managers/TurnManager.cpp
        src/Pathfinder/Pathfinder.cpp
        src/PlayerInfo/TickInfo.cpp
        src/Random.cpp
        src/Managers/EventSystem/GameEventTextHandler.cpp
        src/Managers/EventSystem/Events/MoveEvent.cpp
        src/Managers/EventSystem/Events/BaseEvent.cpp
        src/MapInfo/cardinal_directions.cpp
        src/Managers/EventSystem/EventAnnouncer.cpp
        src/BehaviourTree/Blackboard/BTBlackboard.cpp
        src/BehaviourTree/BehaviourTree.cpp
        src/BehaviourTree/BehaviourTree.h
        src/BehaviourTree/Nodes/ActionNodes/BTActionNode_MoveTowardsDir.cpp
        src/BehaviourTree/Blackboard/BlackboardKeys.cpp
        src/BehaviourTree/BTTemplates.cpp
        src/BehaviourTree/Nodes/ActionNodes/BTActionNode_SetEnemyDir.cpp
        src/BehaviourTree/Nodes/CompositeNode/BTNode_CompositeNode.cpp
        src/BehaviourTree/Nodes/CompositeNode/CompNode_Selector.cpp
        src/BehaviourTree/Nodes/CompositeNode/CompNode_Sequence.cpp
        src/BehaviourTree/Nodes/ActionNodes/BTActionNode_CoutDebug.cpp
        src/BehaviourTree/Nodes/BTNode_Abstract.cpp
        src/BehaviourTree/Nodes/ActionNodes/BTActionNode_SetRandomMoveDir.cpp
        src/BehaviourTree/Nodes/ActionNodes/BTActionNode_CheckBoardValue.cpp
        src/BehaviourTree/Nodes/ActionNodes/BTActionNode_CheckEnemyInAttackRange.cpp
        src/BehaviourTree/Nodes/ActionNodes/BTActionNode_Attack.cpp
        src/Managers/EventSystem/Events/KillEvent.cpp src/Managers/EventSystem/Events/KillEvent.h)
