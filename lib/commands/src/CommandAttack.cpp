#include "CommandAttack.h"
#include <boost/algorithm/string.hpp>
#include <iostream>

void CommandAttack::executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand) {
    auto& combatManager = characterManager.getCombatManager();
    auto& currentCombat = combatManager.getCombatWithPlayer(username);

    if(currentCombat.hasPlayer(username)){

        if(currentCombat.getRoundTime() <= 0){
            cerr << "round time 0, executing attack\n";
            auto attackValue = characterManager.getCharacterAttack(username);
            auto opponentName = currentCombat.getOpponent(username);
            characterManager.damageCharacter(opponentName, attackValue);
            onlineUserManager.addMessageToUser(username, "You attacked " + opponentName + " for " + std::to_string(attackValue) + ".\n");
            onlineUserManager.addMessageToUser(opponentName,
                    "You were attacked for " + std::to_string(attackValue) +
                    ".\nCurrent HP: " + std::to_string(characterManager.getCharacterHealth(opponentName)) + "\n");
        } else {
            cerr << "round time not expired, queuing attack\n";
            currentCombat.queueCommand(username, "attack");
        }

    } else { //player is not in a combat
        onlineUserManager.addMessageToUser(username, "You are not in combat with anyone!\n");
    }
}

std::vector<std::string> CommandAttack::reassembleCommand(std::string& fullCommand, bool& commandIsValid) {
    std::vector<std::string> processedCommand;

    //Format: attack
    boost::trim_if(fullCommand, boost::is_any_of(" \t"));

    //split by " " and compress all long spaces
    boost::split(processedCommand, fullCommand, boost::is_any_of(" \t"), boost::token_compress_on);
    commandIsValid = (processedCommand.size() == 1 || processedCommand.size() == 2);

    return processedCommand;
}