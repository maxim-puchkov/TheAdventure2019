#include "CommandAttack.h"
#include <boost/algorithm/string.hpp>
#include <iostream>

using internationalization::Internationalization;

void CommandAttack::executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand) {
    auto& combatManager = characterManager.getCombatManager();
    auto& currentCombat = combatManager.getCombatWithPlayer(username);

    if(currentCombat.hasPlayer(username)){

        if(currentCombat.getRoundTime() <= 0){
            cerr << stringManager.getString(Internationalization::STRING_CODE::ROUND_TIME_START);
            auto attackValue = characterManager.getCharacterAttack(username);
            auto opponentName = currentCombat.getOpponent(username);
            characterManager.damageCharacter(opponentName, attackValue);
            onlineUserManager.addMessageToUser(username,
                                               stringManager.getString(Internationalization::STRING_CODE::YOU_ATTACKED) + 
                                               opponentName + 
                                               stringManager.getString(Internationalization::STRING_CODE::FOR) + 
                                               std::to_string(attackValue) + 
                                               ".\n");
            onlineUserManager.addMessageToUser(opponentName,
                                               stringManager.getString(Internationalization::STRING_CODE::YOU_WERE_ATTACKED_FOR) + 
                                               std::to_string(attackValue) +
                                               stringManager.getString(Internationalization::STRING_CODE::CURRENT_HP) + 
                                               std::to_string(characterManager.getCharacterHealth(opponentName)) + 
                                               "\n");
        } else {
            cerr << stringManager.getString(Internationalization::STRING_CODE::ROUND_TIME_NOT_EXPIRING);
            currentCombat.queueCommand(username, "attack");
        }

    } else { //player is not in a combat
        onlineUserManager.addMessageToUser(username, stringManager.getString(Internationalization::STRING_CODE::NOT_IN_COMBAT));
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