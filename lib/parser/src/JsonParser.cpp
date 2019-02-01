#include "JsonParser.h"
#include <fstream>

using namespace std;

json JsonParser::processJSON(const std::string& filePath){

    char char_filePath[filePath.length()+1];
    strcpy(char_filePath, filePath.c_str());

    try{
        std::ifstream users_file(char_filePath);
        json users_json = json::parse(users_file);
    }
    catch(nlohmann::detail::parse_error e){
        return nullptr;
    }
    return users_json;
}

void JsonParser::saveJSON(json j, const std::string& filePath){

    char char_filePath[filePath.length()+1];
    strcpy(char_filePath, filePath.c_str());

    std::ofstream file(char_filePath);
    file << j;
}

char* string2charArray(std::string& str){
    char char_filePath[str.length()+1];
    strcpy(char_filePath, str.c_str());
    return char_filePath;
}