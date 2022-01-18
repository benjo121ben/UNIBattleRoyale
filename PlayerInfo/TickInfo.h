//
// Created by benja on 18/01/2022.
//

#ifndef GAME_TICKINFO_H
#define GAME_TICKINFO_H
#include<string>
#include<any>

enum cardinal_directions{
    north, south, west, east
};

struct TickInfo{
    enum ActionType{
        move, flee, recover, attack, scout, gather, reinforce
    };
    ActionType type;
    bool freeAction = false;
    std::any data;
    std::any freeActionData;

    TickInfo();
    TickInfo(ActionType type, std::any&& data);
    TickInfo(ActionType type, std::any&& data, std::any&& freeActionData,bool freeAction = true);
};


#endif //GAME_TICKINFO_H
