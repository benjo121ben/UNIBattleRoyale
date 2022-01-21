//
// Created by benja on 17/01/2022.
//

#ifndef GAME_BEHAVIOURTREEEXCEPTIONS_H
#define GAME_BEHAVIOURTREEEXCEPTIONS_H
#include<stdexcept>

class generic_behaviour_tree_exception : public std::runtime_error{
public:
    explicit generic_behaviour_tree_exception(const std::string& originFunction) : std::runtime_error(originFunction + ": An error has occurred in the behaviourTree."){}
    generic_behaviour_tree_exception(const std::string& originFunction, const std::string& message) : std::runtime_error(originFunction + ": " + message){}
};

class unavailable_blackboard_key_BT_exception : public generic_behaviour_tree_exception{
public:
    unavailable_blackboard_key_BT_exception(const std::string& originFunction, const std::string& key) :
        generic_behaviour_tree_exception(originFunction, "the requested key way not found in blackboard. Key=" + key){}
};

class called_nullptr_child_BT_exception : public generic_behaviour_tree_exception{
public:
    called_nullptr_child_BT_exception(const std::string& originFunction) :
            generic_behaviour_tree_exception(originFunction,"BehaviourTree tried calling a function on a nullptr child"){}
};

#endif //GAME_BEHAVIOURTREEEXCEPTIONS_H
