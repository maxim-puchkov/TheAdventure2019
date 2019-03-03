#include "GameManager.h"
#include <boost/algorithm/string.hpp>

GameManager::GameManager() {
    world = WorldManager{};
    world.generateWorld();

    //miniGameLobby
    
    createTableOfCommands();
}

void GameManager::createTableOfCommands() {
    commandGuideline login = {&GameManager::commandLogin, &GameManager::commandError, 2, 0, " [username] [password]"};
    commandGuideline logout = {&GameManager::commandLogout, &GameManager::commandError, 0, 0, ""};
    commandGuideline create = {&GameManager::commandCreate, &GameManager::commandError, 2, 0, " [username] [password]"};
    commandGuideline startgame = {&GameManager::commandAddToActionList, &GameManager::commandStartGame, 0, 0, ""};
    commandGuideline gamemove = {&GameManager::commandAddToActionList, &GameManager::commandGameMove, 1, 0, " [startpos,endpos]"};
    commandGuideline say = {&GameManager::commandAddToActionList, &GameManager::commandSay, 0, 1, ": [message]"};
    commandGuideline yell = {&GameManager::commandAddToActionList, &GameManager::commandYell, 0, 1, ": [message]"};
    commandGuideline tell = {&GameManager::commandAddToActionList, &GameManager::commandTell, 1, 1, " [other-username]: [message]"};
    commandGuideline move = {&GameManager::commandAddToActionList, &GameManager::commandMove, 1, 0, " [direction]"};
    commandGuideline look = {&GameManager::commandAddToActionList, &GameManager::commandLook, 0, 0, ""};
    commandGuideline examine = {&GameManager::commandAddToActionList, &GameManager::commandExamine, 1, 0, " [object/username]"};
    commandGuideline help = {&GameManager::commandHelp, &GameManager::commandError, 0, 0, ""};
    
    tableOfCommands.insert({"login", login});
    tableOfCommands.insert({"logout", logout});
    tableOfCommands.insert({"create-account", create});
    tableOfCommands.insert({"startgame", startgame});
    tableOfCommands.insert({"gamemove", gamemove});
    tableOfCommands.insert({"say", say});
    tableOfCommands.insert({"yell", yell});
    tableOfCommands.insert({"tell", tell});
    tableOfCommands.insert({"move", move});
    tableOfCommands.insert({"look", look});
    tableOfCommands.insert({"examine", examine});
    tableOfCommands.insert({"help", help});
}

std::string GameManager::extractCommands(const std::string& connectionID, const std::string& fullCommand) {
    std::vector<std::string> commandParts, splitByColon;
    reassembleCommand(fullCommand, commandParts, splitByColon);

    auto found = tableOfCommands.find(commandParts[0]);
    if(found != tableOfCommands.end()) {
        commandGuideline guideline = found->second;
        if (commandIsValid(commandParts.size(), splitByColon.size(), guideline)) {
            return (this->*guideline.promptReply)(connectionID, commandParts);
        }
        else {
            std::ostringstream answer;
            answer << "Invalid command. Command syntax: " << commandParts[0] << guideline.helpText << "\n";
            return answer.str();
        }
    }
    return "Command not found\n";
}

void GameManager::reassembleCommand(std::string fullCommand, std::vector<std::string>& commandParts, std::vector<std::string>& splitByColon) {
    //Format: <command> <arg> : <optional-text-message> 
    boost::trim_if(fullCommand, boost::is_any_of(" \t"));
    boost::split(splitByColon, fullCommand, boost::is_any_of(":"), boost::token_compress_on);
   
       //trim any space before and after ":"
    for(auto& text : splitByColon) {
        boost::trim_if(text, boost::is_any_of(" \t"));
    }
    boost::split(commandParts, splitByColon[0], boost::is_any_of(" \t"), boost::token_compress_on);

    //reassemble
    if(splitByColon.size() > 1)
           commandParts.push_back(splitByColon[1]);
}

bool GameManager::commandIsValid(size_t commandPartsSize, size_t splitByColon, commandGuideline guideline) {
    if(guideline.commandPartArgCount != commandPartsSize - splitByColon)
        return false;
    if(guideline.messagePartArgCount != splitByColon - 1)
        return false;
    return true;
}




//-------------------------------------------------------
//Prompt reply commands
std::string GameManager::commandLogin(const std::string& connectionID, const std::vector<std::string>& fullCommand) {
    auto answer = onlineUserManager.login(connectionID, fullCommand[1], fullCommand[2]);
    switch(answer) {
        case usermanager::OnlineUserManager::USER_CODE::USER_LOGGED_IN:
        {
            auto spawnLocation = avatarManager.spawnAvatar(fullCommand[1]);
            world.spawn(fullCommand[1], spawnLocation);
            return "You are now logged in.\n";
        }
        case usermanager::OnlineUserManager::USER_CODE::USER_NOT_FOUND:
            return "Error! Username not found. Please try again.\n";
        case usermanager::OnlineUserManager::USER_CODE::USER_ALREADY_LOGGED_IN:
            return "Error! You are already logged in.\n";
        default:
            std::cout << "ERROR SHOULD NOT GET HERE! \n";
        break;
    }
    //swallow
    return "";
}

std::string GameManager::commandLogout(const std::string& connectionID, const std::vector<std::string>& fullCommand) {
    auto username = onlineUserManager.getUsernameFromConnectionID(connectionID);
    auto answer = onlineUserManager.logout(connectionID);
    switch(answer) {
        case usermanager::OnlineUserManager::USER_CODE::USER_LOGGED_OUT:
        {
            world.kick(username, avatarManager.getAvatarLocation(username));
            avatarManager.kickAvatar(username);
            return "You are now logged out.\n";
        }
        case usermanager::OnlineUserManager::USER_CODE::USER_NOT_ONLINE:
            return "Error! You are not logged in.\n";
        default:
            std::cout << "ERROR SHOULD NOT GET HERE! \n";
        break;
    }
    //swallow
    return "";
}

std::string GameManager::commandCreate(const std::string& connectionID, const std::vector<std::string>& fullCommand) {
    auto answer = onlineUserManager.createUser(fullCommand[1], fullCommand[2]);
    switch(answer) {
        case UserDB::DB_CODE::INVALID_USERNAME:
            return "Error! Invalid username.\n";
        case UserDB::DB_CODE::ACCOUNT_CREATED:
            return "Account created. Please log in to play the game.\n";
        default:
            std::cout << "ERROR SHOULD NOT GET HERE! \n";
        break;
    }
    //swallow
    return "";
}

std::string GameManager::commandAddToActionList(const std::string& connectionID, const std::vector<std::string>& fullCommand) {
    bool success = onlineUserManager.onlineUserAddCommandToList(connectionID, fullCommand);
    if(!success) {
        return "User is not online.\n";
    }
    //Do nothing, answer only when executing command 
    return "";
}

std::string GameManager::commandHelp(const std::string& connectionID, const std::vector<std::string>& fullCommand) {
    std::ostringstream answer;
    answer << "--------------------------------------------------\n";
    answer << "Supported commands: \n";
    for (const auto& [command, guideline] : tableOfCommands) {
        answer << command << guideline.helpText << std::endl;
    }   
    return answer.str();
}




//----------------------------------------------
//heartbeat reply functions
std::string GameManager::commandStartGame(const std::string& username, const std::vector<std::string>& fullCommand) {
    miniGameLobby.createGame(username);

    return "started game\n";
}
std::string GameManager::commandGameMove(const std::string& username, const std::vector<std::string>& fullCommand) {
    auto& playerMatch = miniGameLobby.getMatchWithPlayer(username);

    if(playerMatch.getAdminName() == "null") {
        return "you are not a player in any minigames.\n";
    }

    std::string move = fullCommand.at(1);

    if(!playerMatch.makePlayerMove(username, move)) {
        return "invalid move.\n";
    }

    playerMatch.display();
    return "< display >";
}

std::string GameManager::commandSay(const std::string& username, const std::vector<std::string>& fullCommand) {
    auto location = avatarManager.getAvatarLocation(username);
    if(location.area == -1) {
        //should not reach here, report error
        return "";
    }
    
    auto& userNamesInRoom = world.getUserNamesInRange(location, SAY_RANGE);
    for(auto name: userNamesInRoom) {
        if(name == username) {
            continue;
        }
        onlineUserManager.addMessageToUser(name, username + " said: " + fullCommand[1] + "\n");
    }

    return "You said: \"" + fullCommand[1] + "\"\n";
}

std::string GameManager::commandYell(const std::string& username, const std::vector<std::string>& fullCommand) {
    auto location = avatarManager.getAvatarLocation(username);
    if(location.area == -1) {
        //should not reach here, report error
        return "";
    }

    auto& userNamesInRoom = world.getUserNamesInRange(location, YELL_RANGE);
    for(auto name : userNamesInRoom){
        if(name == username) {
            continue;
        }
        onlineUserManager.addMessageToUser(name, username + " yelled: " + fullCommand[1] + "\n");
    }

    return "You yelled: \"" + fullCommand[1] + "\"\n";
}

std::string GameManager::commandTell(const std::string& usernameOfSpeaker, const std::vector<std::string>& fullCommand){
    std::string usernameOfListener = fullCommand.at(1);
    std::string message = fullCommand.at(2);
    std::string messageToSendOtherUser = usernameOfSpeaker + " told you: " + message + "\n";

    if(onlineUserManager.addMessageToUser(usernameOfListener, messageToSendOtherUser)) {
        return "You told " + usernameOfListener + ": " + message + "\n";
    }
    return "Failed to find online user with name: " + usernameOfListener + "\n";
}

std::string GameManager::commandMove(const std::string& username, const std::vector<std::string>& fullCommand) {
    auto location = avatarManager.getAvatarLocation(username);
    if(location.area == -1) {
        //should not reach here, report error
        return "";
    }
    auto newLocation = world.move(username, location, fullCommand[1]);
    avatarManager.changeAvatarLocation(username, location);
    std::ostringstream answer;
    answer << "Current location: Area:" << newLocation.area << ", Room: " << newLocation.room << "\n";
    return answer.str();
}

std::string GameManager::commandLook(const std::string& username, const std::vector<std::string>& fullCommand) {
    auto location = avatarManager.getAvatarLocation(username);
    if(location.area == -1) {
        //should not reach here, report error
        return "";
    }
    return world.look(location) + "\n";
}

std::string GameManager::commandExamine(const std::string& username, const std::vector<std::string>& fullCommand) {
	auto location = avatarManager.getAvatarLocation(username);
    if(location.area == -1) {
    	//should not reach here, report error
    	return "";
    }

	if(fullCommand[1] == "exits")
	    return world.listExits(location) + "\n";
	else
	    return world.look(location, fullCommand[1]) + "\n";
}

std::string GameManager::commandError(const std::string& username, const std::vector<std::string>& fullCommand){
    //Intended to be a null-function. Normally it should never reach this.
    return "";
}



//-------------------------------------------------
//heartbeat and other helper functions
std::unique_ptr<std::unordered_map<std::string, std::string>> GameManager::heartbeat() {
    onlineUserManager.removeUnactiveUser();
    auto map = std::make_unique<std::unordered_map<std::string, std::string>>();

    //process commands
    auto userCommands = onlineUserManager.getOnlineUserCommandList();
    for(auto& element : userCommands) {
        auto& username = element.first;
        auto& command = element.second;

        auto found = tableOfCommands.find(command[0]);
        commandGuideline guideline = found->second;

        auto connectionID = getUserIDByUsername(username);
        auto replyMessage = (this->*guideline.heartbeatReply)(username, command);

        map->insert(std::make_pair(connectionID, replyMessage));
    }

    //process messages
    auto userMessages = onlineUserManager.getOnlineUserMessageList();
    for (auto& element : userMessages) {
        auto& connectionID = element.first;
        auto& message = element.second;

        auto found = map->find(connectionID);
        if (found != map->end()) {
          (found->second.append("\n")).append(message);
        }
        else {
          map->insert(make_pair(connectionID, message));
        }
      }
    return std::move(map);

    /*TODO:
        Get list of top commands of all online users
        Loop through and process each command
        Gather return messages and put in the table
       */

    /* dummyUser implementation for testing
     *
     * std::string userID;
    try {
        userID = std::to_string(dummy.getId());
    }catch(std::out_of_range& e){
        std::cout << e.what();
        return map;
    }

    auto& commandQueue = dummy.getCommands();
    if(!commandQueue.empty()){

        const auto& commandParts = commandQueue.front();
        const auto& commandName = commandParts.at(0);

        auto found = tableOfCommands.find(commandName);
        commandGuideline guideline = found->second;

        //calls the command function
        const auto userMessage = (this->*guideline.heartbeatReply)(&dummy, commandParts);

        map->insert(std::make_pair(userID, userMessage));

        dummy.popCommand();
    }*/
}


std::string GameManager::getUserIDByUsername(const std::string& userName) {
    return onlineUserManager.getConnectionID(userName);
}

//user::User GameManager::getUser(const std::string& userName) {
//    return onlineUserManager.getUserByUsername(userName);
//}

