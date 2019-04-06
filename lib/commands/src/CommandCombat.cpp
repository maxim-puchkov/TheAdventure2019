#include "CommandCombat.h"
#include <boost/algorithm/string.hpp>

void CommandCombat::executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand) {
    auto& currentCombat = combatManager.getCombatWithPlayer(username);
    auto& firstCommand = fullCommand.at(1);


    if(firstCommand == "print"){
        if(fullCommand.at(2) == "combats"){
            onlineUserManager.addMessageToUser(username, combatManager.printCombats());
        }else if(fullCommand.at(2) == "invites"){
            onlineUserManager.addMessageToUser(username, combatManager.printInvites());
        }
        return;
    }

    if(currentCombat.hasPlayer(username)){
        onlineUserManager.addMessageToUser(username, "One of you are already in a combat!\n");
        return;
    }

    if(firstCommand == "challenge"){
        auto userLocation = characterManager.getCharacterLocation(username);
        worldManager.spawn("jeff", userLocation);
        characterManager.addNPC("jeff");

        auto& challengedName = fullCommand.at(2);
        if(combatManager.createInvite(username, challengedName)){
            onlineUserManager.addMessageToUser(username, "Waiting for " + challengedName +" to accept challenge.\n");
            onlineUserManager.addMessageToUser(challengedName, "You were challenged to combat by " + username +".\n");
        }
        //handle npc opponent
        auto response = characterManager.getCombatReply(challengedName);
        if(response == "combat accept") { //temp until merge with actions stored in char
            combatManager.confirmInvite(challengedName);
        } else {
            onlineUserManager.addMessageToUser(username, challengedName + " says " + response + " and does not fight you.\n");
        }

    }else if(firstCommand == "join" || firstCommand == "accept"){
        if(combatManager.confirmInvite(username)){
            combatManager.removeInvite(username);
            currentCombat = combatManager.getCombatWithPlayer(username);
            auto opponentName = currentCombat.getOpponent(username);
            onlineUserManager.addMessageToUser(username, "joined combat with " + opponentName + ".\n");
            onlineUserManager.addMessageToUser(opponentName, username + " accepted your challenge.\n");
        } else {
            onlineUserManager.addMessageToUser(username, "You have not been challenged to combat.\n");
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
        commandIsValid = (processedCommand[1] == "accept");
    
    } else if(processedCommand.size() == 3) {
        //reassemble the command
        commandIsValid = (processedCommand[1] == "accept" ||
                            processedCommand[1] == "join" ||
                            processedCommand[1] == "challenge" ||
                            processedCommand[1] == "print" && (processedCommand[2] == "combats" || processedCommand[2] == "invites"));
    } else {
        commandIsValid = false;
    }

    return processedCommand;
}