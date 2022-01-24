//
// Created by benja on 24/01/2022.
//

#ifndef GAME_TEXTVARIABLES_H
#define GAME_TEXTVARIABLES_H
#include <string>
#include <map>
#include <any>
#include <stdexcept>

class TextVariables {
    std::map<std::string, std::any> varMap;
    template <typename T> T getValue(const std::string& key) const{
        if(!isSet(key)){
            throw std::runtime_error("TextVariables::getValue " + key);
        }
        return std::any_cast<T>(varMap.at(key));
    }

    template <typename T> void setValue(const std::string& key, T value){
        varMap.insert_or_assign(key, std::make_any<T>(value));
    }

    bool isSet(const std::string& key) const;
};


#endif //GAME_TEXTVARIABLES_H
