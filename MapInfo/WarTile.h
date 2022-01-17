//
// Created by benja on 16/01/2022.
//

#ifndef GAME_WARTILE_H
#define GAME_WARTILE_H
#include "Tileable.h"

class WarTile : public Tile{
    int flag = 0;
    std::string agentId = "";
public:
    WarTile(int x,int y, TerrainType t, int flag, std::string agentId): Tile{x,y,t}, flag{flag}, agentId{agentId}{}
    int getFlagInfo(){return flag;}
    std::string getAgentID(){return agentId;}
    float cost() const override{return 1;}
    virtual Tileable* getCopyPtr() const override {return new WarTile(coords.x,coords.y, tileType,flag,agentId);}
    std::string print(){
        if(!agentId.empty()) return "P";
        else{
            if(flag != 0) return "F";
            if(tileType == water) return "w";
            if(tileType == plains) return "-";
            return "^";
        }

    }
};
#endif //GAME_WARTILE_H
