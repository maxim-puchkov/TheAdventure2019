#ifndef INTERNATIONALIZATION_H
#define INTERNATIONALIZATION_H

#include "JsonParser.h"
#include <fstream>

#include <string>
#include <unordered_map>

using nlohmann::json;

namespace internationalization {
class Internationalization {
  public:
    enum class STRING_CODE : uint8_t {
       COMMAND_NOT_FOUND,
       WRONG_COMMAND_SYNTAX
    };

  private:
    JsonParser jsonParser;
    json users_json;
    std::string json_filePath = "../adventure2019/data/strings.json";
    std::unordered_map<STRING_CODE, std::string> stringMap;

    void bindEnumToKey();
    void loadStringsToMap();
    void generateDefaultStrings(STRING_CODE codeName, const std::string& defaultString);
    std::string extractStringFromJSON(const std::string& key);
  public:
    Internationalization();
    std::string getString(STRING_CODE codeName);
};

}
#endif
