#include "CommandFlee.h"
#include <boost/algorithm/string.hpp>
#include <iostream> //temp for debugging

void CommandFlee::executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand) {
    auto& currentCombat = combatManager.getCombatWithPlayer(username);

    if(currentCombat.hasPlayer(username)){

        cerr << "round time not expired, queuing flee\n";
        currentCombat.queueCommand(username, fullCommand.at(0));

    } else { //player is not in a combat
        onlineUserManager.addMessageToUser(username, "You are not in combat with anyone!\n");
    }
}

void CommandFlee::executeCombatRound(const std::string& username, const std::vector<std::string>& fullCommand) {
    auto& currentCombat = combatManager.getCombatWithPlayer(username);
    auto opponentName = currentCombat.getOpponent(username);

    cerr << "round time 0, executing flee\n";
    //for now flee is guaranteed success
    combatManager.deleteCombat(username);

    onlineUserManager.addMessageToUser(username, "You fled the combat.\n");
    onlineUserManager.addMessageToUser(opponentName, username + " has fled the combat.\n");
}

std::vector<std::string> CommandFlee::reassembleCommand(std::string& fullCommand, bool& commandIsValid) {
    std::vector<std::string> processedCommand;

    //Format: flee
    boost::trim_if(fullCommand, boost::is_any_of(" \t"));

    //split by " " and compress all long spaces
    boost::split(processedCommand, fullCommand, boost::is_any_of(" \t"), boost::token_compress_on);
    commandIsValid = (processedCommand.size() == 1);

    return processedCommand;
}