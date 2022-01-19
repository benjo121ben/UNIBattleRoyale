//
// Created by benja on 17/01/2022.
//

#ifndef GAME_BEHAVIOURTREEEXCEPTIONS_H
#define GAME_BEHAVIOURTREEEXCEPTIONS_H
#include<stdexcept>

class generic_behaviour_tree_exception : public std::runtime_error{
public:
    generic_behaviour_tree_exception() : std::runtime_error("an error has occurred in the behaviourTree"){}
    generic_behaviour_tree_exception(std::string message) : std::runtime_error(message){}
};

class unavailable_blackboard_key_exception : public generic_behaviour_tree_exception{
public:
    unavailable_blackboard_key_exception(const std::string& key) :
        generic_behaviour_tree_exception("the requested key way not found in blackboard. Key=" + key){}
};

#endif //GAME_BEHAVIOURTREEEXCEPTIONS_H
