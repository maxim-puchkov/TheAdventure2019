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
       NAME,
       YOU,
       SAID,
       TOLD,
       YELLED,
       
       PLEASE_ENTER,
       TO_SEE_SUPPORTED_COMMANDS,
       TO_SEE_SUPPORTED_SYNTAX,
       TO_SEE_MORE_INFO,
       TO_CREATE,

       NO_EXITS_FOUND,
       YOU_ARE_LOST,
       ROOM,
       AREA,
       EXITS,
       OUT_OF_BOUND,
       CURRENT_LOCATION,

       USER_NOT_ONLINE,
       INVALID_USERNAME,
       ACCOUNT_CREATED,
       IDLE_FOR_TOO_LONG,
       NOW_LOGGED_IN,
       NOW_LOGGED_OUT,
       USERNAME_NOT_FOUND,
       ALREADY_LOGGED_IN,
       NOT_LOGGED_IN,

       PLEASE_CUSTOMIZE_AVATAR_FIRST,
       AVATAR_IS_REQUIRED,
       AVATAR,
       
       ERROR,
       PLEASE_TRY_AGAIN,
       FAILED_TO_FIND_WITH_NAME,

       ROUND_TIME_START,
       YOU_ATTACKED,
       FOR,
       YOU_WERE_ATTACKED_FOR,
       CURRENT_HP,
       ROUND_TIME_NOT_EXPIRING,
       NOT_IN_COMBAT,

       ONE_OF_YOU_ALREADY_IN_COMBAT,
       WAITING_FOR,
       TO_ACCEPT_CHALLENGE,
       YOU_WERE_CHALLENGED_TO_COMBAT,
       JOINED_COMBAT_WITH,
       ACCEPTED_YOUR_CHALLENGE,
       YOU_NOT_CHALLENGED_TO_COMBAT


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
