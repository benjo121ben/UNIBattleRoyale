//
// Created by benja on 07/12/2021.
//

#ifndef ASTAR_TILEMAP_H
#define ASTAR_TILEMAP_H

#include<map>
#include<vector>
#include<string>
#include"Tileable.h"



template <typename T> class TileMap{
protected:
    std::map<std::string,T*> tileMap;
public:

    int sizeX = 0;
    int sizeY = 0;
    void add(T* t);
    std::vector<T*> getTilesAround(int x, int y) const;
    std::vector<T*> getTilesAround(const Coordinate& c)const;
    const T* getTileAt(int x, int y) const;
    [[nodiscard]] bool existsTileAt(int x, int y) const;
    [[nodiscard]] bool existsTileAt(const Coordinate& c) const;

    ~TileMap();

    virtual std::string printMap(bool showSpawn = false) const;

};

#include "TileMap_impl.tci"

#endif //ASTAR_TILEMAP_H
