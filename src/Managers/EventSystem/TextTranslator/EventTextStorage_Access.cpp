//
// Created by benja on 24/01/2022.
//


#include<vector>
#include <iostream>
#include "EventTextStorage_Access.h"
#include "EventTextStorage/EventTextTranslator.h"
#include "EventTextStorage/TextVariableLambdas.h"
#include "EventTextStorage/TextVariables.h"
#include "EventTextStorage/EventTextStorageContainer.h"
#include "../../../PlayerInfo/Player.h"
#include "../../../Random.h"
using container = EventTextStorageContainer;


std::string EventTextStorage_Access::getKill(const TextVariables& vars, bool groupFight) {
    std::string ret;
    if(groupFight) { //GROUP FIGHT
        auto survivorList{vars.getValue<std::vector<Player>>(TextVariables::KEY_SURVIVORLIST())};

        if (survivorList.size() > 1) {
            ret = container::manySurvivorSkirmish();
        } else {
            ret = container::soleSurvivorSkirmish();
        }
    }
    else{
        ret = container::oneVone();
    }
    return EventTextTranslator::translate(vars, ret);
}






