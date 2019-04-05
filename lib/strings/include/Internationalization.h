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
       COMMAND_CREATE_ITEM,
       COMMAND_DELETE_ROOM,
       COMMAND_TAKE,

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

       PLEASE_LOG_IN_AGAIN,
       PLEASE_ENTER_HELP_SYNTAX,
       AVATAR_CREATED,

       EDIT_AVATAR_SHORTDESC,
       EDIT_AVATAR_LONGDESC,
       EDIT_AVATAR_DESC,
       AVATAR_FULLY_CUSTOMIZED,
       AVATAR_UPDATED,
       ATTRIBUTE_TO_BE_UPDATED,

       TYPE_MINIGAME_EXIT,
       STARTED_GAME,
       YOU_ARE_NOT_IN_ANY_MINIGAMES,
       INVALID_MOVE_OR_NOT_YOUR_TURN,
       HAS_CHALLENGED_TO_MINIGAME,
       AWAITING_RESPONSE_FROM,
       HAS_JOINED_THE_GAME,
       JOINED_GAME_WITH,
       INVITE_DOES_NOT_EXIST_OR_FULL,
       YOU_LEFT_GAME,

       ACCOUNT_COMMANDS,
       AVATAR_COMMANDS,
       CREATE_AVATAR_INSTRUCTIONS,
       EDIT_AVATAR_INSTRUCTIONS,
       EDIT_AVATAR_INSTRUCTIONS_VALUE,
       LINE_WITH_SINGE_NEWLINE,
       COMMUNICATION_COMMANDS,
       WORLD_INTERACTION_COMMANDS,
       WORLD_INTERACTION_COMMANDS_ADMIN,
       LINE_WITH_DOUBLE_NEWLINE,
       INVENTORY_COMMANDS,
       MINIGAME_COMMANDS,
       COMBAT_COMMANDS,
       UTILITY_COMMANDS,

       ONE_OF_YOU_ALREADY_IN_COMBAT,
       WAITING_FOR,
       TO_ACCEPT_CHALLENGE,
       YOU_WERE_CHALLENGED_TO_COMBAT,
       JOINED_COMBAT_WITH,
       ACCEPTED_YOUR_CHALLENGE,
       YOU_NOT_CHALLENGED_TO_COMBAT,

       MINIGAME_CHESS_WELCOME_MESSAGE,
       MINIGAME_CHESS_KING_NOT_DEAD,
       MINIGAME_CHESS_TEAM_LOWER_WON,
       MINIGAME_CHESS_TEAM_UPPER_WON,

       MAKING_NEW_MATCH,
       MINIGAME_LOBBY_GAMELIST,
       MINIGAME_LOBBY_INVITELIST,

       DIRECTION_NOT_FOUND,
       NONE,
       NORTH,
       NORTHEAST,
       EAST,
       SOUTHEAST,
       SOUTH,
       SOUTHWEST,
       WEST,
       NORTHWEST,

       STARTING_AREA,
       SECRET_AREA,
       STARTING_AREA_WELCOME_MESSAGE,
       SECRET_AREA_WELCOME_MESSAGE,

       ROOM_UPPER_CASE,
       GOES_TO_ROOM,
       THIS_DARK_ROOM_CONTAINS_NUMBER,
       GATE,
       THIS_SECRET_ROOM_CONTAINS_NUMBER,
       GOES_TO_AREA,
       GOES_OUT_OF_BOUNDS,
       HIDDEN_PASSAGE,
       SOUTH_GATE,
       WEST_GATE,
       EAST_GATE,
       NORTH_GATE,

       LOCATION_COORDINATES,

       INVALID_USERNAME_CREATE_MESSAGE,

       NPC_DOES_NOT_EXIST,
       EDITED_NPC_NAME,
       EDITED_NPC_DESCRIPTION,
       DELETED_NPC,
       NPC_IN_ROOM,

       USERS_IN_ROOM_ARE,
       EXIT_TO,

       THIS_EXIT_HAS_NO_DESC,

       CHALLENGE,
       ACCEPT,
       JOIN,
       NPC,
       DESC,
       DELETE,
       EXIT,
       DEFAULT_NAME,
       NO_ROOM_NAME,
       ADMIN_EXIT,
       NPCS,

       ACCOUNT,
       AVATAR_LOWER,
       COMMUNICATION,
       WORLD_INTERACTION,
       INVENTORY,
       WORLD,

       QUIT,
       PRINT,
       GAMES,
       INVITES,
       START,
       INVITE,
       INVALID_MESSAGE,
       READ,
       ITEMS_NOW_WORKING,
       VIEW_ALL_GAMES,
       SPECTATE,
       CURRENTLY_SPECTATING,
       COULDNT_FIND_GAME_WITH,
       PLAYING,

       DELETING_ROOM_YOU_ARE_IN,
       DELETING_ROOM_MESSAGE,
       IN_AREA,
       INVALID_ROOM_ENTER,

       CHARACTERS_JSON_FILE_NAME,
       SHORTDESC,
       LONGDESC,
       DESCRIPTION,
       KEYWORDS,
       CHARACTER_FIRST_TIME_SETUP
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
