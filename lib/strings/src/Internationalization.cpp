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
    generateDefaultStrings(Internationalization::STRING_CODE::COMMAND_LOGOUT, "command_logout");
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

    generateDefaultStrings(Internationalization::STRING_CODE::PLEASE_LOG_IN_AGAIN, "please_log_in_again");
    generateDefaultStrings(Internationalization::STRING_CODE::PLEASE_ENTER_HELP_SYNTAX, "please_enter_help_syntax");
    generateDefaultStrings(Internationalization::STRING_CODE::AVATAR_CREATED, "avatar_created");

    generateDefaultStrings(Internationalization::STRING_CODE::EDIT_AVATAR_SHORTDESC, "edit_avatar_shortdesc");
    generateDefaultStrings(Internationalization::STRING_CODE::EDIT_AVATAR_LONGDESC, "edit_avatar_longdesc");
    generateDefaultStrings(Internationalization::STRING_CODE::EDIT_AVATAR_DESC, "edit_avatar_desc");
    generateDefaultStrings(Internationalization::STRING_CODE::AVATAR_FULLY_CUSTOMIZED, "avatar_fully_customized");
    generateDefaultStrings(Internationalization::STRING_CODE::AVATAR_UPDATED, "avatar_updated");
    generateDefaultStrings(Internationalization::STRING_CODE::ATTRIBUTE_TO_BE_UPDATED, "attribute_to_be_updated");

    generateDefaultStrings(Internationalization::STRING_CODE::TYPE_MINIGAME_EXIT, "type_minigame_exit");
    generateDefaultStrings(Internationalization::STRING_CODE::STARTED_GAME, "started_game");
    generateDefaultStrings(Internationalization::STRING_CODE::YOU_ARE_NOT_IN_ANY_MINIGAMES, "you_are_not_in_any_minigames");
    generateDefaultStrings(Internationalization::STRING_CODE::INVALID_MOVE_OR_NOT_YOUR_TURN, "invalid_move_or_not_your_turn");
    generateDefaultStrings(Internationalization::STRING_CODE::HAS_CHALLENGED_TO_MINIGAME, "has_challenged_to_minigame");
    generateDefaultStrings(Internationalization::STRING_CODE::AWAITING_RESPONSE_FROM, "awaiting_response_from");
    generateDefaultStrings(Internationalization::STRING_CODE::HAS_JOINED_THE_GAME, "has_joined_the_game");
    generateDefaultStrings(Internationalization::STRING_CODE::JOINED_GAME_WITH, "joined_game_with");
    generateDefaultStrings(Internationalization::STRING_CODE::INVITE_DOES_NOT_EXIST_OR_FULL, "invite_does_not_exist_or_full");
    generateDefaultStrings(Internationalization::STRING_CODE::YOU_LEFT_GAME, "you_left_game");

    generateDefaultStrings(Internationalization::STRING_CODE::ACCOUNT_COMMANDS, "account_commands");
    generateDefaultStrings(Internationalization::STRING_CODE::AVATAR_COMMANDS, "avatar_commands");
    generateDefaultStrings(Internationalization::STRING_CODE::CREATE_AVATAR_INSTRUCTIONS, "create_avatar_instructions");
    generateDefaultStrings(Internationalization::STRING_CODE::EDIT_AVATAR_INSTRUCTIONS, "edit_avatar_instructions");
    generateDefaultStrings(Internationalization::STRING_CODE::EDIT_AVATAR_INSTRUCTIONS_VALUE, "edit_avatar_instructions_value");
    generateDefaultStrings(Internationalization::STRING_CODE::LINE_WITH_SINGE_NEWLINE, "line_with_single_newline");
    generateDefaultStrings(Internationalization::STRING_CODE::COMMUNICATION_COMMANDS, "communication_commands");
    generateDefaultStrings(Internationalization::STRING_CODE::WORLD_INTERACTION_COMMANDS, "world_interaction_commands");
    generateDefaultStrings(Internationalization::STRING_CODE::WORLD_INTERACTION_COMMANDS_ADMIN, "world_interaction_commands_admin");
    generateDefaultStrings(Internationalization::STRING_CODE::LINE_WITH_DOUBLE_NEWLINE, "line_with_double_newline");
    generateDefaultStrings(Internationalization::STRING_CODE::INVENTORY_COMMANDS, "inventory_commands");
    generateDefaultStrings(Internationalization::STRING_CODE::MINIGAME_COMMANDS, "minigame_commands");
    generateDefaultStrings(Internationalization::STRING_CODE::COMBAT_COMMANDS, "combat_commands");
    generateDefaultStrings(Internationalization::STRING_CODE::UTILITY_COMMANDS, "utility_commands");

    generateDefaultStrings(Internationalization::STRING_CODE::ONE_OF_YOU_ALREADY_IN_COMBAT, "one_of_you_already_in_combat");
    generateDefaultStrings(Internationalization::STRING_CODE::WAITING_FOR, "waiting_for");
    generateDefaultStrings(Internationalization::STRING_CODE::TO_ACCEPT_CHALLENGE, "to_accept_challenge");
    generateDefaultStrings(Internationalization::STRING_CODE::YOU_WERE_CHALLENGED_TO_COMBAT, "you_were_challenged_to_combat");
    generateDefaultStrings(Internationalization::STRING_CODE::JOINED_COMBAT_WITH, "joined_combat_with");
    generateDefaultStrings(Internationalization::STRING_CODE::ACCEPTED_YOUR_CHALLENGE, "accepted_your_challenge");
    generateDefaultStrings(Internationalization::STRING_CODE::YOU_NOT_CHALLENGED_TO_COMBAT, "you_not_challenged_to_combat");

    generateDefaultStrings(Internationalization::STRING_CODE::MINIGAME_CHESS_WELCOME_MESSAGE, "minigame_chess_welcome_message");
    generateDefaultStrings(Internationalization::STRING_CODE::MINIGAME_CHESS_KING_NOT_DEAD, "minigame_chess_king_not_dead");
    generateDefaultStrings(Internationalization::STRING_CODE::MINIGAME_CHESS_TEAM_LOWER_WON, "minigame_chess_team_lower_won");
    generateDefaultStrings(Internationalization::STRING_CODE::MINIGAME_CHESS_TEAM_UPPER_WON, "minigame_chess_team_upper_won");

    generateDefaultStrings(Internationalization::STRING_CODE::MAKING_NEW_MATCH, "making_new_match");
    generateDefaultStrings(Internationalization::STRING_CODE::MINIGAME_LOBBY_GAMELIST, "minigame_lobby_gamelist");
    generateDefaultStrings(Internationalization::STRING_CODE::MINIGAME_LOBBY_INVITELIST, "minigame_lobby_invitelist");

    generateDefaultStrings(Internationalization::STRING_CODE::DIRECTION_NOT_FOUND, "direction_not_found");
    generateDefaultStrings(Internationalization::STRING_CODE::NONE, "none");
    generateDefaultStrings(Internationalization::STRING_CODE::NORTH, "north");
    generateDefaultStrings(Internationalization::STRING_CODE::NORTHEAST, "northeast");
    generateDefaultStrings(Internationalization::STRING_CODE::EAST, "east");
    generateDefaultStrings(Internationalization::STRING_CODE::SOUTHEAST, "southeast");
    generateDefaultStrings(Internationalization::STRING_CODE::SOUTH, "south");
    generateDefaultStrings(Internationalization::STRING_CODE::SOUTHWEST, "southwest");
    generateDefaultStrings(Internationalization::STRING_CODE::WEST, "west");
    generateDefaultStrings(Internationalization::STRING_CODE::NORTHWEST, "northwest");

    generateDefaultStrings(Internationalization::STRING_CODE::STARTING_AREA, "starting_area");
    generateDefaultStrings(Internationalization::STRING_CODE::SECRET_AREA, "secret_area");
    generateDefaultStrings(Internationalization::STRING_CODE::STARTING_AREA_WELCOME_MESSAGE, "starting_area_welcome_message");
    generateDefaultStrings(Internationalization::STRING_CODE::SECRET_AREA_WELCOME_MESSAGE, "secret_area_welcome_message");

    generateDefaultStrings(Internationalization::STRING_CODE::ROOM_UPPER_CASE, "room_upper_case");
    generateDefaultStrings(Internationalization::STRING_CODE::GOES_TO_ROOM, "goes_to_room");
    generateDefaultStrings(Internationalization::STRING_CODE::THIS_DARK_ROOM_CONTAINS_NUMBER, "this_dark_room_contains_number");
    generateDefaultStrings(Internationalization::STRING_CODE::GATE, "gate");
    generateDefaultStrings(Internationalization::STRING_CODE::THIS_SECRET_ROOM_CONTAINS_NUMBER, "this_secret_room_contains_number");
    generateDefaultStrings(Internationalization::STRING_CODE::GOES_TO_AREA, "goes_to_area");
    generateDefaultStrings(Internationalization::STRING_CODE::GOES_OUT_OF_BOUNDS, "goes_out_of_bounds");
    generateDefaultStrings(Internationalization::STRING_CODE::HIDDEN_PASSAGE, "hidden_passage");
    generateDefaultStrings(Internationalization::STRING_CODE::SOUTH_GATE, "south_gate");
    generateDefaultStrings(Internationalization::STRING_CODE::WEST_GATE, "west_gate");
    generateDefaultStrings(Internationalization::STRING_CODE::EAST_GATE, "east_gate");
    generateDefaultStrings(Internationalization::STRING_CODE::NORTH_GATE, "north_gate");

    generateDefaultStrings(Internationalization::STRING_CODE::LOCATION_COORDINATES, "location_coordinates");

    generateDefaultStrings(Internationalization::STRING_CODE::INVALID_USERNAME_CREATE_MESSAGE, "invalid_username_create_message");

    generateDefaultStrings(Internationalization::STRING_CODE::NPC_DOES_NOT_EXIST, "npc_does_not_exist");
    generateDefaultStrings(Internationalization::STRING_CODE::EDITED_NPC_NAME, "edited_npc_name");
    generateDefaultStrings(Internationalization::STRING_CODE::EDITED_NPC_DESCRIPTION, "edited_npc_description");
    generateDefaultStrings(Internationalization::STRING_CODE::DELETED_NPC, "deleted_npc");
    generateDefaultStrings(Internationalization::STRING_CODE::NPC_IN_ROOM, "npc_in_room");

    generateDefaultStrings(Internationalization::STRING_CODE::USERS_IN_ROOM_ARE, "users_in_room_are");
    generateDefaultStrings(Internationalization::STRING_CODE::EXIT_TO, "exit_to");

    generateDefaultStrings(Internationalization::STRING_CODE::THIS_EXIT_HAS_NO_DESC, "this_exit_has_no_desc");

    generateDefaultStrings(Internationalization::STRING_CODE::CHALLENGE, "challenge");
    generateDefaultStrings(Internationalization::STRING_CODE::ACCEPT, "accept");
    generateDefaultStrings(Internationalization::STRING_CODE::JOIN, "join");
    generateDefaultStrings(Internationalization::STRING_CODE::NPC, "NPC");
    generateDefaultStrings(Internationalization::STRING_CODE::DESC, "desc");
    generateDefaultStrings(Internationalization::STRING_CODE::DELETE, "delete");
    generateDefaultStrings(Internationalization::STRING_CODE::EXIT, "exit");
    generateDefaultStrings(Internationalization::STRING_CODE::DEFAULT_NAME, "default_name");
    generateDefaultStrings(Internationalization::STRING_CODE::NO_ROOM_NAME, "no_room_name");
    generateDefaultStrings(Internationalization::STRING_CODE::ADMIN_EXIT, "admin_exit");
    generateDefaultStrings(Internationalization::STRING_CODE::NPCS, "NPCS");

    generateDefaultStrings(Internationalization::STRING_CODE::ACCOUNT, "account");
    generateDefaultStrings(Internationalization::STRING_CODE::AVATAR_LOWER, "avatar_lower");
    generateDefaultStrings(Internationalization::STRING_CODE::COMMUNICATION, "communication");
    generateDefaultStrings(Internationalization::STRING_CODE::WORLD_INTERACTION, "world_interaction");
    generateDefaultStrings(Internationalization::STRING_CODE::INVENTORY, "inventory");
    generateDefaultStrings(Internationalization::STRING_CODE::WORLD, "WORLD");

    generateDefaultStrings(Internationalization::STRING_CODE::QUIT, "quit");
    generateDefaultStrings(Internationalization::STRING_CODE::PRINT, "print");
    generateDefaultStrings(Internationalization::STRING_CODE::GAMES, "games");
    generateDefaultStrings(Internationalization::STRING_CODE::INVITES, "invites");
    generateDefaultStrings(Internationalization::STRING_CODE::START, "start");
    generateDefaultStrings(Internationalization::STRING_CODE::INVITE, "invites");
    generateDefaultStrings(Internationalization::STRING_CODE::INVALID_MESSAGE, "invalid_message");
    generateDefaultStrings(Internationalization::STRING_CODE::READ, "read");
    generateDefaultStrings(Internationalization::STRING_CODE::ITEMS_NOW_WORKING, "items_now_working");
    generateDefaultStrings(Internationalization::STRING_CODE::VIEW_ALL_GAMES, "view_all_games");
    generateDefaultStrings(Internationalization::STRING_CODE::SPECTATE, "spectate");
    generateDefaultStrings(Internationalization::STRING_CODE::CURRENTLY_SPECTATING, "currently_spectating");
    generateDefaultStrings(Internationalization::STRING_CODE::COULDNT_FIND_GAME_WITH, "couldnt_find_game_with");
    generateDefaultStrings(Internationalization::STRING_CODE::PLAYING, "playing");

    generateDefaultStrings(Internationalization::STRING_CODE::CHARACTERS_JSON_FILE_NAME, "characters_json_file_name");
    generateDefaultStrings(Internationalization::STRING_CODE::SHORTDESC, "shortdesc");
    generateDefaultStrings(Internationalization::STRING_CODE::LONGDESC, "longdesc");
    generateDefaultStrings(Internationalization::STRING_CODE::DESCRIPTION, "description");
    generateDefaultStrings(Internationalization::STRING_CODE::KEYWORDS, "keywords");
    generateDefaultStrings(Internationalization::STRING_CODE::CHARACTER_FIRST_TIME_SETUP, "character_first_time_setup");
}

/*
INTERNATIONALIZATION COPY AND PASTE STUFF:

            using internationalization::Internationalization;

            generateDefaultStrings(Internationalization::STRING_CODE::, "");

            "":{"string": ""},

            stringManager.getString(Internationalization::STRING_CODE::)
*/

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
