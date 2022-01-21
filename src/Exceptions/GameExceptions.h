//
// Created by benja on 17/01/2022.
//

#ifndef GAME_BEHAVIOURTREEEXCEPTIONS_H
#define GAME_GAMEEXCEPTIONS_H
class generic_game_error : public std::runtime_error{
public:
    generic_game_error(std::string message) : std::runtime_error(message){}
};

class game_started_error : public generic_game_error{
public:
    game_started_error(std::string message) : generic_game_error(message){}
    game_started_error() : generic_game_error("Game has already started"){}
};
#endif //GAME_BEHAVIOURTREEEXCEPTIONS_H
