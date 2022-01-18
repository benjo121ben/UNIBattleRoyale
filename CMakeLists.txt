cmake_minimum_required(VERSION 3.21)
project(Game)

set(CMAKE_CXX_STANDARD 17)

add_executable(Game main.cpp PlayerInfo/Player.cpp PlayerInfo/Pronouns.cpp MapInfo/GameMap.cpp MapInfo/Tileable.cpp GameManager.cpp Pathfinder/Pathfinder.cpp PlayerInfo/TickInfo.cpp)
