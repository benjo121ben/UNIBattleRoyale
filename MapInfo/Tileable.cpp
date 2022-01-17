//
// Created by benja on 15/12/2021.
//

#include "Tileable.h"
#include<stdexcept>
#include<cmath>
#include<iostream>

Coordinate::Coordinate(int x, int y) :x{x}, y{y}{}

std::string Coordinate::print() const{
    std::string ret = "(";
    ret += std::to_string(x);
    ret += ", " + std::to_string(y)  +")";
    return ret;
}

Coordinate& Coordinate::operator=(const Coordinate& c2)= default;

std::string Coordinate::hashValue()const{
    return std::to_string(x) + "/" + std::to_string(y);
}


bool operator<(const Coordinate &c1, const Coordinate &c2) {
    return c1.y < c2.y || c1.x < c2.x;
}

bool operator==(const Coordinate &c1, const Coordinate &c2) {
    return c1.x == c2.x && c1.y == c2.y;
}

float distance(const Coordinate &c1, const Coordinate &c2){
    float xDis = (float)std::abs(c2.x - c1.x) * 0.1f;
    float yDis = (float)std::abs(c2.y - c1.y)* 0.1f;
    return xDis+yDis;
}

int stepDistance(const Coordinate &c1, const Coordinate &c2){
    int xDis = std::abs(c2.x - c1.x);
    int yDis = std::abs(c2.y - c1.y);
    return xDis+yDis;
}

Tileable::Tileable(int x, int y): coords{x,y}{}

std::string Tileable::hashValue() const{
    return coords.hashValue();
}



Tile::Tile(int x, int y, TerrainType terrain) : Tileable(x,y), tileType{terrain}{}

Tile::Tile(const Tile& other) : Tile(other.coords.x, other.coords.y, other.tileType){}

float Tile::cost() const {
    switch(tileType){
        case plains: return 1;
        case mountain: return 2;
        case forest: return 1;
        case water: return 3;
    }
    throw std::runtime_error("wrong tiletype asked from cost: " + std::to_string(tileType));
}

std::string Tile::print() const{
    switch (tileType) {
        case water: return "~";
        case plains: return "p";
        case forest: return "#";
        case mountain: return "M";
    }
    return "";
}

Tile& Tile::operator=(const Tile& otherTile)= default;

int Tile::getX() const {
    return coords.x;
}

int Tile::getY() const{
    return coords.y;
}

Tile* Tile::getCopyPtr() const{
    return new Tile(*this);
}



BRTile::BRTile(int x, int y, TerrainType tileType, bool spawn) : Tile(x,y, tileType), spawn{spawn}{}
BRTile::BRTile(const BRTile& other) : BRTile(other.getX(),other.getY(), other.tileType, other.spawn){}

std::string BRTile::print() const {
    if (spawn)return "0";
    return Tile::print();
}

bool BRTile::isSpawn() const{
    return spawn;
}

BRTile* BRTile::getCopyPtr() const{
    return new BRTile(*this);
}
