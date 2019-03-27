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
       COMMAND_LOGIN,
       COMMAND_LOGOUT,
       COMMAND_CREATE_ACCOUNT,
       COMMAND_HELP,
       COMMAND_SAY,
       COMMAND_TELL,
       COMMAND_YELL,
       COMMAND_LOOK,
       COMMAND_EXAMINE,
       COMMAND_MOVE,
       COMMAND_CREATE_AVATAR,
       COMMAND_EDIT_AVATAR,
       COMMAND_CREATE_ROOM,
       COMMAND_EDIT_ROOM,
       COMMAND_USE,
       COMMAND_EQUIP,
       COMMAND_PICKUP,
       COMMAND_DROP,
       COMMAND_PUT,
       COMMAND_MINIGAME,
       COMMAND_COMBAT,
       COMMAND_ATTACK,
       COMMAND_FLEE,
       COMMAND_CAST,

       COMMAND_NOT_FOUND,
       WRONG_COMMAND_SYNTAX,
       IDLE_FOR_TOO_LONG,
       PLEASE_ENTER,
       TO_SEE_SUPPORTED_COMMANDS,
       TO_SEE_SUPPORTED_SYNTAX,

       NO_EXITS_FOUND,
       YOU_ARE_LOST,
       ROOM,
       AREA,
       OUT_OF_BOUND
       
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
    std::string getString(STRING_CODE codeName) const;
};

}
#endif
