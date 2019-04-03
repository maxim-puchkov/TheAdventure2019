#include "GameManager.h"
#include <boost/algorithm/string.hpp>

int heartBeatDuration = 50;

GameManager::GameManager() {
    world.generateWorld();
    createTableOfCommands();
}

void GameManager::createTableOfCommands() {

    tableOfCommands.insert({"help", make_unique<CommandHelp>(characterManager, onlineUserManager, world)});
    tableOfCommands.insert({"login", make_unique<CommandLogin>(characterManager, onlineUserManager, world)});
    tableOfCommands.insert({"create-account", make_unique<CommandCreate>(characterManager, onlineUserManager, world)});
    tableOfCommands.insert({"create-avatar", make_unique<CommandCreateAva>(characterManager, onlineUserManager, world)});
    tableOfCommands.insert({"edit-avatar", make_unique<CommandEditAva>(characterManager, onlineUserManager, world)});
#ifdef BUILD_ALL_TARGETS
   tableOfCommands.insert({"logout", make_unique<CommandLogout>(characterManager, onlineUserManager, world)});
    tableOfCommands.insert({"say", make_unique<CommandSay>(characterManager, onlineUserManager, world)});
    tableOfCommands.insert({"tell", make_unique<CommandTell>(characterManager, onlineUserManager, world)});
    tableOfCommands.insert({"yell", make_unique<CommandYell>(characterManager, onlineUserManager, world)});
    tableOfCommands.insert({"look", make_unique<CommandLook>(characterManager, onlineUserManager, world)});
    tableOfCommands.insert({"examine", make_unique<CommandExamine>(characterManager, onlineUserManager, world)});
    tableOfCommands.insert({"move", make_unique<CommandMove>(characterManager, onlineUserManager, world)});

    tableOfCommands.insert({"create-room", make_unique<CommandCreateRoom>(characterManager, onlineUserManager, world)});
    tableOfCommands.insert({"edit-room", make_unique<CommandEditRoom>(characterManager, onlineUserManager, world)});
    tableOfCommands.insert({"use", make_unique<CommandUse>(characterManager, onlineUserManager, world)});
    tableOfCommands.insert({"equip", make_unique<CommandEquip>(characterManager, onlineUserManager, world)});
    tableOfCommands.insert({"take", make_unique<CommandTake>(characterManager, onlineUserManager, world)});
    tableOfCommands.insert({"drop", make_unique<CommandDrop>(characterManager, onlineUserManager, world)});
    tableOfCommands.insert({"put", make_unique<CommandPut>(characterManager, onlineUserManager, world)});
    tableOfCommands.insert({"minigame", make_unique<CommandMinigame>(characterManager, onlineUserManager, world)});
    tableOfCommands.insert({"combat", make_unique<CommandCombat>(characterManager, onlineUserManager, world)});
    tableOfCommands.insert({"attack", make_unique<CommandAttack>(characterManager, onlineUserManager, world)});
    tableOfCommands.insert({"flee", make_unique<CommandFlee>(characterManager, onlineUserManager, world)});
    tableOfCommands.insert({"cast", make_unique<CommandCast>(characterManager, onlineUserManager, world)});
#endif
}

std::string GameManager::extractCommands(const std::string& connectionID, std::string fullCommand) {
	auto found = tableOfCommands.find(extractKeyword(fullCommand));
    
    if(found != tableOfCommands.end()) {
    	bool commandIsValid;
    	auto processedCommand = found->second->reassembleCommand(fullCommand, commandIsValid);
    	if(commandIsValid) {
            onlineUserManager.updateUserTimeStamp(connectionID);
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

    //kick inactive users
    if (heartBeatDuration == 0) {
        auto connectionIDs = onlineUserManager.unactiveUser();
        for(const auto& element : connectionIDs) {
            std::string fullCommand = "logout";
            std::string logoutMessage = "You have been idle for too long.\n" + extractCommands(element, fullCommand);
            map->insert(make_pair(element, logoutMessage));
        }
        heartBeatDuration = 50;
    }
    heartBeatDuration--;

    //Combat round
    auto& combatManager = characterManager.getCombatManager();
    combatManager.roundTick();
    auto combatCommands = combatManager.getCombatCommands();
    for (auto& element : combatCommands){
        auto& username = element.first;
        auto& command = element.second;

        auto found = tableOfCommands.find(command[0]);
        if(found != tableOfCommands.end()) {
            found->second->executeInHeartbeat(username, command);
        }
    }


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
