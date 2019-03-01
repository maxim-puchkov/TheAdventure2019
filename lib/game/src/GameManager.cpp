#include "GameManager.h"
#include <boost/algorithm/string.hpp>

GameManager::GameManager() {
    world = WorldManager{};
    world.generateWorld();
    
    createTableOfCommands();
}

void GameManager::createTableOfCommands() {
    commandGuideline login = {&GameManager::commandLogin, &GameManager::commandError, 2, 0, " [username] [password]"};
    commandGuideline logout = {&GameManager::commandLogout, &GameManager::commandError, 0, 0, ""};
    commandGuideline create = {&GameManager::commandCreate, &GameManager::commandError, 2, 0, " [username] [password]"};
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
		    world.spawn(getAvatarByUsername(fullCommand[1]), LocationCoordinates{0,0});
			return "You are now logged in.\n";
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
    auto answer = onlineUserManager.logout(connectionID);
    auto& avatar = onlineUserManager.getAvatarById(connectionID);
	switch(answer) {
		case usermanager::OnlineUserManager::USER_CODE::USER_LOGGED_OUT:
            world.kick(avatar);
			return "You are now logged out.\n";
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
std::string GameManager::commandSay(Avatar& avatar, const std::vector<std::string>& fullCommand) {
    auto& userNamesInRoom = world.getUserNamesInRoom(avatar.getCurrentLocation());

    for(auto name: userNamesInRoom) {
    	if(name == avatar.getName()) {
    		continue;
    	}
        onlineUserManager.addMessageToUser(name, avatar.getName() + " said: " + fullCommand[1] + "\n");
    }

	return "You said: \"" + fullCommand[1] + "\"\n";
}

std::string GameManager::commandYell(Avatar& avatar, const std::vector<std::string>& fullCommand) {
    auto& userNamesInRoom = world.getUserNamesInRange(avatar.getCurrentLocation(), YELL_RANGE);

    for(auto name : userNamesInRoom){
    	if(name == avatar.getName()) {
    		continue;
    	}
        onlineUserManager.addMessageToUser(name, avatar.getName() + " yelled: " + fullCommand[1] + "\n");
    }

    return "You yelled: \"" + fullCommand[1] + "\"\n";
}

std::string GameManager::commandTell(Avatar& avatar, const std::vector<std::string>& fullCommand){
    std::string usernameOfListener = fullCommand.at(1);
	std::string message = fullCommand.at(2);
    std::string messageToSendOtherUser = avatar.getName() + " told you: " + message + "\n";

    if(onlineUserManager.addMessageToUser(usernameOfListener, messageToSendOtherUser)) {
        return "You told " + usernameOfListener + ": " + message + "\n";
    }
    return "Failed to find online user with name: " + usernameOfListener + "\n";
}

std::string GameManager::commandMove(Avatar& avatar, const std::vector<std::string>& fullCommand) {
	LocationCoordinates newLocation = world.move(avatar, fullCommand[1]);
	std::ostringstream answer;
	answer << "Current location: Area:" << newLocation.area << ", Room: " << newLocation.room << "\n";
	return answer.str();
}

std::string GameManager::commandLook(Avatar& avatar, const std::vector<std::string>& fullCommand) {
	return world.look(avatar) + "\n";
}

std::string GameManager::commandExamine(Avatar& avatar, const std::vector<std::string>& fullCommand) {
	if(fullCommand[1] == "exits")
	    return world.listExits(avatar) + "\n";
	else
	    return world.look(avatar, fullCommand[1]) + "\n";
}

std::string GameManager::commandError(Avatar& avatar, const std::vector<std::string>& fullCommand){
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
    	auto& avatar = getAvatarByUsername(username);
    	auto replyMessage = (this->*guideline.heartbeatReply)(avatar, command);

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
}


std::string GameManager::getUserIDByUsername(const std::string& userName) {
    return onlineUserManager.getConnectionID(userName);
}

Avatar& GameManager::getAvatarByUsername(const std::string& userName) {
	return onlineUserManager.getAvatarByUsername(userName);
}

