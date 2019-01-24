
#include "GameManager.h"


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

	//temp dummy char setup
	Character dummy;
	dummy.setCurrentLocation(0,0);
	Character* newCharacter = &dummy;
	this->dummyCharacter = newCharacter;
}

std::string GameManager::extractCommands(const std::string command) const {
	std::vector<std::string> trimmed;
	boost::split(trimmed, command, boost::is_any_of(" "));
/*	hard coded data
	trimmed.at(0) = "LogIn";
	trimmed.at(1) = "User";
	trimmed.at(2) = "Pswd";
*/
	std::string result = command;
    result.append("\n");

	if(trimmed.at(0) == "LogIn") {
		accountmanager::AccountManager manager;
		User user = manager.login(trimmed.at(1), trimmed.at(2));
		if( user.getUserName().empty() ) {
			result = "Failed to log in";
		} else {
			result = "Succeeded to log in";
		}
	}
	else if(trimmed.at(0) == "CreateAcc") {
		accountmanager::AccountManager manager;
		User user = manager.createUser(trimmed.at(1), trimmed.at(2));
		if( user.getUserName().empty() ) {
			result = "Failed to create account";
		} else {
			result = "Account created";
		}
	}
	else if(trimmed.at(0) == "move") {
		if(world->move(this->dummyCharacter, 0)){
			result = "Move worked";
		}else{
			result = "Move failed";
		}
		//result = world->look(dummyCharacter->getCurrentLocation());
		/*User *user = getUser(trimmed.at(1));
		if( user->getUserName().empty() ) {
			result = "Invalid move";
		}
		else {
			//WorldManager manager;
			result = "Moved to ";
			result.append(std::to_string(world->move(user, 0)));
		}*/
	}
	else if(trimmed.at(0) == "look") {
		//WorldManager manager;
		result = world->look(dummyCharacter->getCurrentLocation());
	}

	return result;
}

void GameManager::heartbeat() const {
	//fill this
}

User* GameManager::getUser(const std::string userName) const {
	return nullptr;
	//need function getUserByUsername(string username) in UserManager API
}
