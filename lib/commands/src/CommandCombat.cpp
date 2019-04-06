#include "CommandCombat.h"
#include <boost/algorithm/string.hpp>

using internationalization::Internationalization;

void CommandCombat::executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand) {
    auto& currentCombat = combatManager.getCombatWithPlayer(username);
    auto& firstCommand = fullCommand.at(1);

    if(currentCombat.hasPlayer(username)){
        onlineUserManager.addMessageToUser(
            username,
            stringManager.getString(Internationalization::STRING_CODE::ONE_OF_YOU_ALREADY_IN_COMBAT)
        );
        return;
    }

    if(firstCommand == stringManager.getString(Internationalization::STRING_CODE::CHALLENGE)){
        auto userLocation = characterManager.getCharacterLocation(username);
        auto& challengedName = fullCommand.at(2);
        if(combatManager.createInvite(username, challengedName)){
            onlineUserManager.addMessageToUser(
                username,
                stringManager.getString(Internationalization::STRING_CODE::WAITING_FOR) +
                challengedName +
                stringManager.getString(Internationalization::STRING_CODE::TO_ACCEPT_CHALLENGE)
            );
            onlineUserManager.addMessageToUser(
                challengedName,
                stringManager.getString(Internationalization::STRING_CODE::YOU_WERE_CHALLENGED_TO_COMBAT) +
                username +
                ".\n"
            );
        }
        //handle npc opponent
        auto response = characterManager.getCombatReply(challengedName);
        if(response == "combat accept") { //temp until merge with actions stored in char
            combatManager.confirmInvite(challengedName);
        } else {
            onlineUserManager.addMessageToUser(username, challengedName + " says " + response + " and does not fight you.\n");
        }

    }else if(
        firstCommand == stringManager.getString(Internationalization::STRING_CODE::JOIN) ||
        firstCommand == stringManager.getString(Internationalization::STRING_CODE::ACCEPT)
    ){
        if(combatManager.confirmInvite(username)){
            combatManager.removeInvite(username);
            currentCombat = combatManager.getCombatWithPlayer(username);
            auto opponentName = currentCombat.getOpponent(username);
            onlineUserManager.addMessageToUser(
                username,
                stringManager.getString(Internationalization::STRING_CODE::JOINED_COMBAT_WITH) +
                opponentName +
                ".\n"
            );
            onlineUserManager.addMessageToUser(
                opponentName,
                username +
                stringManager.getString(Internationalization::STRING_CODE::ACCEPTED_YOUR_CHALLENGE)
            );
        } else {
            onlineUserManager.addMessageToUser(
                username,
                stringManager.getString(Internationalization::STRING_CODE::YOU_NOT_CHALLENGED_TO_COMBAT)
            );
        }
    }
}

std::vector<std::string> CommandCombat::reassembleCommand(std::string& fullCommand, bool& commandIsValid) {
    std::vector<std::string> processedCommand;

    //Format: combat challenge [username]
    //Format: combat accept
    //Format: combat accept [username]
    //Format: combat join [username]
    boost::trim_if(fullCommand, boost::is_any_of(" \t"));

    //split by " "
    boost::split(processedCommand, fullCommand, boost::is_any_of(" \t"), boost::token_compress_on);        
    if(processedCommand.size() == 2) {
        commandIsValid = (processedCommand[1] == stringManager.getString(Internationalization::STRING_CODE::ACCEPT));
    
    } else if(processedCommand.size() == 3) {
        //reassemble the command
        commandIsValid = (processedCommand[1] == stringManager.getString(Internationalization::STRING_CODE::ACCEPT) ||
                            processedCommand[1] == stringManager.getString(Internationalization::STRING_CODE::JOIN) ||
                            processedCommand[1] == stringManager.getString(Internationalization::STRING_CODE::CHALLENGE));
    } else {
        commandIsValid = false;
    }

    return processedCommand;
}