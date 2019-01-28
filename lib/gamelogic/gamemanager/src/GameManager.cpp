
#include "GameManager.h"


GameManager::GameManager() {
	WorldManager newWorld;
	world = &newWorld;
	world->generateWorld();

    createTableOfCommands();
}

void GameManager::createTableOfCommands() {
    commandGuideline login = {&GameManager::commandLogin, &GameManager::commandError, 2, " <username> <password>"};
    commandGuideline logout = {&GameManager::commandLogout, &GameManager::commandError, 0, ""};
    commandGuideline create = {&GameManager::commandCreate, &GameManager::commandError, 2, " <username> <password>"};
    commandGuideline say = {&GameManager::commandAddToActionList, &GameManager::commandSay, 1, " \"<message>\""};
    commandGuideline yell = {&GameManager::commandAddToActionList, &GameManager::commandYell, 1, " \"<message>\""};
    commandGuideline tell = {&GameManager::commandAddToActionList, &GameManager::commandTell, 2, " <other-username> \"<message>\""};
    commandGuideline move = {&GameManager::commandAddToActionList, &GameManager::commandMove, 1, " <direction>"};
    commandGuideline look = {&GameManager::commandAddToActionList, &GameManager::commandLook, 0, ""};
    commandGuideline examine = {&GameManager::commandAddToActionList, &GameManager::commandExamine, 1, " <object/username>"};
    commandGuideline help = {&GameManager::commandHelp, &GameManager::commandError, 0, ""};
    
    tableOfCommands.insert({"log-in", login});
    tableOfCommands.insert({"log-out", logout});
    tableOfCommands.insert({"create-account", create});
    tableOfCommands.insert({"say", say});
    tableOfCommands.insert({"yell", yell});
    tableOfCommands.insert({"tell", tell});
    tableOfCommands.insert({"move", move});
    tableOfCommands.insert({"look", look});
    tableOfCommands.insert({"examine", examine});
    tableOfCommands.insert({"help", help});
}

std::string GameManager::extractCommands(const std::string connectionID, const std::string fullMessage) const {
    return "test";

}

std::string GameManager::commandLogin(std::string connectionID, std::string fullCommand) {
    return "test";
}

std::string GameManager::commandLogout(std::string connectionID, std::string fullCommand) {
    return "test";
}

std::string GameManager::commandCreate(std::string connectionID, std::string fullCommand) {
    return "test";
}

std::string GameManager::commandAddToActionList(std::string connectionID, std::string fullCommand) {
    return "test";
}

std::string GameManager::commandHelp(std::string connectionID, std::string fullCommand) {
    return "test";
}

void GameManager::commandSay(User* user, std::string fullCommand) {

}

void GameManager::commandYell(User* user, std::string fullCommand) {

}

void GameManager::commandTell(User* user, std::string fullCommand){

}

void GameManager::commandMove(User* user, std::string fullCommand) {

}

void GameManager::commandLook(User* user, std::string fullCommand) {

}

void GameManager::commandExamine(User* user, std::string fullCommand) {

}

void GameManager::commandError(User* user, std::string fullCommand){

}

bool GameManager::commandIsValid(std::string command, std::vector<std::string> args) {
    return true;
}


void GameManager::heartbeat() const {
	//fill this
}

User* GameManager::getUser(const std::string userName) const {
	return nullptr;
	//need function User* getUserByUsername(string username) in UserManager API
}
/*
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
                // result.append(std::to_string(world->move(user, 0)));
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
    }*/