#include <string>
#include <boost/algorithm/string.hpp>
#include <vector>
#include <exception>
#include "GameManager.h"
#include "../usermanager/include/UserManager.h"
#include "../usermanager/include/User.h"

using namespace std;

GameManager* GameManager::instance = 0; //set to null, will be initialized on demand

GameManager* GameManager::getInstance() {
    if (instance == 0) {
        GameManager newInstance;
        instance = &newInstance;
    }
	return instance;
}

GameManager::GameManager() {
	WorldManager newWorld;
	world = &newWorld;
	world->generateWorld();
}

std::string GameManager::extractCommands(const std::string fullMessage) const {
	std::vector<std::string> messageParts;
	boost::split(messageParts, fullMessage, boost::is_any_of(" "));

	try {
		auto command = messageParts.at(0);
		std::string result;

		//will be converted into array of functions later once we have finalized the commands
		//since different commands require different ways to deal with
		if(command == "LogIn") {
			auto username = messageParts.at(1);
			auto password = messageParts.at(2);

			usermanager::UserManager userManager;
			//auto answer = userManager.login(username, password);
			//return answer;

			return "test";
		}
		else if(command == "CreateAcc") {
	        auto username = messageParts.at(1);
			auto password = messageParts.at(2);

			usermanager::UserManager userManager;
			//auto answer = userManager.createUser(username, password);
			//return answer;

			return "test";
		}
		else if(command == "Move") {
			auto user = getUser(messageParts.at(1));
			auto direction = messageParts.at(2);

			if(user == nullptr) {
				result = "Please log in to play.";
			}
			else {
				result = "Moved to ";
				result.append(std::to_string(world->move(user, 0)));
			}
		}
		else if(command == "Look") {
			result = world->look(0);
		}

		return result;
	}
	catch (exception& e) {
		return "Invalid command. Please try again.";
	}
}

void GameManager::heartbeat() const {
	//fill this
}

User* GameManager::getUser(const std::string userName) const {
	return nullptr;
	//need function User* getUserByUsername(string username) in UserManager API
}
