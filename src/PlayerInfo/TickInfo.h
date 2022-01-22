//
// Created by benja on 18/01/2022.
//

#ifndef GAME_TICKINFO_H
#define GAME_TICKINFO_H
#include<string>
#include<any>



struct TickInfo{
private:
    std::any data;
    std::any freeActionData;
public:
    enum ActionType{
        move, flee, recover, attack, scout, gather, reinforce
    };
    ActionType type;
    bool freeAction = false;


    TickInfo();
    TickInfo(ActionType type, std::any&& data);
    TickInfo(ActionType type, std::any&& data, std::any&& freeActionData,bool freeAction = true);

    template<class T> T getData() const {
        return std::any_cast<T>(data);
    }

};


#endif //GAME_TICKINFO_H
