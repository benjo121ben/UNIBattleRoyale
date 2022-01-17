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
    enum dir{
        left,right,up,down, root
    };

    const Tileable* tile;
    Node* parent;
    float distanceCost;
    float baseCost;

public:
    dir walkDir;
    Node(const Node& n);
    Node(const Tileable* t, const Coordinate& goal, Node* parent = nullptr);
    Coordinate getCoords() const;
    float getCost() const;
    float getPrio() const;
    const Tileable* getTile() const;
    void trySetParent(Node& newParent);
    Coordinate getParentCoordinates() const;
    std::stack<Node> getPathStack();

    Node& operator=(const Node& n);
};


class Pathfinder{
public:
    static std::stack<Node> findPath(const TileMap<Tileable>& map, const Coordinate& start, const Coordinate& goal);
    static std::stack<Node> findPath(const GameMap& map, const Coordinate& start, const Coordinate& goal);
    static void outputPath(const TileMap<Tileable>& map, const Coordinate& start, const Coordinate& goal);
    static void outputPath(const GameMap& map, const Coordinate& start, const Coordinate& goal);



};


#endif //ASTAR_PATHFINDER_H
