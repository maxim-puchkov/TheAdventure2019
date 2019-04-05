#include "JsonParser.h"
#include <fstream>

using namespace std;

json JsonParser::processJSON(const std::string& filePath){

    char char_filePath[filePath.length()+1];
    strcpy(char_filePath, filePath.c_str());
    json users_json;
    try{
        std::ifstream users_file(char_filePath);
        users_json = json::parse(users_file);
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



std::string JsonParser::removeQuotes( std::string str){
    return str.substr(1, str.size() - 2);
}

std::string JsonParser::json2string(json j){
    std::string retStr;
    for(auto line : j){
        retStr += (removeQuotes(line.dump()) + "\n");
    }
    return retStr;
}

std::vector<std::string> JsonParser::json2Vector(json j){
    std:vector<std::string> strVec;
    for(auto line : j){
        strVec.push_back(removeQuotes(line.dump()));
    }
    return strVec;
}

std::vector<std::string> JsonParser::getFileNamesInPath(const char* path){
    
    std::vector<std::string> fileNames;
    DIR* dirp = opendir(path);
    struct dirent * dp = readdir(dirp); dp = readdir(dirp);

    while ((dp = readdir(dirp)) != NULL) {

        std::string fileName(dp->d_name);
        fileNames.push_back(dp->d_name);
    }
    closedir(dirp);
    return fileNames;
}
