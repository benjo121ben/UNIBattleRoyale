//
// Created by benja on 24/01/2022.
//

#ifndef GAME_EVENTTEXTTRANSLATOR_H
#define GAME_EVENTTEXTTRANSLATOR_H
#include<string>
#include<vector>
#include<any>
#include <functional>
#include "TextVariables.h"
#include "TextVariableLambdas.h"
class EventTextTranslator {
    static std::string interpretKeyword(const TextVariables &variables, const std::string& keyword);
    static std::string interpretKeywordWithLambda(const TextVariables &variables, std::string& keyword, std::string& lambda_keyword);
    static std::string interpretListKeyword(const TextVariables &variables, const std::string& listKeyword);
    static bool bracketCheck(const char& beginChar, const char& endChar, const std::string checkString, int& first, int& second, int startIndex = 0);
    template<typename T> static std::string outputList(std::vector<T> list, std::function<std::string(const std::any&)>& func);
public:
    [[nodiscard]]static std::string translate(const TextVariables& vars, std::string baseText);



};



#include "EventTextTranslator.tci"



#endif //GAME_EVENTTEXTTRANSLATOR_H
