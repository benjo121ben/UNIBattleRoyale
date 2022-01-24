//
// Created by benja on 24/01/2022.
//

#ifndef GAME_EVENTTEXTTRANSLATOR_H
#define GAME_EVENTTEXTTRANSLATOR_H
#include<string>
#include<vector>
#include <functional>
#include "TextVariables.h"
class EventTextTranslator {
public:
    static std::string translate(std::string baseText, const TextVariables& vars);
    template<typename T> static std::string outputList(std::vector<T> list, std::function<std::string(const T&)> func);
};

#include "EventTextTranslator.tci"


#endif //GAME_EVENTTEXTTRANSLATOR_H
