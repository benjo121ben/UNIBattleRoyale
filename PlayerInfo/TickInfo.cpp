//
// Created by benja on 18/01/2022.
//
#include "TickInfo.h"
#include <iostream>

TickInfo::TickInfo() : type{recover}{}
TickInfo::TickInfo(ActionType type, std::any&& data) : type{type}, data{data}{}
TickInfo::TickInfo(TickInfo::ActionType type, std::any&& data, std::any&& freeActionData,bool freeAction) :
    type{type}, data{data}, freeActionData {freeActionData}, freeAction{freeAction}{}
