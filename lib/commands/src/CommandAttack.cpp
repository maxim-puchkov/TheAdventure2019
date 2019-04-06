#include "CommandAttack.h"
#include <boost/algorithm/string.hpp>
#include <iostream>

using internationalization::Internationalization;

void CommandAttack::executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand) {
    auto& currentCombat = combatManager.getCombatWithPlayer(username);

    if(currentCombat.hasPlayer(username)){

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
        onlineUserManager.addMessageToUser(username, stringManager.getString(Internationalization::STRING_CODE::NOT_IN_COMBAT));
    }
}

void CommandAttack::executeCombatRound(const std::string& username, const std::vector<std::string>& fullCommand) {
    auto& currentCombat = combatManager.getCombatWithPlayer(username);

    auto attackValue = characterManager.getCharacterAttack(username);
    auto opponentName = currentCombat.getOpponent(username);

    if(characterManager.isDecoy(opponentName)){
        onlineUserManager.addMessageToUser(username, "You missed your opponent and hit their decoy.\n");
        onlineUserManager.addMessageToUser(opponentName, "Your opponent hit your decoy\n");
    } else {
        characterManager.damageCharacter(opponentName, attackValue);
        onlineUserManager.addMessageToUser(
                username,
                stringManager.getString(Internationalization::STRING_CODE::YOU_ATTACKED) +
                opponentName +
                stringManager.getString(Internationalization::STRING_CODE::FOR) +
                std::to_string(attackValue) +
                ".\n"
        );
        onlineUserManager.addMessageToUser(
                opponentName,
                stringManager.getString(Internationalization::STRING_CODE::YOU_WERE_ATTACKED_FOR) +
                std::to_string(attackValue) +
                ".\n" + stringManager.getString(Internationalization::STRING_CODE::CURRENT_HP) +
                std::to_string(characterManager.getCharacterHealth(opponentName)) +
                "\n"
        );
    }


    if(characterManager.getCharacterHealth(opponentName) <= 0){
        //end combat & respawn opponent if user
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