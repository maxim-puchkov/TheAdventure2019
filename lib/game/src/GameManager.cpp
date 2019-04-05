#include "GameManager.h"
#include <boost/algorithm/string.hpp>

GameManager::GameManager() {
    //worldManager.generateWorld();
    // Making the World using the JSON files
    AreaGenerator areaGen{};
    std::vector<std::string> areaJSONs = 
        {"../adventure2019/data/world/mirkwood.json",
        "../adventure2019/data/world/shire.json",
        "../adventure2019/data/world/solace.json"};
    std::vector<Area> areas;

    for (auto filePath : areaJSONs){
        auto area = areaGen.getArea(filePath, characterManager, world.items);
        areas.push_back(area);
    }

    //get the first area name to spawn first time login user
    int count = 0;
    for(auto& area: areas){
        if(count == 0) {
            world.setAreaToSpawnFirstTimer(area.getName());
            count++;
        }
        area = areaGen.generateExits(area);
        world.addArea(area);
    }    

    createTableOfCommands();
}

void GameManager::createTableOfCommands() {

#ifndef BUILD_ALL_TARGETS
    
    tableOfCommands.insert({"help", make_unique<CommandHelp>(characterManager, onlineUserManager, world, stringManager)});
    tableOfCommands.insert({"login", make_unique<CommandLogin>(characterManager, onlineUserManager, world, stringManager)});
    
    tableOfCommands.insert({"take", make_unique<CommandTake>(characterManager, onlineUserManager, world, stringManager)});

#else
    
    tableOfCommands.insert({"help", make_unique<CommandHelp>(characterManager, onlineUserManager, world, stringManager)});
    tableOfCommands.insert({"login", make_unique<CommandLogin>(characterManager, onlineUserManager, world, stringManager)});
    tableOfCommands.insert({"logout", make_unique<CommandLogout>(characterManager, onlineUserManager, world, stringManager)});
    tableOfCommands.insert({"create-account", make_unique<CommandCreate>(characterManager, onlineUserManager, world, stringManager)});
    
    tableOfCommands.insert({"create-avatar", make_unique<CommandCreateAva>(characterManager, onlineUserManager, world, stringManager)});
    tableOfCommands.insert({"edit-avatar", make_unique<CommandEditAva>(characterManager, onlineUserManager, world, stringManager)});

    tableOfCommands.insert({"say", make_unique<CommandSay>(characterManager, onlineUserManager, world, stringManager)});
    tableOfCommands.insert({"tell", make_unique<CommandTell>(characterManager, onlineUserManager, world, stringManager)});
    tableOfCommands.insert({"yell", make_unique<CommandYell>(characterManager, onlineUserManager, world, stringManager)});
    
    tableOfCommands.insert({"look", make_unique<CommandLook>(characterManager, onlineUserManager, world, stringManager)});
    tableOfCommands.insert({"examine", make_unique<CommandExamine>(characterManager, onlineUserManager, world, stringManager)});
    tableOfCommands.insert({"move", make_unique<CommandMove>(characterManager, onlineUserManager, world, stringManager)});

    tableOfCommands.insert({"create-room", make_unique<CommandCreateRoom>(characterManager, onlineUserManager, world, stringManager)});
    tableOfCommands.insert({"edit-room", make_unique<CommandEditRoom>(characterManager, onlineUserManager, world, stringManager)});
    
    tableOfCommands.insert({"take", make_unique<CommandTake>(characterManager, onlineUserManager, world, stringManager)});
    tableOfCommands.insert({"use", make_unique<CommandUse>(characterManager, onlineUserManager, world, stringManager)});
    tableOfCommands.insert({"equip", make_unique<CommandEquip>(characterManager, onlineUserManager, world, stringManager)});
    tableOfCommands.insert({"drop", make_unique<CommandDrop>(characterManager, onlineUserManager, world, stringManager)});
    tableOfCommands.insert({"put", make_unique<CommandPut>(characterManager, onlineUserManager, world, stringManager)});
    
    tableOfCommands.insert({"minigame", make_unique<CommandMinigame>(characterManager, onlineUserManager, world, stringManager)});
    
    tableOfCommands.insert({"combat", make_unique<CommandCombat>(characterManager, onlineUserManager, world, stringManager)});
    tableOfCommands.insert({"attack", make_unique<CommandAttack>(characterManager, onlineUserManager, world, stringManager)});
    tableOfCommands.insert({"flee", make_unique<CommandFlee>(characterManager, onlineUserManager, world, stringManager)});
    
    tableOfCommands.insert({"cast", make_unique<CommandCast>(characterManager, onlineUserManager, world, stringManager)});
    tableOfCommands.insert({"create-item", make_unique<CommandCreateItem>(characterManager, onlineUserManager, world, stringManager)});
    
#endif
    
}

std::string GameManager::extractCommands(const std::string& connectionID, std::string fullCommand) {
	auto found = tableOfCommands.find(extractKeyword(fullCommand));
    
    if(found != tableOfCommands.end()) {
    	bool commandIsValid;
    	auto processedCommand = found->second->reassembleCommand(fullCommand, commandIsValid);
    	//everything is ok
        if(commandIsValid) {
            onlineUserManager.updateUserTimeStamp(connectionID);
    		return found->second->executePromptReply(connectionID, processedCommand);
    	}
        //wrong syntax
        return (stringManager.getString(Internationalization::STRING_CODE::WRONG_COMMAND_SYNTAX) + " " +
                stringManager.getString(Internationalization::STRING_CODE::PLEASE_ENTER) + "\"" +
                stringManager.getString(Internationalization::STRING_CODE::COMMAND_HELP) + "\"" +
                stringManager.getString(Internationalization::STRING_CODE::TO_SEE_SUPPORTED_SYNTAX));
    }
    //command not found
    return (stringManager.getString(Internationalization::STRING_CODE::COMMAND_NOT_FOUND) + " " +
            stringManager.getString(Internationalization::STRING_CODE::PLEASE_ENTER) + "\"" +
            stringManager.getString(Internationalization::STRING_CODE::COMMAND_HELP) + "\"" +
            stringManager.getString(Internationalization::STRING_CODE::TO_SEE_SUPPORTED_COMMANDS));
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
            std::string fullCommand = stringManager.getString(Internationalization::STRING_CODE::COMMAND_LOGOUT);
            std::string logoutMessage = (stringManager.getString(Internationalization::STRING_CODE::IDLE_FOR_TOO_LONG) +
                                         extractCommands(element, fullCommand));
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
