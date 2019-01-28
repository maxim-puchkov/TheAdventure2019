//
// Created by john on 18/01/19.
//

#ifndef WEBSOCKETNETWORKING_GAMEMANAGER_H
#define WEBSOCKETNETWORKING_GAMEMANAGER_H

#include <string>
#include <boost/algorithm/string.hpp>
#include <vector>
#include <exception>

#include "WorldManager.h"
#include "AccountManager.h"
#include "User.h"

class GameManager{

private:
    WorldManager *world;
	user::User* getUser(const std::string userName) const;
	struct commandGuideline {
		std::string (GameManager::*promptReply)(std::string, std::string);
		void (GameManager::*heartbeatReply)(User*, std::string);
		int argCount;
		std::string helpText;
	};
	std::unordered_map<std::string, commandGuideline> tableOfCommands;

	std::string commandLogin(std::string connectionID, std::string fullCommand);
	std::string commandLogout(std::string connectionID, std::string fullCommand);
	std::string commandCreate(std::string connectionID, std::string fullCommand);
	std::string commandAddToActionList(std::string connectionID, std::string fullCommand);
	std::string commandHelp(std::string connectionID, std::string fullCommand);
	
	void commandSay(User* user, std::string fullCommand);
	void commandYell(User* user, std::string fullCommand);
	void commandTell(User* user, std::string fullCommand);
	void commandMove(User* user, std::string fullCommand);
	void commandLook(User* user, std::string fullCommand);
	void commandExamine(User* user, std::string fullCommand); //can only examine users
	void commandError(User* user, std::string fullCommand);
	
	bool commandIsValid(std::string command, std::vector<std::string> args);
	void createTableOfCommands();

public:
    GameManager();
	std::string extractCommands(const std::string connectionID, const std::string command);
	void heartbeat() const;
};

#endif //WEBSOCKETNETWORKING_GAMEMANAGER_H