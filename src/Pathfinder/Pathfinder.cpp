//
// Created by benja on 07/12/2021.
//

#include"Pathfinder.h"
#include"../MapInfo/TileMap.h"
#include"../MapInfo/Tileable.h"
#include<stdexcept>
#include<unordered_set>
#include<stack>
#include<iostream>

bool Pathfinder::getDirection(const GameMap& map, const Coordinate& start, const Coordinate& goal, std::string& dir){
    if(start == goal) return false;
    auto nodes {findPath(map,start,goal)};
    Coordinate diff = nodes.at(1).getCoords()-nodes.at(0).getCoords();
    if(diff.x > 0){
        dir = "east";
        return true;
    }
    else if(diff.x < 0){
        dir = "west";
        return true;
    }
    else if(diff.y > 0){
        dir = "south";
        return true;
    }
    else if(diff.y < 0){
        dir = "north";
        return true;
    }
    return false;
}

std::deque<Node> Pathfinder::findPath(const GameMap& map, const Coordinate &start, const Coordinate &goal) {

    if(!map.existsTileAt(start.x,start.y)) throw std::invalid_argument("invalid start coordinate");

    Node root{map.getTileAt(start.x, start.y),goal};

    std::map<std::size_t, Node> nodes;
    std::map<std::size_t, Node *> toVisit;
    std::unordered_set<std::size_t> visited;

    visited.insert(root.getCoords().hashValue());
    //std:.cout << "children: ";
    for(const Tileable* t : map.getTilesAround(root.getCoords())){
        //std:.cout << t.coords.print() <<", " << "\n";
        nodes.insert(std::pair<std::size_t, Node>(t->hashValue(),Node(t, goal,&root)));
        Node * ptr = &nodes.at(t->hashValue());
        toVisit.insert(std::pair<std::size_t, Node *> (t->hashValue(),ptr));
    }

    while(!toVisit.empty()){
        Node* n = toVisit.begin()->second;
        //std:.cout << "\nchecking: ";
        for(auto& otherNode : toVisit){
            //std:.cout << otherNode.second->getCoords().print() << "/" << otherNode.second->getCost() << ", ";
            if(otherNode.second->getPrio() < n->getPrio()){
                n = otherNode.second;
            }
        }
        //std:.cout << "\nvisiting: " <<  n->getCoords().print() << "parent: " << n->getParentCoordinates().print()<<"\n";
        toVisit.erase(n->getCoords().hashValue());
        visited.insert(n->getCoords().hashValue());
        if(n->getCoords() == goal) {
            //std:.cout<< "ended search: "<< n->getCoords().print() << "parent: " << n->getParentCoordinates().print()<<"\n";
            auto ret{ n->getPathDeque()};
            return ret;
        }
        //std:.cout << "searching around: ";
        for(const Tileable* checkTile : map.getTilesAround(n->getCoords())){
            //std:.cout << checkTile.coords.print() <<", ";
            if(visited.count(checkTile->hashValue()) == 0){
                if(toVisit.count(checkTile->hashValue()) != 0){
                    //std:.cout << "____________________________" << n->getCoords().print() << "\n";
                    toVisit.at(checkTile->hashValue())->trySetParent(*n);
                }
                else{
                    //std:.cout << "inserting: \n";
                    //std:.cout << n->getCoords().print() << "\n";
                    //std:.cout << checkTile.coords.print() << "\n";
                    nodes.insert(std::pair<std::size_t, Node>(checkTile->hashValue(),Node(checkTile, goal,n)));
                    Node * ptr = &nodes.at(checkTile->hashValue());
                    toVisit.insert(std::pair<std::size_t, Node *> (checkTile->hashValue(),ptr));
                }
            }
        }
        //std:.cout << "\n";
    }
    throw std::runtime_error("could not reach goal coordinate");

}

void Pathfinder::outputPath(const GameMap& map, const Coordinate& start, const Coordinate& goal){
    std::cout << "Route: " << start.print() << " -> " << goal.print() << std::endl;
    std::deque<Node> deque = findPath(map,start,goal);
    std::cout << "Path taken: ";
    for(int pos {0}; pos < deque.size(); pos++){
        Node n = deque.at(pos);
        if(pos != 0){
            std::cout << " -> ";
        }
        std::cout << n.getCoords().print() << "/" << n.getCost();
    }
    std::cout << "\ncost: " << deque.at(deque.size()-1).getCost() << "\n\n\n";
}

Node::Node(const Tileable* t, const Coordinate& goal, Node *parent) : tile{t->getPtr()}, parent{parent} {
    if(parent){
        baseCost = tile->cost() + parent->getCost();

        if(t->getX() > parent->tile->getX()){
            walkDir = right;
        }
        else if(t->getX() < parent->tile->getX()){
            walkDir = left;
        }
        else if(t->getY() > parent->tile->getY()){
            walkDir = up;
        }
        else{
            walkDir = down;
        }
        //std:.cout << "nodeConstructor: " << t.coords.print() << ", parent->" << parent->getCoords().print();
    }
    else{
        baseCost = 0;
        walkDir = root;
    }
    distanceCost = distance(Coordinate(t->getX(), t->getY()) ,goal);
}
Node::~Node(){
}


Node::Node(const Node& n) : tile{n.tile->getPtr()},parent{n.parent},distanceCost{n.distanceCost},baseCost{n.baseCost}{
}

Coordinate Node::getCoords() const{
    return Coordinate(tile->getX(),tile->getY());
}

float Node::getCost() const {
    return baseCost;
}

float Node::getPrio() const{
    return baseCost + distanceCost*0.1f;
}

const Tileable* Node::getTile() const {
    return tile;
}

void Node::trySetParent(Node& newParent) {
    if(!parent){
        parent = &newParent;
    }
    parent = newParent.getCost() < parent->getCost() ? &newParent : parent;
}

Coordinate Node::getParentCoordinates() const{
    return parent->getCoords();
}

Node& Node::operator=(const Node& n){
    baseCost = n.baseCost;
    parent = n.parent;
    distanceCost = n.distanceCost;
    tile = n.tile;
    return *this;
}

std::deque<Node> Node::getPathDeque() {
    std::deque<Node> deque;
    Node *n = this;
    //std:.cout << "going down rabbit hole: " << n->getCoords().print();
    do {
        deque.emplace_front(*n);
        //std:.cout << n->getCoords().print();
        n = n->parent;
    }while(n != nullptr);
    //std:.cout << "went down rabbit hole\n";
    return deque;
}


