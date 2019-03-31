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
    
    generateDefaultStrings(Internationalization::STRING_CODE::COMMAND_LOGIN, "command_login");
    generateDefaultStrings(Internationalization::STRING_CODE::COMMAND_CREATE_ACCOUNT, "command_create_account");
    generateDefaultStrings(Internationalization::STRING_CODE::COMMAND_HELP, "command_help");
    generateDefaultStrings(Internationalization::STRING_CODE::COMMAND_SAY, "command_say");
    generateDefaultStrings(Internationalization::STRING_CODE::COMMAND_TELL, "command_tell");
    generateDefaultStrings(Internationalization::STRING_CODE::COMMAND_YELL, "command_yell");
    generateDefaultStrings(Internationalization::STRING_CODE::COMMAND_LOOK, "command_look");
    generateDefaultStrings(Internationalization::STRING_CODE::COMMAND_EXAMINE, "command_examine");
    generateDefaultStrings(Internationalization::STRING_CODE::COMMAND_MOVE, "command_move");
    generateDefaultStrings(Internationalization::STRING_CODE::COMMAND_CREATE_AVATAR, "command_create_avatar");
    generateDefaultStrings(Internationalization::STRING_CODE::COMMAND_EDIT_AVATAR, "command_edit_avatar");
    generateDefaultStrings(Internationalization::STRING_CODE::COMMAND_CREATE_ROOM, "command_create_room");
    generateDefaultStrings(Internationalization::STRING_CODE::COMMAND_EDIT_ROOM, "command_edit_room");
    generateDefaultStrings(Internationalization::STRING_CODE::COMMAND_USE, "command_use");
    generateDefaultStrings(Internationalization::STRING_CODE::COMMAND_EQUIP, "command_equip");
    generateDefaultStrings(Internationalization::STRING_CODE::COMMAND_PICKUP, "command_pickup");
    generateDefaultStrings(Internationalization::STRING_CODE::COMMAND_DROP, "command_drop");
    generateDefaultStrings(Internationalization::STRING_CODE::COMMAND_PUT, "command_put");
    generateDefaultStrings(Internationalization::STRING_CODE::COMMAND_MINIGAME, "command_minigame");
    generateDefaultStrings(Internationalization::STRING_CODE::COMMAND_COMBAT, "command_combat");
    generateDefaultStrings(Internationalization::STRING_CODE::COMMAND_ATTACK, "command_attack");
    generateDefaultStrings(Internationalization::STRING_CODE::COMMAND_FLEE, "command_flee");
    generateDefaultStrings(Internationalization::STRING_CODE::COMMAND_CAST, "command_cast");

    generateDefaultStrings(Internationalization::STRING_CODE::COMMAND_NOT_FOUND, "command_not_found");
    generateDefaultStrings(Internationalization::STRING_CODE::WRONG_COMMAND_SYNTAX, "wrong_command_syntax");
    generateDefaultStrings(Internationalization::STRING_CODE::NAME, "name");
    generateDefaultStrings(Internationalization::STRING_CODE::YOU, "you");
    generateDefaultStrings(Internationalization::STRING_CODE::TOLD, "told");
    generateDefaultStrings(Internationalization::STRING_CODE::SAID, "said");
    generateDefaultStrings(Internationalization::STRING_CODE::YELLED, "yelled");
    
    generateDefaultStrings(Internationalization::STRING_CODE::PLEASE_ENTER, "please_enter");
    generateDefaultStrings(Internationalization::STRING_CODE::TO_SEE_SUPPORTED_COMMANDS, "to_see_supported_commands");
    generateDefaultStrings(Internationalization::STRING_CODE::TO_SEE_SUPPORTED_SYNTAX, "to_see_supported_syntax");
    generateDefaultStrings(Internationalization::STRING_CODE::TO_SEE_MORE_INFO, "to_see_more_info");
    generateDefaultStrings(Internationalization::STRING_CODE::TO_CREATE, "to_create");
    
    generateDefaultStrings(Internationalization::STRING_CODE::NO_EXITS_FOUND, "no_exits_found");
    generateDefaultStrings(Internationalization::STRING_CODE::YOU_ARE_LOST, "you_are_lost");
    generateDefaultStrings(Internationalization::STRING_CODE::ROOM, "room");
    generateDefaultStrings(Internationalization::STRING_CODE::AREA, "area");
    generateDefaultStrings(Internationalization::STRING_CODE::EXITS, "exits");
    generateDefaultStrings(Internationalization::STRING_CODE::OUT_OF_BOUND, "out_of_bound");
    generateDefaultStrings(Internationalization::STRING_CODE::CURRENT_LOCATION, "current_location");
    
    generateDefaultStrings(Internationalization::STRING_CODE::PLEASE_CUSTOMIZE_AVATAR_FIRST, "please_customize_avatar_first");
    generateDefaultStrings(Internationalization::STRING_CODE::AVATAR, "avatar");
    generateDefaultStrings(Internationalization::STRING_CODE::AVATAR_IS_REQUIRED, "avatar_is_required");
      
    generateDefaultStrings(Internationalization::STRING_CODE::USER_NOT_ONLINE, "user_not_online");
    generateDefaultStrings(Internationalization::STRING_CODE::INVALID_USERNAME, "invalid_username");
    generateDefaultStrings(Internationalization::STRING_CODE::ACCOUNT_CREATED, "account_created");
    generateDefaultStrings(Internationalization::STRING_CODE::IDLE_FOR_TOO_LONG, "idle_for_too_long");
    generateDefaultStrings(Internationalization::STRING_CODE::NOW_LOGGED_IN, "now_logged_in");
    generateDefaultStrings(Internationalization::STRING_CODE::NOW_LOGGED_OUT, "now_logged_out");
    generateDefaultStrings(Internationalization::STRING_CODE::USERNAME_NOT_FOUND, "username_not_found");
    generateDefaultStrings(Internationalization::STRING_CODE::ALREADY_LOGGED_IN, "already_logged_in");
    generateDefaultStrings(Internationalization::STRING_CODE::NOT_LOGGED_IN, "not_logged_in");

    generateDefaultStrings(Internationalization::STRING_CODE::ERROR, "error");
    generateDefaultStrings(Internationalization::STRING_CODE::PLEASE_TRY_AGAIN, "please_try_again");
    generateDefaultStrings(Internationalization::STRING_CODE::FAILED_TO_FIND_WITH_NAME, "failed_to_find_with_name");

    generateDefaultStrings(Internationalization::STRING_CODE::ROUND_TIME_START, "round_time_start");
    generateDefaultStrings(Internationalization::STRING_CODE::YOU_ATTACKED, "you_attacked");
    generateDefaultStrings(Internationalization::STRING_CODE::FOR, "for");
    generateDefaultStrings(Internationalization::STRING_CODE::YOU_WERE_ATTACKED_FOR, "you_were_attacked_for");
    generateDefaultStrings(Internationalization::STRING_CODE::CURRENT_HP, "current_hp");
    generateDefaultStrings(Internationalization::STRING_CODE::ROUND_TIME_NOT_EXPIRING, "round_time_not_expiring");
    generateDefaultStrings(Internationalization::STRING_CODE::NOT_IN_COMBAT, "not_in_combat");

    generateDefaultStrings(Internationalization::STRING_CODE::ONE_OF_YOU_ALREADY_IN_COMBAT, "one_of_you_already_in_combat");
    generateDefaultStrings(Internationalization::STRING_CODE::WAITING_FOR, "waiting_for");
    generateDefaultStrings(Internationalization::STRING_CODE::TO_ACCEPT_CHALLENGE, "to_accept_challenge");
    generateDefaultStrings(Internationalization::STRING_CODE::YOU_WERE_CHALLENGED_TO_COMBAT, "you_were_challenged_to_combat");
    generateDefaultStrings(Internationalization::STRING_CODE::JOINED_COMBAT_WITH, "joined_combat_with");
    generateDefaultStrings(Internationalization::STRING_CODE::ACCEPTED_YOUR_CHALLENGE, "accepted_your_challenge");
    generateDefaultStrings(Internationalization::STRING_CODE::YOU_NOT_CHALLENGED_TO_COMBAT, "you_not_challenged_to_combat");
}

void Internationalization::generateDefaultStrings(Internationalization::STRING_CODE codeName, const std::string& defaultString) {
    auto pair = std::pair(codeName, defaultString);
    stringMap.insert(std::move(pair));
}

std::string Internationalization::getString(Internationalization::STRING_CODE codeName) const {
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
