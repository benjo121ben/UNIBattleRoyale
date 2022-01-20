//
// Created by benja on 18/01/2022.
//

#include "cardinal_directions.h"
#include<stdexcept>

std::string dir_to_string(cardinal_directions dir){
    switch (dir) {
        case north: return "north";
        case south: return "south";
        case west: return "west";
        case east: return "east";
    }
    return "";
}

cardinal_directions string_to_dir(std::string s){
    if(s == "north") return north;
    if(s == "south") return south;
    if(s == "west") return west;
    if(s == "east") return east;
    throw std::runtime_error("tried to convert invalid string to cardinal direction");
}