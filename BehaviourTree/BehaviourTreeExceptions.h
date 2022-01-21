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

class unavailable_blackboard_key_BT_exception : public generic_behaviour_tree_exception{
public:
    unavailable_blackboard_key_BT_exception(const std::string& key) :
        generic_behaviour_tree_exception("the requested key way not found in blackboard. Key=" + key){}
};

class called_nullptr_child_BT_exception : public generic_behaviour_tree_exception{
public:
    called_nullptr_child_BT_exception() :
            generic_behaviour_tree_exception("BehaviourTree tried calling a function on a nullptr child"){}
};

#endif //GAME_BEHAVIOURTREEEXCEPTIONS_H
