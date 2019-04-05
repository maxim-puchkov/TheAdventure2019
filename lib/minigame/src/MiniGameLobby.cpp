#include <iostream>
#include "MiniGameLobby.h"

MiniGameLobby::MiniGameLobby() {}

MiniGameMatch& MiniGameLobby::createGame(const std::string& userName) {
    MiniGameMatch newGame{userName};
    this->gameList.emplace_back(newGame);
    return gameList.back();
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
bool MiniGameLobby::confirmInvite(const std::string& invitedName){
    for(auto& invite : pendingInvites){
        auto& invited = std::get<1>(invite);
        if(invited == invitedName){
            auto& inviter = std::get<0>(invite);
            auto& match = getMatchWithPlayer(inviter);

            if (match.getAdminName() == "null"){ //if inviter is not in a match, create new one
                std::cerr << stringManager.getString(Internationalization::STRING_CODE::MAKING_NEW_MATCH);
                //match = createGame(inviter); //PROBLEM HERE. when accepting challenge when no game exists, challengee is not properly added to game (or game is not added to gameList)
                match = MiniGameMatch{inviter, invited}; //new constructor as temp solution. 1hr+ of debugging could not find solution to previous line
                gameList.emplace_back(match);
            }
            //return match.addPlayer(invited);
            return true;
        }
    }
    return false;
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
    return std::move(result);
}

std::string MiniGameLobby::printInvites() const{
    std::string result = stringManager.getString(Internationalization::STRING_CODE::MINIGAME_LOBBY_INVITELIST);
    for(auto& invite : pendingInvites){
        result += std::get<0>(invite) + ", " + std::get<1>(invite) + "\n";
    }
    return std::move(result);
}


/**
 * Spectates a game that is currently being played by the userName
 * @param userName - The userName the observer wants to watch
 * @param observer - the observer's name
 * @return
 */
std::string MiniGameLobby::spectate(const std::string &userName, const std::string &observer) {

    //find game with a specific userName

    const auto game = std::find_if(gameList.begin(), gameList.end(),
            [&](const auto &iter) {return (iter.hasPlayer(userName)); } );

    if(game != gameList.end()){
        (*game).addSpectator(observer);
        return std::move(
            stringManager.getString(Internationalization::STRING_CODE::CURRENTLY_SPECTATING) + 
            userName + 
            "\n"
        );
    }

    return std::move(
        stringManager.getString(Internationalization::STRING_CODE::COULDNT_FIND_GAME_WITH) + 
        userName + 
        stringManager.getString(Internationalization::STRING_CODE::PLAYING)
    );
}

















