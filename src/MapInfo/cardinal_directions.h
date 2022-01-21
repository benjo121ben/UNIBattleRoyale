//
// Created by benja on 18/01/2022.
//

#ifndef CARDINAL_DIRECTIONS_H
#define CARDINAL_DIRECTIONS_H

#include<string>

enum cardinal_directions{
    north, south, west, east
};


std::string dir_to_string(cardinal_directions dir);
cardinal_directions string_to_dir(std::string s);


#endif //CARDINAL_DIRECTIONS_H
