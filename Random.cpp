//
// Created by benja on 18/01/2022.
//

#include "Random.h"
#include<random>
#include<iostream>


/// calculates a semi random value between 0 (included) and max (excluded)
/// \param max excluded maximum value
/// \return random value
int Random::get_random_Int(int max){
    static std::default_random_engine defEngine(time(NULL));
    std::uniform_int_distribution<int> intDistro(0,max-1);
    return intDistro(defEngine);
}