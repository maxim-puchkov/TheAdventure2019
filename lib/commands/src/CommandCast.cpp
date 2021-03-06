#include "CommandCast.h"
#include <boost/algorithm/string.hpp>

void CommandCast::executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand) {
    auto& currentCombat = combatManager.getCombatWithPlayer(username);

    if(currentCombat.hasPlayer(username)){

        currentCombat.queueCommand(username, fullCommand);

        //handle npc opponent. does nothing if character is user controlled
        auto opponentName = currentCombat.getOpponent(username);
        auto opponentResponse = characterManager.getCastReply(opponentName);
        if(!opponentResponse.empty()) {
            onlineUserManager.addMessageToUser(username, opponentName + " prepares a(n) " + opponentResponse + "\n");
            std::vector<std::string> opponentCommand;
            boost::split(opponentCommand, opponentResponse, boost::is_any_of(" \t"), boost::token_compress_on);
            //opponentCommand.push_back(opponentResponse);
            currentCombat.queueCommand(opponentName, opponentCommand);
        }

    } else { //player is not in a combat
        onlineUserManager.addMessageToUser(username, "You are not in combat with anyone!\n");
    }
}

void CommandCast::executeCombatRound(const std::string& username, const std::vector<std::string>& fullCommand) {
    auto& currentCombat = combatManager.getCombatWithPlayer(username);
    auto opponentName = currentCombat.getOpponent(username);
    auto spellName = fullCommand.at(1);

    cerr << "round time 0, executing cast\n";
    if(spellName == "swap"){
        if(characterManager.swapCharacters(username, opponentName)){
            characterManager.setSwapped(opponentName, true);
            cerr << "swap should have worked\n";
            cerr << "your char name: " + characterManager.getCharacterNameFromUser(username) + "\n";
            onlineUserManager.addMessageToUser(username, "You swapped!\n");
            onlineUserManager.addMessageToUser(opponentName, "You were swapped!\n");
        } else {
            cerr << "swap should have failed\n";
            cerr << "your char name: " + characterManager.getCharacterNameFromUser(username) + "\n";
        }
    } else if(spellName == "confuse"){
        characterManager.setConfused(opponentName, true);
        onlineUserManager.addMessageToUser(username, "You confused!\n");
        onlineUserManager.addMessageToUser(opponentName, "You were confused!\n");
    } else if(spellName == "decoy"){
        characterManager.setDecoy(opponentName, true);
        onlineUserManager.addMessageToUser(username, "You created a decoy!\n");
        onlineUserManager.addMessageToUser(opponentName, "Your opponent made a decoy!\n");
    }

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