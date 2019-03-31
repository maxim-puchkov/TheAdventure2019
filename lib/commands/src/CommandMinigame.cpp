#include "CommandMinigame.h"
#include <boost/algorithm/string.hpp>
#include <iostream>

using internationalization::Internationalization;

void CommandMinigame::sendWinMessage(vector<std::string> &players, vector<std::string> &spectators, std::string msg) {

    msg.append(stringManager.getString(Internationalization::STRING_CODE::TYPE_MINIGAME_EXIT));
    for(const std::string &iter : spectators){
        onlineUserManager.addMessageToUser(iter,  msg + "\n");
    }

    for(const std::string &aPlayer : players){
        onlineUserManager.addMessageToUser(aPlayer, msg + "\n");
    }

}

void CommandMinigame::executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand) {
    auto &miniGameLobby = characterManager.getMiniGameLobby();
    auto &playerMatch = miniGameLobby.getMatchWithPlayer(username);
    auto &firstCommand = fullCommand.at(1);

    if (firstCommand == "start") {

        miniGameLobby.createGame(username);
        onlineUserManager.addMessageToUser(username,
                                           stringManager.getString(Internationalization::STRING_CODE::STARTED_GAME));

    } else if (firstCommand == "move") {

        if (playerMatch.getAdminName() == "null") {
            onlineUserManager.addMessageToUser(username, 
                                               stringManager.getString(Internationalization::STRING_CODE::YOU_ARE_NOT_IN_ANY_MINIGAMES));
        }

        auto moveFrom = fullCommand.at(2);
        auto moveTo = fullCommand.at(3);
        if (!playerMatch.makePlayerMove(username, moveFrom, moveTo)) {
            std::string msg = stringManager.getString(Internationalization::STRING_CODE::INVALID_MOVE_OR_NOT_YOUR_TURN) +
                              playerMatch.getCurrentPlayerTurn() + "'s turn\n ";
            onlineUserManager.addMessageToUser(username, std::move(msg));
        }

    } else if (firstCommand == "challenge" || firstCommand == "invite") {

        auto &challengedName = fullCommand.at(2);
        miniGameLobby.createInvite(username, challengedName);
        onlineUserManager.addMessageToUser(challengedName, username + stringManager.getString(Internationalization::STRING_CODE::HAS_CHALLENGED_TO_MINIGAME) 
                                                                    + stringManager.getString(Internationalization::STRING_CODE::TO_ACCEPT_CHALLENGE));

        onlineUserManager.addMessageToUser(username, 
                                          (stringManager.getString(Internationalization::STRING_CODE::AWAITING_RESPONSE_FROM) + challengedName + "\n"));

    } else if (firstCommand == "join" || firstCommand == "accept") {

        if (miniGameLobby.confirmInvite(username)) {
            miniGameLobby.removeInvite(username);
            auto &playerMatch = miniGameLobby.getMatchWithPlayer(username);
            auto &playerList = playerMatch.getPlayers();
            std::string pNames;
            for (auto &pName : playerList) {
                onlineUserManager.addMessageToUser(pName, 
                                                   username + stringManager.getString(Internationalization::STRING_CODE::HAS_JOINED_THE_GAME));
                pNames += pName + ", ";
            }
            onlineUserManager.addMessageToUser(username, 
                                               stringManager.getString(Internationalization::STRING_CODE::JOINED_GAME_WITH) + pNames + "\n");
        } else {
            onlineUserManager.addMessageToUser(username, 
                                               stringManager.getString(Internationalization::STRING_CODE::INVITE_DOES_NOT_EXIST_OR_FULL));
        }

    } else if (firstCommand == "quit" || firstCommand == "exit") {

        auto &playerMatch = miniGameLobby.getMatchWithPlayer(username);
        if (playerMatch.getAdminName() == "null") {
            onlineUserManager.addMessageToUser(username, 
                                               stringManager.getString(Internationalization::STRING_CODE::YOU_ARE_NOT_IN_ANY_MINIGAMES));
        }
        playerMatch.removePlayer(username);
        if (playerMatch.getCurrentPlayers() == 0) {
            miniGameLobby.deleteGame(playerMatch.getAdminName());
        }
        onlineUserManager.addMessageToUser(username, 
                                           stringManager.getString(Internationalization::STRING_CODE::YOU_LEFT_GAME));
        return;

    } else if (firstCommand == "print") {
        if (fullCommand.at(2) == "games")
            onlineUserManager.addMessageToUser(username, miniGameLobby.printGames());
        if (fullCommand.at(2) == "invites")
            onlineUserManager.addMessageToUser(username, miniGameLobby.printInvites());
        return;
    }


    vector<string> &players = playerMatch.getPlayers();
    if (players.size() == 2) {
        onlineUserManager.addMessageToUser(players.at(0), playerMatch.reverseDisplay() + "\n" );
        onlineUserManager.addMessageToUser(players.at(1), playerMatch.display() + "\n" );
    }


    for(const std::string &spectator : playerMatch.getSpectators()){
        onlineUserManager.addMessageToUser(spectator, playerMatch.display() + "\n");
    }


    if(playerMatch.isGameFinished()){
        sendWinMessage( playerMatch.getPlayers(), playerMatch.getSpectators(), std::move(playerMatch.getWinMessage()) );
    }

}

std::vector<std::string> CommandMinigame::reassembleCommand(std::string& fullCommand, bool& commandIsValid) {
    std::vector<std::string> processedCommand;
    commandIsValid = false;

    //Format: minigame challenge [username]
    //Format: minigame accept
    //Format: minigame accept [username]
    //Format: minigame join [username]
    //Format: minigame move [location-of-piece-to-be-moved],[new-location]
    boost::trim_if(fullCommand, boost::is_any_of(" \t"));

    //Split by ","
    std::vector<std::string> splitByComma;
    boost::split(splitByComma, fullCommand, boost::is_any_of(","), boost::token_compress_on);   
    if(splitByComma.size() == 2) {
        //validate "minigame move"
        return reassembleMinigameMove(splitByComma, commandIsValid);

    } else if (splitByComma.size() == 1) {
        //split by " "
        boost::split(processedCommand, splitByComma[0], boost::is_any_of(" \t"), boost::token_compress_on);        
        if(processedCommand.size() == 2) {
            commandIsValid = (processedCommand[1] == "accept" ||
                                processedCommand[1] == "start" ||
                                processedCommand[1] == "quit");
        
        } else if(processedCommand.size() == 3) {
            //reassemble the command
            commandIsValid = (processedCommand[1] == "accept" ||
                                processedCommand[1] == "join" ||
                                processedCommand[1] == "challenge" ||
                                processedCommand[1] == "print");
        }
    }

    return processedCommand;
}

std::vector<std::string> CommandMinigame::reassembleMinigameMove(std::vector<std::string>& splitByComma, bool& commandIsValid) {
    //Format: minigame move [location-of-piece-to-be-moved],[new-location]
    std::vector<std::string> leftSide, rightSide, processedCommand;
    commandIsValid = false;

    //trim any space before and after ","
    boost::trim_if(splitByComma[0], boost::is_any_of(" \t"));
    boost::trim_if(splitByComma[1], boost::is_any_of(" \t"));
    
    //split left side of "," by " "
    boost::split(leftSide, splitByComma[0], boost::is_any_of(" \t"), boost::token_compress_on);
    if (leftSide.size() != 3)  {    
        return processedCommand;
    }

    if(leftSide[1] != "move") {
        return processedCommand;
    }

    //split right side of "," by " "
    boost::split(rightSide, splitByComma[1], boost::is_any_of(" \t"), boost::token_compress_on);
    if (rightSide.size() != 1)  {
        return processedCommand;
    }

    //reassemble the whole thing
    std::swap(leftSide, processedCommand);
    processedCommand.push_back(rightSide[0]);

    commandIsValid = true;
    return processedCommand;
}