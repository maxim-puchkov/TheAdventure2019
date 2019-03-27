#include "Internationalization.h"

using internationalization::Internationalization;

Internationalization::Internationalization(){
    users_json = jsonParser.processJSON(json_filePath);

    if(users_json == nullptr){
        std::ofstream("strings.json");
    }

    bindEnumToKey();
    loadStringsToMap();
}

void Internationalization::loadStringsToMap() {
    for(auto& pair : stringMap) {
        auto& key = pair.second;

        //if not found, keep it as default
        auto temp = extractStringFromJSON(key);
        if(temp != "") {
            key = temp;
        }
    }
}

void Internationalization::bindEnumToKey() {
    //why wouldn't people create enum.toString for C++?
    generateDefaultStrings(Internationalization::STRING_CODE::COMMAND_NOT_FOUND, "command_not_found");
    generateDefaultStrings(Internationalization::STRING_CODE::WRONG_COMMAND_SYNTAX, "wrong_command_syntax");
}

void Internationalization::generateDefaultStrings(Internationalization::STRING_CODE codeName, const std::string& defaultString) {
    auto pair = std::pair(codeName, defaultString);
    stringMap.insert(std::move(pair));
}

std::string Internationalization::getString(Internationalization::STRING_CODE codeName) {
    auto found = stringMap.find(codeName);
    return found->second;
}

std::string Internationalization::extractStringFromJSON(const std::string& key) {
    if(users_json[key] == nullptr) {
        //string not found, error, log this
        return "";
    }
    else {
        return users_json[key]["string"];
    }
}
