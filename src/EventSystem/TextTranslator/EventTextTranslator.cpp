//
// Created by benja on 24/01/2022.
//

#include <iostream>
#include <functional>
#include "EventTextTranslator.h"
#include "../../PlayerInfo/Player.h"

using lambdas = TextVariableLambdas;

std::string EventTextTranslator::translate(const TextVariables &vars, std::string baseText) {
        int first_to_copy_Index = 0;
        std::string ret;
        bool keep_going;
        do {
            keep_going = false;
            int first{-1}, second{-1};
            bool found = bracketCheck('{', '}', baseText, first, second, first_to_copy_Index);
            if (found) {
                keep_going = true;
                ret += baseText.substr(first_to_copy_Index, first - first_to_copy_Index);
                first_to_copy_Index = second + 1;
                std::string keyword = baseText.substr(first + 1, second - first - 1);
                ret += interpretKeyword(vars, keyword);
            }
        } while (keep_going);
        ret += baseText.substr(first_to_copy_Index, baseText.size() - first_to_copy_Index);
        return ret;

}

std::string EventTextTranslator::interpretKeyword(const TextVariables &variables, const std::string& keyword) {
    std::string ret;
    int first{-1}, second{-1};
    bool checkForListBrackets = bracketCheck('[',']', keyword, first,second);
    if(checkForListBrackets) {
        std::string listKeyWord = keyword.substr(first+1, second-first-1);
        return interpretListKeyword(variables, listKeyWord);
    }

    bool checkForLambdaBrackets = bracketCheck('(',')', keyword, first,second);
    if(checkForLambdaBrackets) {
        std::string mainKey = keyword.substr(0, first - 1);
        std::string subKey = keyword.substr(first + 1, second - first - 1);
        return interpretKeywordWithLambda(variables, mainKey, subKey);
    }
    else{
        return variables.getValue<std::string>(keyword);
    }

    return ret;
}

std::string EventTextTranslator::interpretKeywordWithLambda(const TextVariables &variables, std::string& keyword, std::string& lambda_keyword) {
    //SUB KEYS SET THE FUNCTION
    std::function<std::string(const std::any&)> func = lambdas::getLambda(lambda_keyword);
    return func(variables.getValue_asAny(keyword));

}



std::string EventTextTranslator::interpretListKeyword(const TextVariables &variables, const std::string& listKeyword) {

    int first{-1}, second{-1};
    bool checkForLambda = bracketCheck('(',')', listKeyword, first,second);
    if(!checkForLambda) throw std::runtime_error("EventTextTranslator: no closing bracket for list SubkeyWord found in: " + listKeyword);
    std::string mainKeyword = listKeyword.substr(0, first-1);
    std::string subKeyword = listKeyword.substr(first+1, second-first-1);


    //SUB KEYS SET THE FUNCTION
    std::function<std::string(const std::any&)> func = lambdas::getLambda(subKeyword);


    //MAIN KEYS
    if(mainKeyword == TextVariables::KEY_SURVIVORLIST()){
        auto survivorList = variables.getValue<std::vector<Player>>(TextVariables::KEY_SURVIVORLIST());
        return outputList<Player>(survivorList, func);
    }
    else if(mainKeyword == TextVariables::KEY_DEADLIST()){
        auto survivorList = variables.getValue<std::vector<Player>>(TextVariables::KEY_DEADLIST());
        return outputList<Player>(survivorList, func);
    }

    return "COULD NOT TRANSLATE THIS KEYWORD:/" + mainKeyword +"/";
}



bool EventTextTranslator::bracketCheck(const char& beginChar, const char& endChar, const std::string checkString, int& first, int& second, int startIndex){
    bool firstFound = false;
    bool secondFound = false;
    for (int index{startIndex}; index < checkString.size(); ++index) {
        if (!firstFound && checkString.at(index) == beginChar) {
            first = index;
            firstFound = true;
        }
        else if(firstFound && checkString.at(index) == endChar) {
            second = index;
            secondFound = true;
            break;
        }
    }
    if(firstFound && !secondFound) throw std::runtime_error("EventTextTranslator: no closing bracket for bracketCheck found in: " + checkString);
    else if(firstFound) {
        return true;
    }
    else{
        return false;
    }
}







