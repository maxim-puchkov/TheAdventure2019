#include "CommandHelp.h"
#include <boost/algorithm/string.hpp>

using internationalization::Internationalization;

std::string CommandHelp::executePromptReply(const std::string& connectionID, const std::vector<std::string>& fullCommand) {
    //TODO: check user's role to print out appropriate text
    //test role
    auto username = onlineUserManager.getUsernameFromConnectionID(connectionID);
    auto userRole = onlineUserManager.getUserRole(username);

    std::stringstream answer;

    if(fullCommand.size() == 1) {
        answer << printUtilityCommands(userRole);
    } else {
        if(fullCommand[1] == stringManager.getString(Internationalization::STRING_CODE::ACCOUNT)) {
            answer << printAccountCommands(userRole);
        } else if (fullCommand[1] == stringManager.getString(Internationalization::STRING_CODE::AVATAR_LOWER)) {
            answer << printAvatarCommands(userRole);
        } else if (fullCommand[1] == stringManager.getString(Internationalization::STRING_CODE::COMMUNICATION)) {
            answer << printCommunicationCommands(userRole);
        } else if (fullCommand[1] == stringManager.getString(Internationalization::STRING_CODE::WORLD_INTERACTION)) {
            answer << printWorldInteractionCommands(userRole);
        } else if (fullCommand[1] == stringManager.getString(Internationalization::STRING_CODE::INVENTORY)) {
            answer << printInventoryCommands(userRole);
        } else if (fullCommand[1] == stringManager.getString(Internationalization::STRING_CODE::COMMAND_MINIGAME)) {
            answer << printMinigameCommands(userRole);
        } else if (fullCommand[1] == stringManager.getString(Internationalization::STRING_CODE::COMMAND_COMBAT)) {
            answer << printCombatCommands(userRole);
        } else {
            answer << (stringManager.getString(Internationalization::STRING_CODE::COMMAND_NOT_FOUND),
                       " ",
                       stringManager.getString(Internationalization::STRING_CODE::PLEASE_ENTER_HELP_SYNTAX));
        }
    }
    return answer.str();
}

std::string CommandHelp::printAccountCommands(OnlineUserManager::USER_CODE userRole) {
    std::stringstream answer;
    answer << stringManager.getString(Internationalization::STRING_CODE::ACCOUNT_COMMANDS);
    return answer.str();
}

std::string CommandHelp::printAvatarCommands(OnlineUserManager::USER_CODE userRole) {
    //needs enum in User
    auto admin = OnlineUserManager::USER_CODE::USER_ADMIN;

    std::stringstream answer;
    answer << stringManager.getString(Internationalization::STRING_CODE::AVATAR_COMMANDS);
    if(userRole == admin) {
        answer << stringManager.getString(Internationalization::STRING_CODE::CREATE_AVATAR_INSTRUCTIONS);
    }
    answer << stringManager.getString(Internationalization::STRING_CODE::EDIT_AVATAR_INSTRUCTIONS);
    if(userRole == admin) {
        answer << stringManager.getString(Internationalization::STRING_CODE::EDIT_AVATAR_INSTRUCTIONS_VALUE);
    }
    answer << stringManager.getString(Internationalization::STRING_CODE::LINE_WITH_SINGE_NEWLINE);
    return answer.str();
}

std::string CommandHelp::printCommunicationCommands(OnlineUserManager::USER_CODE userRole) {
    std::stringstream answer;
    answer << stringManager.getString(Internationalization::STRING_CODE::COMMUNICATION_COMMANDS);
    return answer.str();
}

std::string CommandHelp::printWorldInteractionCommands(OnlineUserManager::USER_CODE userRole) {
    //needs enum in User
    auto admin = OnlineUserManager::USER_CODE::USER_ADMIN;

    std::stringstream answer;
    answer << stringManager.getString(Internationalization::STRING_CODE::WORLD_INTERACTION_COMMANDS);
    if(userRole == admin) {
        answer << stringManager.getString(Internationalization::STRING_CODE::WORLD_INTERACTION_COMMANDS_ADMIN);
    }
    answer << stringManager.getString(Internationalization::STRING_CODE::LINE_WITH_DOUBLE_NEWLINE);
    return answer.str();
}

std::string CommandHelp::printInventoryCommands(OnlineUserManager::USER_CODE userRole) {
    std::stringstream answer;
    answer << stringManager.getString(Internationalization::STRING_CODE::INVENTORY_COMMANDS); 
    return answer.str();
}

std::string CommandHelp::printMinigameCommands(OnlineUserManager::USER_CODE userRole) {
    std::stringstream answer;
    answer << stringManager.getString(Internationalization::STRING_CODE::MINIGAME_COMMANDS); 
    return answer.str();
}

std::string CommandHelp::printCombatCommands(OnlineUserManager::USER_CODE userRole) {
    std::stringstream answer;
    answer << stringManager.getString(Internationalization::STRING_CODE::COMBAT_COMMANDS); 
    return answer.str();
}

std::string CommandHelp::printUtilityCommands(OnlineUserManager::USER_CODE userRole) {
    std::stringstream answer;
    answer << stringManager.getString(Internationalization::STRING_CODE::UTILITY_COMMANDS);
    return answer.str();
}

std::vector<std::string> CommandHelp::reassembleCommand(std::string& fullCommand, bool& commandIsValid) {
    std::vector<std::string> processedCommand;

    //Format: help
    boost::trim_if(fullCommand, boost::is_any_of(" \t"));
    boost::to_lower(fullCommand);

    //split by " " and compress all long spaces
    boost::split(processedCommand, fullCommand, boost::is_any_of(" \t"), boost::token_compress_on);
    commandIsValid = (processedCommand.size() == 1 || processedCommand.size() == 2);
   
    return processedCommand;
}