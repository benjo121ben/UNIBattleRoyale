//
// Created by benja on 07/12/2021.
//

#ifndef ASTAR_PATHFINDER_H
#define ASTAR_PATHFINDER_H

#include "../MapInfo/TileMap.h"
#include "../MapInfo/GameMap.h"
#include<vector>
#include<stack>


class Node{


    const Tileable* tile;
    Node* parent;
    float distanceCost;
    float baseCost;

public:
    enum dir{
        left,right,up,down, root
    };

    dir walkDir;
    Node(const Node& n);
    Node(const Tileable* t, const Coordinate& goal, Node* parent = nullptr);
    ~Node();
    Coordinate getCoords() const;
    float getCost() const;
    float getPrio() const;
    const Tileable* getTile() const;
    void trySetParent(Node& newParent);
    Coordinate getParentCoordinates() const;
    std::deque<Node > getPathDeque();

    Node& operator=(const Node& n);
};


class Pathfinder{
public:
    static bool getDirection(const GameMap& map, const Coordinate& start, const Coordinate& goal, std::string& dir);
    static std::deque<Node> findPath(const GameMap& map, const Coordinate& start, const Coordinate& goal);
    static void outputPath(const GameMap& map, const Coordinate& start, const Coordinate& goal);



};


#endif //ASTAR_PATHFINDER_H
