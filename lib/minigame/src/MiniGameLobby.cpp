#include <iostream>
#include "MiniGameLobby.h"

MiniGameLobby::MiniGameLobby() {}

MiniGameMatch& MiniGameLobby::createGame(const std::string& userName) {
    MiniGameMatch newGame{userName};

    return newGame;
}

//potential issue: deletes all games owned by adminName. may switch to unique matchID
// if we do not prevent players from creating more than one game
void MiniGameLobby::deleteGame(const std::string& adminName){
    gameList.erase(std::remove_if(gameList.begin(), gameList.end(),
                                        [&adminName](MiniGameMatch& x){return x.getAdminName() == adminName;}),
                   gameList.end());
}

MiniGameMatch& MiniGameLobby::getMatchWithPlayer(const std::string& playerName) {
    for(auto& match : gameList){
        if (match.hasPlayer(playerName)){
            return match;
        }
    }
    return nullMatch;
}

void MiniGameLobby::createInvite(const std::string& inviterName, const std::string& invitedName){
    //auto invite = std::make_tuple(inviterName, invitedName, TimeStamp::getTimeStamp());
    auto invite = std::make_tuple(inviterName, invitedName, 0);
    pendingInvites.emplace_back(invite);
}

void MiniGameLobby::clearStaleInvites() {
    pendingInvites.erase(std::remove_if(pendingInvites.begin(), pendingInvites.end(),
            [](std::tuple<std::string, std::string, long>& x){return std::get<2>(x) == 0;}), //for now: remove if timestamp = 0. change later
                    pendingInvites.end());
}

//potential issue: if inviter logs out before invited accepts, game is still made for both
//Function is called when player accepts an invite.
bool MiniGameLobby::confirmInvite(const std::string& invitedName){


    for(const auto& invite : pendingInvites){
        auto &invitedPlayer = std::get<1>(invite);
        if(invitedPlayer == invitedName){
            //we found the correct invite!

            auto &hostPlayer = std::get<0>(invite);
            auto &match = getMatchWithPlayer(hostPlayer);

            if(match.getAdminName() == "null"){
                match = MiniGameMatch{hostPlayer,invitedPlayer};
            } else{
                match.addPlayer(invitedPlayer); //the match has already been created since the adminName isn't null
            }
            gameList.emplace_back(match);
            return true;
        }
    }

    return false; //The name was never found in the list of invited people


}

void MiniGameLobby::removeInvite(const std::string& eitherName){
    pendingInvites.erase(std::remove_if(pendingInvites.begin(), pendingInvites.end(),
            [&eitherName](std::tuple<std::string, std::string, long>& x){return std::get<0>(x) == eitherName || std::get<1>(x) == eitherName;}),
                    pendingInvites.end());
}

std::string MiniGameLobby::printGames() const{
    std::string result = stringManager.getString(Internationalization::STRING_CODE::MINIGAME_LOBBY_GAMELIST);
    for(auto game : gameList){
        std::string playerNames;
        auto& playerList = game.getPlayers();
        for(auto& pname : playerList){
            playerNames += pname + ", ";
        }
        result += game.getAdminName() + ": " + playerNames + "\n";
    }
    return result;
}


std::string MiniGameLobby::printInvites() const{
    std::string result = stringManager.getString(Internationalization::STRING_CODE::MINIGAME_LOBBY_INVITELIST);
    for(auto& invite : pendingInvites){
        result += std::get<0>(invite) + ", " + std::get<1>(invite) + "\n";
    }
    return result;
}


/**
 * Spectates a game that is currently being played by the userName
 * @param userName - The userName the observer wants to watch
 * @param observer - the observer's name
 * @return - A message to the user
 */
std::string MiniGameLobby::spectate(const std::string &userName, const std::string &observer) {

    //find game with a specific userName

    const auto game = std::find_if(gameList.begin(), gameList.end(),
            [&](const auto &iter) {return (iter.hasPlayer(userName)); } );

    if(game != gameList.end()){
        (*game).addSpectator(observer);
        return stringManager.getString(Internationalization::STRING_CODE::CURRENTLY_SPECTATING) +userName + "\n";
    }

    return stringManager.getString(Internationalization::STRING_CODE::COULDNT_FIND_GAME_WITH) + userName + stringManager.getString(Internationalization::STRING_CODE::PLAYING);
}

















