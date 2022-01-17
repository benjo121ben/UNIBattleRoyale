//
// Created by benja on 15/12/2021.
//

#ifndef AI_TILEABLE_H
#define AI_TILEABLE_H

#include<string>

class Coordinate{
public:
    int x;
    int y;

    Coordinate(int x, int y);
    std::string hashValue() const;
    std::string print() const;
    Coordinate& operator=(const Coordinate& c2);
};


bool operator<(const Coordinate &c1, const Coordinate &c2);
bool operator==(const Coordinate &c1, const Coordinate &c2);
float distance(const Coordinate &c1, const Coordinate &c2);
int stepDistance(const Coordinate &c1, const Coordinate &c2);

class Tileable{
protected:
    Coordinate coords;
public:
    virtual int getX() const = 0;
    virtual int getY() const = 0;
    virtual float cost() const = 0;
    virtual std::string hashValue() const;
    Tileable(int x, int y);
    virtual std::string print() const = 0;
};

class Tile : public Tileable{
public:
    enum TerrainType{
        plains, forest, mountain, water
    };
public:
    TerrainType tileType;
    Tile(int x, int y, TerrainType t);
    Tile(const Tile& other);
    Tile& operator=(const Tile&);
    virtual int getX() const override;
    virtual int getY() const override;

    float cost() const override;
    std::string print() const override;
};

class BRTile : public Tile{
    bool spawn;
public:
    BRTile(int x, int y, TerrainType tileType, bool spawn = false);
    BRTile(const BRTile& other);
    std::string print() const override;
    bool isSpawn() const;
};



#endif //AI_TILEABLE_H
