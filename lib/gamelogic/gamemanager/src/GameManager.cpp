#include <string>
#include <boost/algorithm/string.hpp>
#include <vector>
#include <exception>
#include "GameManager.h"
#include "AccountManager.h"
#include "User.h"
#include "../../../usermanager/include/OnlineUserManager.h"

using namespace std;
using user::User;
using usermanager::OnlineUserManager;

using namespace accountmanager;

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

void testOnlineUser(){
	OnlineUserManager online{};
	User user1 {"user1", "123456"};
	User user2 {"user2", "123456"};
	User user3 {"user3", "123456"};
	User user4 {"user4", "123456"};
	user1.setRoomID(100);
	user2.setRoomID(50);
	user3.setRoomID(200);
	user4.setRoomID(12);

	online.inserUser("1", user1);
	online.inserUser("2", user2);
	online.inserUser("3", user3);
	online.inserUser("4", user4);

	online.printTable();

	// Removing user2
	online.removeUser("2");
	std::cout << "Table with user2 removed\n";
	online.printTable();

	//update timestamp user4
	online.updateUserTimeStamp("4", 1000);
	std::cout << "Table with user4 updated to 1000\n";
	online.printTable();

}

void testAccountManager(){
	AccountManager accountManager{};

	assert( accountManager.createUser("user", "pwd") == AccountManager::ACCOUNT_CODE::ACCOUNT_CREATED);

	// assert( accountManager.login("123","user","test") == AccountManager::ACCOUNT_CODE::INVALID_PASSWORD);

	assert( accountManager.login("123","user","pwd") == AccountManager::ACCOUNT_CODE::SUCCESFUL_LOGIN);
	assert( accountManager.login("123","user","pwd") == AccountManager::ACCOUNT_CODE::USER_ALREADY_LOGGED_IN);

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

			//auto answer = userManager.login(username, password);
			//return answer;
			return "test";
		}
		else if(command == "CreateAcc") {
	        auto username = messageParts.at(1);
			auto password = messageParts.at(2);

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
		}else if(command == "test") {
			testOnlineUser();
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
