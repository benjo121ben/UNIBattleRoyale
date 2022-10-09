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

    Coordinate();
    explicit Coordinate(int x, int y);
    static Coordinate invalidCoords();
    std::size_t hashValue() const;
    std::string print() const;
    Coordinate& operator=(const Coordinate& c2);
};

Coordinate operator-(const Coordinate &c1, const Coordinate &c2);
bool operator<(const Coordinate &c1, const Coordinate &c2);
bool operator==(const Coordinate &c1, const Coordinate &c2);
bool operator!=(const Coordinate &c1, const Coordinate &c2);
float distance(const Coordinate &c1, const Coordinate &c2);
int stepDistance(const Coordinate &c1, const Coordinate &c2);

class Tileable{
protected:
    Coordinate coords;
public:
    Tileable(int x, int y);

    [[nodiscard]] virtual int getX() const = 0;
    [[nodiscard]] virtual int getY() const = 0;
    [[nodiscard]] virtual float cost() const = 0;
    [[nodiscard]] virtual std::size_t hashValue() const;
    [[nodiscard]] virtual Tileable* getCopyPtr() const = 0;
    [[nodiscard]] virtual const Tileable* getPtr() const = 0 ;
    [[nodiscard]] virtual std::string print(bool) const = 0;
    virtual ~Tileable() = default;
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
    virtual ~Tile() = default;
    Tile& operator=(const Tile&);
    [[nodiscard]] int getX() const override;
    [[nodiscard]] int getY() const override;
    [[nodiscard]] Tile* getCopyPtr() const override;
    [[nodiscard]] virtual const Tile* getPtr() const override;

    [[nodiscard]] float cost() const override;
    [[nodiscard]] std::string print(bool) const override;
};

class BRTile : public Tile{
    bool spawn;
public:
    BRTile(int x, int y, TerrainType tileType, bool spawn = false);
    BRTile(const BRTile& other);
    virtual ~BRTile() = default;
    [[nodiscard]] BRTile* getCopyPtr() const override;
    [[nodiscard]] virtual const BRTile* getPtr() const override;
    [[nodiscard]] std::string print(bool showSpawn) const override;
    [[nodiscard]] bool isSpawn() const;
};



#endif //AI_TILEABLE_H
