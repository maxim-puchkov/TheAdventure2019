#include "CommandAttack.h"
#include <boost/algorithm/string.hpp>
#include <iostream>

void CommandAttack::executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand) {
    auto& currentCombat = combatManager.getCombatWithPlayer(username);

    if(currentCombat.hasPlayer(username)){

        cerr << "round time not expired, queuing attack\n";
        currentCombat.queueCommand(username, fullCommand);
        //handle npc opponent. does nothing if character is user controlled
        auto opponentName = currentCombat.getOpponent(username);
        auto opponentResponse = characterManager.getAttackReply(opponentName);
        //if response is empty then non-ai opponent
        if(!opponentResponse.empty()) {
            onlineUserManager.addMessageToUser(username, opponentName + " prepares a(n) " + opponentResponse + "\n");
            std::vector<std::string> opponentCommand;
            opponentCommand.push_back(opponentResponse);
            currentCombat.queueCommand(opponentName, opponentCommand);
        }


    } else { //player is not in a combat
        onlineUserManager.addMessageToUser(username, "You are not in combat with anyone!\n");
    }
}

void CommandAttack::executeCombatRound(const std::string& username, const std::vector<std::string>& fullCommand) {
    auto& currentCombat = combatManager.getCombatWithPlayer(username);

    cerr << "round time 0, executing attack\n";
    auto attackValue = characterManager.getCharacterAttack(username);
    auto opponentName = currentCombat.getOpponent(username);

    characterManager.damageCharacter(opponentName, attackValue);

    //check character hp
    //kill/respawn character

    onlineUserManager.addMessageToUser(username, "You attacked " + opponentName + " for " + std::to_string(attackValue) + ".\n");
    onlineUserManager.addMessageToUser(opponentName,
                                       "You were attacked for " + std::to_string(attackValue) +
                                       ".\nCurrent HP: " + std::to_string(characterManager.getCharacterHealth(opponentName)) + "\n");
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