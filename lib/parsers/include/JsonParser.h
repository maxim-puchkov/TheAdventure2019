#ifndef JSON_PARSER_H
#define JSON_PARSER_H

#include "json.hpp"
using nlohmann::json;

class JsonParser{
    private:
        json users_json;

    public:
        json processJSON(const std::string&);
        void saveJSON(json , const std::string&);
        std::string removeQuotes(std::string str);
        std::string json2string(json j);
        std::vector<std::string> json2Vector(json j);
};


#endif