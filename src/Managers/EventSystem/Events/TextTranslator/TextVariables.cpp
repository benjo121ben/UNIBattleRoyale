//
// Created by benja on 24/01/2022.
//

#include "TextVariables.h"

bool TextVariables::isSet(const std::string& key) const {
    return varMap.count(key);
}
