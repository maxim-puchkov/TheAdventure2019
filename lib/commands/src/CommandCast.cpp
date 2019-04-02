#include "CommandCast.h"
#include <boost/algorithm/string.hpp>

void CommandCast::executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand) {
    auto& currentCombat = combatManager.getCombatWithPlayer(username);

    if(currentCombat.hasPlayer(username)){

        currentCombat.queueCommand(username, fullCommand);

        //handle npc opponent. does nothing if character is user controlled
        auto opponentName = currentCombat.getOpponent(username);
        auto opponentResponse = characterManager.getAttackReply(opponentName);
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

void CommandCast::executeCombatRound(const std::string& username, const std::vector<std::string>& fullCommand) {
    auto& currentCombat = combatManager.getCombatWithPlayer(username);
    auto spellName = fullCommand.at(1);

    cerr << "round time 0, executing attack\n";
    auto attackValue = characterManager.getCharacterAttack(username);
    auto opponentName = currentCombat.getOpponent(username);

    characterManager.damageCharacter(opponentName, attackValue);

}

std::vector<std::string> CommandCast::reassembleCommand(std::string& fullCommand, bool& commandIsValid) {
    std::vector<std::string> processedCommand;

    //Format: cast [spell-name]
    boost::trim_if(fullCommand, boost::is_any_of(" \t"));

    //split by " " and compress all long spaces
    boost::split(processedCommand, fullCommand, boost::is_any_of(" \t"), boost::token_compress_on);
    commandIsValid = (processedCommand.size() == 2);

    return processedCommand;
}