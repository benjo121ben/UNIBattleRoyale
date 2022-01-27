//
// Created by benja on 18/01/2022.
//

#ifndef GAME_RANDOM_H
#define GAME_RANDOM_H


#include <random>

class Random{

    std::random_device device;
    Random() = default;
public:
    static int get_random_Int(int max);
};
#endif //GAME_RANDOM_H
