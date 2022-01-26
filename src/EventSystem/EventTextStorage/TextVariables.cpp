//
// Created by benja on 24/01/2022.
//

#include "TextVariables.h"
#include "TextVariableLambdas.h"

bool TextVariables::isSet(const std::string& key) const {
    return varMap.count(key);
}

std::any TextVariables::getValue_asAny(const std::string& key) const{
    if(!isSet(key)){throw std::runtime_error("TextVariables::getValue_asAny " + key);}
    return varMap.at(key);
}


