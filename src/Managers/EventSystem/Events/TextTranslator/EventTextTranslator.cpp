//
// Created by benja on 24/01/2022.
//

#include <iostream>
#include "EventTextTranslator.h"


std::string EventTextTranslator::translate(std::string baseText, const TextVariables &vars) {
    int index, first_to_copy_Index = 0;
    std::string ret;
    bool keep_going;
    do {
        keep_going = false;
        int first {-1}, second{-1};
        for (index = first_to_copy_Index; index < baseText.size(); ++index) {
            if (first == -1 && baseText.at(index) == '{') {
                first = index;
            }
            else if(first != -1 && baseText.at(index) == '}') {
                second = index;
                break;
            }
        }
        if(first != -1 && second < first) throw std::runtime_error("EventTextTranslator: no closing bracket found in: " + baseText);
        else if(first != -1) {
            ret += baseText.substr(first_to_copy_Index, first-first_to_copy_Index);
            first_to_copy_Index = second +1;
            keep_going = true;
            std::string keyword = baseText.substr(first+1, second-first-1);
            std::cout << keyword << std::endl;
            if(keyword == "test") {
                ret += "replaced";
            }
        }
    }while(keep_going);
    ret += baseText.substr(first_to_copy_Index, index - first_to_copy_Index + 1);
    return ret;
}


