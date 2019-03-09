#include "GameManager.h"
#include <boost/algorithm/string.hpp>

#include <exception>

GameManager::GameManager() {
    world = WorldManager{};
    world.generateWorld();
    
    createTableOfCommands();
}

void GameManager::createTableOfCommands() {
    table.insert({"login", make_unique<CommandLogin>(avatarManager, onlineUserManager, world)});
    table.insert({"logout", make_unique<CommandLogout>(avatarManager, onlineUserManager, world)});
    table.insert({"create-account", make_unique<CommandCreate>(avatarManager, onlineUserManager, world)});
    table.insert({"help", make_unique<CommandHelp>(avatarManager, onlineUserManager, world)});
    table.insert({"say", make_unique<CommandSay>(avatarManager, onlineUserManager, world)});
    table.insert({"tell", make_unique<CommandTell>(avatarManager, onlineUserManager, world)});
    table.insert({"yell", make_unique<CommandYell>(avatarManager, onlineUserManager, world)});
    table.insert({"look", make_unique<CommandLook>(avatarManager, onlineUserManager, world)});
    table.insert({"examine", make_unique<CommandExamine>(avatarManager, onlineUserManager, world)});
}

std::string GameManager::extractCommands(const std::string& connectionID, const std::string& fullCommand) {
    std::vector<std::string> commandParts, splitByColon;
    reassembleCommand(fullCommand, commandParts, splitByColon);

	auto found = table.find(commandParts[0]);
    if(found != table.end()) {
    	return found->second->executePromptReply(connectionID, commandParts);
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

bool GameManager::commandIsValid(size_t commandPartsSize, size_t splitByColon) {
    return true;
}



std::unique_ptr<std::unordered_map<std::string, std::string>> GameManager::heartbeat() {
    auto map = std::make_unique<std::unordered_map<std::string, std::string>>();

    //process commands
    auto userCommands = onlineUserManager.getOnlineUserCommandList();
    for(auto& element : userCommands) {
    	auto& username = element.first;
    	auto& command = element.second;
		
		auto found = table.find(command[0]);
	    if(found != table.end()) {
	    	found->second->executeInHeartbeat(username, command);
	    }
	}

    //process messages
    auto userMessages = onlineUserManager.getOnlineUserMessageList();
    for (auto& element : userMessages) {
    	auto& connectionID = element.first;
    	auto& message = element.second;
    	map->insert(make_pair(connectionID, message));
	}

    return std::move(map);
}