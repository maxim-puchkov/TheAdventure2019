
#include "GameManager.h"


GameManager::GameManager() {
    WorldManager newWorld;
    world = newWorld;
    world.generateWorld();

    //temp dummy char setup
    Character* newCharacter = new Character();
    newCharacter->setCurrentLocation(0,0);
    this->dummyCharacter = newCharacter;
}

std::string GameManager::extractCommands(const std::string command) const {
    if(command.empty()) return command;
    std::vector<std::string> trimmed;
    boost::split(trimmed, command, boost::is_any_of(" "));
/*	hard coded data
	trimmed.at(0) = "LogIn";
	trimmed.at(1) = "User";
	trimmed.at(2) = "Pswd";
*/
    std::string result;

    if(trimmed.at(0) == "LogIn") {
        accountmanager::AccountManager manager;
        result = manager.login(trimmed.at(1), trimmed.at(2));
    }
    else if(trimmed.at(0) == "CreateAcc") {
        accountmanager::AccountManager manager;
        result = manager.createUser(trimmed.at(1), trimmed.at(2));
    }
    else if(trimmed.at(0) == "move") {
        LocationCoordinates movLoc = world.move(this->dummyCharacter, Exit::CardinalDirection::NORTH);
        result = "moved to: ";
        result.append(std::to_string(movLoc.area));
        result.append(", ");
        result.append(std::to_string(movLoc.room));
    }
    else if(trimmed.at(0) == "look") {
        //LocationCoordinates loc = this->dummyCharacter->getCurrentLocation();
        result = world.look(this->dummyCharacter);
    }
    result.append("\n");
    return result;
}

void GameManager::heartbeat() const {
    //fill this
}

User* GameManager::getUser(const std::string userName) const {
    return nullptr;
    //need function getUserByUsername(string username) in UserManager API
}

