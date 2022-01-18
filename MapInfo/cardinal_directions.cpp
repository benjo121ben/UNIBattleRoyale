//
// Created by benja on 18/01/2022.
//

#include "cardinal_directions.h"

std::string dir_to_string(cardinal_directions dir){
    switch (dir) {
        case north: return "north";
        case south: return "south";
        case west: return "west";
        case east: return "east";
    }
    return "";
}