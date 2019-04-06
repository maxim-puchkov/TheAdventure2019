#include "GameManager.h"
#include <boost/algorithm/string.hpp>

GameManager::GameManager() {
    
    // Making the World using the JSON files
    AreaGenerator areaGen{};
    std::vector<std::string> areaJSONs = jsonParser.getFileNamesInPath("data/world");
    std::vector<Area> areas;

    for (auto filePath : areaJSONs){
        auto area = areaGen.getArea("data/world/" + filePath, characterManager, world.items);
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
    for(auto path: areaJSONs){
        std::cout<< "data/world/"+path << "\n";
    }
        

}

void GameManager::createTableOfCommands() {

#ifndef BUILD_ALL_TARGETS
    
    tableOfCommands.insert({stringManager.getString(Internationalization::STRING_CODE::COMMAND_HELP), make_unique<CommandHelp>(characterManager, onlineUserManager, world, stringManager)});
    tableOfCommands.insert({stringManager.getString(Internationalization::STRING_CODE::COMMAND_LOGIN), make_unique<CommandLogin>(characterManager, onlineUserManager, world, stringManager)});
    
    tableOfCommands.insert({stringManager.getString(Internationalization::STRING_CODE::COMMAND_TAKE), make_unique<CommandTake>(characterManager, onlineUserManager, world, stringManager)});

#else
    
    tableOfCommands.insert({stringManager.getString(Internationalization::STRING_CODE::COMMAND_HELP), make_unique<CommandHelp>(characterManager, onlineUserManager, world, stringManager)});
    tableOfCommands.insert({stringManager.getString(Internationalization::STRING_CODE::COMMAND_LOGIN), make_unique<CommandLogin>(characterManager, onlineUserManager, world, stringManager)});
    tableOfCommands.insert({stringManager.getString(Internationalization::STRING_CODE::COMMAND_LOGOUT), make_unique<CommandLogout>(characterManager, onlineUserManager, world, stringManager)});
    tableOfCommands.insert({stringManager.getString(Internationalization::STRING_CODE::COMMAND_CREATE_ACCOUNT), make_unique<CommandCreate>(characterManager, onlineUserManager, world, stringManager)});
    
    tableOfCommands.insert({stringManager.getString(Internationalization::STRING_CODE::COMMAND_CREATE_AVATAR), make_unique<CommandCreateAva>(characterManager, onlineUserManager, world, stringManager)});
    tableOfCommands.insert({stringManager.getString(Internationalization::STRING_CODE::COMMAND_EDIT_AVATAR), make_unique<CommandEditAva>(characterManager, onlineUserManager, world, stringManager)});

    tableOfCommands.insert({stringManager.getString(Internationalization::STRING_CODE::COMMAND_SAY), make_unique<CommandSay>(characterManager, onlineUserManager, world, stringManager)});
    tableOfCommands.insert({stringManager.getString(Internationalization::STRING_CODE::COMMAND_TELL), make_unique<CommandTell>(characterManager, onlineUserManager, world, stringManager)});
    tableOfCommands.insert({stringManager.getString(Internationalization::STRING_CODE::COMMAND_YELL), make_unique<CommandYell>(characterManager, onlineUserManager, world, stringManager)});
    
    tableOfCommands.insert({stringManager.getString(Internationalization::STRING_CODE::COMMAND_LOOK), make_unique<CommandLook>(characterManager, onlineUserManager, world, stringManager)});
    tableOfCommands.insert({stringManager.getString(Internationalization::STRING_CODE::COMMAND_EXAMINE), make_unique<CommandExamine>(characterManager, onlineUserManager, world, stringManager)});
    tableOfCommands.insert({stringManager.getString(Internationalization::STRING_CODE::COMMAND_MOVE), make_unique<CommandMove>(characterManager, onlineUserManager, world, stringManager, combatManager)});

    tableOfCommands.insert({stringManager.getString(Internationalization::STRING_CODE::COMMAND_CREATE_ROOM), make_unique<CommandCreateRoom>(characterManager, onlineUserManager, world, stringManager)});
    tableOfCommands.insert({stringManager.getString(Internationalization::STRING_CODE::COMMAND_EDIT_ROOM), make_unique<CommandEditRoom>(characterManager, onlineUserManager, world, stringManager)});
    
    tableOfCommands.insert({stringManager.getString(Internationalization::STRING_CODE::COMMAND_TAKE), make_unique<CommandTake>(characterManager, onlineUserManager, world, stringManager)});
    tableOfCommands.insert({stringManager.getString(Internationalization::STRING_CODE::COMMAND_USE), make_unique<CommandUse>(characterManager, onlineUserManager, world, stringManager)});
    tableOfCommands.insert({stringManager.getString(Internationalization::STRING_CODE::COMMAND_EQUIP), make_unique<CommandEquip>(characterManager, onlineUserManager, world, stringManager)});
    tableOfCommands.insert({stringManager.getString(Internationalization::STRING_CODE::COMMAND_DROP), make_unique<CommandDrop>(characterManager, onlineUserManager, world, stringManager)});
    tableOfCommands.insert({stringManager.getString(Internationalization::STRING_CODE::COMMAND_PUT), make_unique<CommandPut>(characterManager, onlineUserManager, world, stringManager)});

    tableOfCommands.insert({stringManager.getString(Internationalization::STRING_CODE::COMMAND_MINIGAME), make_unique<CommandMinigame>(characterManager, onlineUserManager, world, stringManager, combatManager)});

    tableOfCommands.insert({stringManager.getString(Internationalization::STRING_CODE::COMMAND_COMBAT), make_unique<CommandCombat>(characterManager, onlineUserManager, world, stringManager, combatManager)});
    tableOfCommands.insert({stringManager.getString(Internationalization::STRING_CODE::COMMAND_ATTACK), make_unique<CommandAttack>(characterManager, onlineUserManager, world, stringManager, combatManager)});
    tableOfCommands.insert({stringManager.getString(Internationalization::STRING_CODE::COMMAND_FLEE), make_unique<CommandFlee>(characterManager, onlineUserManager, world, stringManager, combatManager)});

    tableOfCommands.insert({stringManager.getString(Internationalization::STRING_CODE::COMMAND_CAST), make_unique<CommandCast>(characterManager, onlineUserManager, world, stringManager, combatManager)});
    tableOfCommands.insert({stringManager.getString(Internationalization::STRING_CODE::COMMAND_CREATE_ITEM), make_unique<CommandCreateItem>(characterManager, onlineUserManager, world, stringManager)});
    tableOfCommands.insert({stringManager.getString(Internationalization::STRING_CODE::COMMAND_DELETE_ROOM), make_unique<CommandDeleteRoom>(characterManager, onlineUserManager, world, stringManager)});
    tableOfCommands.insert({stringManager.getString(Internationalization::STRING_CODE::ADMIN), make_unique<CommandAdmin>(characterManager, onlineUserManager, world, stringManager)});

    
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
    //reduces all combat roundtimers and returns commands from all combats with 0 roundtime
    auto combatCommands = combatManager.resolveCombatStep();
    for (auto& element : combatCommands){
        auto& username = element.first;
        auto& command = element.second;
        if(command.empty()) continue;
        auto found = tableOfCommands.find(command[0]);
        if(found != tableOfCommands.end()) {
            found->second->executeCombatRound(username, command);
        }
        if(characterManager.spellCooldown(username) <= 0){
            if(characterManager.isSwapped(username)){
                auto& currentMatch = combatManager.getCombatWithPlayer(username);
                auto opponentName = currentMatch.getOpponent(username);
                characterManager.swapCharacters(username, opponentName);
                onlineUserManager.addMessageToUser(username, "You've returned to your original form.\n");
                onlineUserManager.addMessageToUser(opponentName, "You've returned to your original form.\n");
            }
            characterManager.resetSpellEffects(username);

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

    	//confuse spell application
    	const auto& username = onlineUserManager.getUsernameFromConnectionID(connectionID);
    	if(characterManager.isConfused(username)){
    	    message.pop_back();
    	    message.pop_back(); //remove \n
            message = characterManager.confuseMessage(message);
    	}

    	map->insert(make_pair(connectionID, message));
	}

    return std::move(map);
}
