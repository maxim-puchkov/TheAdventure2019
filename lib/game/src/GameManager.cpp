#include "GameManager.h"

int heartBeatDuration = 50;

GameManager::GameManager() {
    world.generateWorld();
    createTableOfCommands();
}

void GameManager::createTableOfCommands() {
    tableOfCommands.insert({"login", make_unique<CommandLogin>(avatarManager, onlineUserManager, world)});
    tableOfCommands.insert({"logout", make_unique<CommandLogout>(avatarManager, onlineUserManager, world)});
    tableOfCommands.insert({"create-account", make_unique<CommandCreate>(avatarManager, onlineUserManager, world)});
    tableOfCommands.insert({"help", make_unique<CommandHelp>(avatarManager, onlineUserManager, world)});
    tableOfCommands.insert({"say", make_unique<CommandSay>(avatarManager, onlineUserManager, world)});
    tableOfCommands.insert({"tell", make_unique<CommandTell>(avatarManager, onlineUserManager, world)});
    tableOfCommands.insert({"yell", make_unique<CommandYell>(avatarManager, onlineUserManager, world)});
    tableOfCommands.insert({"look", make_unique<CommandLook>(avatarManager, onlineUserManager, world)});
    tableOfCommands.insert({"examine", make_unique<CommandExamine>(avatarManager, onlineUserManager, world)});
    tableOfCommands.insert({"move", make_unique<CommandMove>(avatarManager, onlineUserManager, world)});
    tableOfCommands.insert({"create-avatar", make_unique<CommandCreateAva>(avatarManager, onlineUserManager, world)});
    tableOfCommands.insert({"edit-avatar", make_unique<CommandEditAva>(avatarManager, onlineUserManager, world)});
    tableOfCommands.insert({"create-room", make_unique<CommandCreateRoom>(avatarManager, onlineUserManager, world)});
    tableOfCommands.insert({"edit-room", make_unique<CommandEditRoom>(avatarManager, onlineUserManager, world)});
    tableOfCommands.insert({"use", make_unique<CommandUse>(avatarManager, onlineUserManager, world)});
    tableOfCommands.insert({"equip", make_unique<CommandEquip>(avatarManager, onlineUserManager, world)});
    tableOfCommands.insert({"pickup", make_unique<CommandPickup>(avatarManager, onlineUserManager, world)});
    tableOfCommands.insert({"drop", make_unique<CommandDrop>(avatarManager, onlineUserManager, world)});
    tableOfCommands.insert({"put", make_unique<CommandPut>(avatarManager, onlineUserManager, world)});
    tableOfCommands.insert({"minigame", make_unique<CommandMinigame>(avatarManager, onlineUserManager, world)});
    tableOfCommands.insert({"combat", make_unique<CommandCombat>(avatarManager, onlineUserManager, world)});
    tableOfCommands.insert({"attack", make_unique<CommandAttack>(avatarManager, onlineUserManager, world)});
    tableOfCommands.insert({"flee", make_unique<CommandFlee>(avatarManager, onlineUserManager, world)});
    tableOfCommands.insert({"cast", make_unique<CommandCast>(avatarManager, onlineUserManager, world)});
}

std::string GameManager::extractCommands(const std::string& connectionID, std::string fullCommand) {
	auto found = tableOfCommands.find(extractKeyword(fullCommand));
    
    if(found != tableOfCommands.end()) {
    	bool commandIsValid;
    	auto processedCommand = found->second->reassembleCommand(fullCommand, commandIsValid);
    	if(commandIsValid) {
    		return found->second->executePromptReply(connectionID, processedCommand);
    	}
    	return "Wrong command syntax. Please enter \"help\" to see the syntax.\n";
    }
    return "Command not found. Please enter \"help\" to see the syntax.\n";
}

std::string GameManager::extractKeyword(std::string& fullCommand) {
	boost::to_lower(fullCommand);
    boost::trim_if(fullCommand, boost::is_any_of(" \t"));

    std::vector<std::string> commandParts;
    boost::split(commandParts, fullCommand, boost::is_any_of(" :"), boost::token_compress_on);
    
    return commandParts[0];
}

std::unique_ptr<std::unordered_map<std::string, std::string>> GameManager::heartbeat() {
    auto map = std::make_unique<std::unordered_map<std::string, std::string>>();
/*
    //kick inactive users
    std::cout << "TIME TO KICK: " << heartBeatDuration <<"\n";
    
    if (heartBeatDuration == 0) {
        std::string connectionID = onlineUserManager.removeUnactiveUser();
        
        auto found = tableOfCommands.find("logout");
        std::vector<std::string> fullCommand;
        fullCommand.push_back("logout");
        std::string logoutMessage = "You have been idle for too long.\n" + found->second->executePromptReply(connectionID, fullCommand);
        map->insert(make_pair(connectionID, logoutMessage));
        //commandLogout(connectionID, vecForTest);
        
        heartBeatDuration = 50;
    
    }
    heartBeatDuration--;
*/    
    
    //process commands
    auto userCommands = onlineUserManager.getOnlineUserCommandList();
    for(auto& element : userCommands) {
    	auto& username = element.first;
    	auto& command = element.second;
		
		auto found = tableOfCommands.find(command[0]);
	    if(found != tableOfCommands.end()) {
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