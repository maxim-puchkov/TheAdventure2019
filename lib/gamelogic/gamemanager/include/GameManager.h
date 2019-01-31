//
// Created by john on 18/01/19.
//

#ifndef WEBSOCKETNETWORKING_GAMEMANAGER_H
#define WEBSOCKETNETWORKING_GAMEMANAGER_H

#include <string>
#include <boost/algorithm/string.hpp>
#include <vector>
#include <exception>
#include <iostream>
#include <unordered_map>

#include "WorldManager.h"
#include "AccountManager.h"
#include "User.h"

class GameManager{

private:
    WorldManager *world;
	user::User* getUser(const std::string userName) const;
	struct commandGuideline {
		std::string (GameManager::*promptReply)(std::string, std::vector<std::string>);
		void (GameManager::*heartbeatReply)(User*, std::vector<std::string>);
		size_t commandPartArgCount;
		size_t messagePartArgCount;
		std::string helpText;
	};
	std::unordered_map<std::string, commandGuideline> tableOfCommands;

	std::string commandLogin(std::string connectionID, std::vector<std::string> fullCommand);
	std::string commandLogout(std::string connectionID, std::vector<std::string> fullCommand);
	std::string commandCreate(std::string connectionID, std::vector<std::string> fullCommand);
	std::string commandAddToActionList(std::string connectionID, std::vector<std::string> fullCommand);
	std::string commandHelp(std::string connectionID, std::vector<std::string> fullCommand);
	
	void commandSay(User* user, std::vector<std::string> fullCommand);
	void commandYell(User* user, std::vector<std::string> fullCommand);
	void commandTell(User* user, std::vector<std::string> fullCommand);
	void commandMove(User* user, std::vector<std::string> fullCommand);
	void commandLook(User* user, std::vector<std::string> fullCommand);
	void commandExamine(User* user, std::vector<std::string> fullCommand); //can only examine users
	void commandError(User* user, std::vector<std::string> fullCommand);
	
	bool commandIsValid(size_t commandPartsSize, size_t messagePartSize, commandGuideline guideline);
	void reassembleCommand(std::string fullCommand, std::vector<std::string>& commandParts, std::vector<std::string>& splitByColon);
	void createTableOfCommands();

public:
    GameManager();
	std::string extractCommands(const std::string& connectionID, std::string fullCommand);
	std::unordered_map<std::string, std::string> heartbeat();
};

#endif //WEBSOCKETNETWORKING_GAMEMANAGER_H