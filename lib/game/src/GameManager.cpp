#include <unordered_map>
#include <iostream>
#include <string>
#include "GameManager.h"
#include "AccountManager.h"
#include "User.h"
#include "OnlineUserManager.h"
#include <boost/algorithm/string.hpp>
#include "Avatar.h"
#include "LocationCoordinates.h"

using usermanager::OnlineUserManager;
using accountmanager::AccountManager;

//global user to test
User dummy{"bob","123"};

GameManager::GameManager() {
    WorldManager newWorld;
    world = &newWorld;
    world->generateWorld();

    createTableOfCommands();
}

void GameManager::createTableOfCommands() {
    commandGuideline login = {&GameManager::commandLogin, &GameManager::commandError, 2, 0, " [username] [password]"};
    commandGuideline logout = {&GameManager::commandLogout, &GameManager::commandError, 0, 0, ""};
    commandGuideline create = {&GameManager::commandCreate, &GameManager::commandError, 2, 0, " [username] [password]"};
    commandGuideline say = {&GameManager::commandAddToActionList, &GameManager::commandSay, 0, 1, ": [message]"};
    commandGuideline yell = {&GameManager::commandAddToActionList, &GameManager::commandYell, 0, 1, ": [message]"};
    commandGuideline tell = {&GameManager::commandAddToActionList, &GameManager::commandTell, 1, 1, " [other-username]: [message]"};
    commandGuideline move = {&GameManager::commandAddToActionList, &GameManager::commandMove, 1, 0, " [direction]"};
    commandGuideline look = {&GameManager::commandAddToActionList, &GameManager::commandLook, 0, 0, ""};
    commandGuideline examine = {&GameManager::commandAddToActionList, &GameManager::commandExamine, 1, 0, " [object/username]"};
    commandGuideline help = {&GameManager::commandHelp, &GameManager::commandError, 0, 0, ""};
    
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

//tell a : a;

std::string GameManager::extractCommands(const std::string& connectionID, const std::string &fullCommand) {
    std::vector<std::string> commandParts, splitByColon;
    reassembleCommand(fullCommand, commandParts, splitByColon);

    auto found = tableOfCommands.find(commandParts[0]);
    if(found != tableOfCommands.end()) {
        commandGuideline guideline = found->second;
        if (commandIsValid(commandParts.size(), splitByColon.size(), guideline))
            return (this->*guideline.promptReply)(connectionID, commandParts);
        else {
            std::ostringstream answer;
            answer << "Invalid command. Command syntax: " << commandParts[0] << guideline.helpText << "\n";
            return answer.str();
        }
    }
    return "Command not found\n";
}

void GameManager::reassembleCommand(std::string fullCommand, std::vector<std::string>& commandParts, std::vector<std::string>& splitByColon) {
    //Format: <command> <arg> : <optional-text-message> 
    boost::trim_if(fullCommand, boost::is_any_of(" \t"));
    boost::split(splitByColon, fullCommand, boost::is_any_of(":"), boost::token_compress_on);
   
       //trim any space before and after ":"
    for(auto& text : splitByColon) {
        boost::trim_if(text, boost::is_any_of(" \t"));
    }
    boost::split(commandParts, splitByColon[0], boost::is_any_of(" \t"), boost::token_compress_on);

    //reassemble
    for(auto& text : splitByColon) {
        commandParts.push_back(text);
    }
}

bool GameManager::commandIsValid(size_t commandPartsSize, size_t splitByColon, commandGuideline guideline) {
    if(guideline.commandPartArgCount != commandPartsSize - 1 - splitByColon)
        return false;
    if(guideline.messagePartArgCount != splitByColon - 1)
        return false;
    return true;
}
/*
void testAccountManager(){
    std::cout << "*** AccountManager TEST ***\n";
    
    AccountManager accountManager{};
    std::string userName = "user9";
    std::string pwd = "pwd";
    std::string id = "123";

    assert( accountManager.createUser(userName, pwd) == AccountManager::ACCOUNT_CODE::ACCOUNT_CREATED);
    // assert( accountManager.login("123","user","test") == AccountManager::ACCOUNT_CODE::INVALID_PASSWORD);
    assert( accountManager.login(id,userName,pwd) == AccountManager::ACCOUNT_CODE::SUCCESFUL_LOGIN);
    assert( accountManager.login(id,userName,pwd) == AccountManager::ACCOUNT_CODE::USER_ALREADY_LOGGED_IN);

}
*/
std::string GameManager::commandLogin(const std::string& connectionID, const std::vector<std::string>& fullCommand) {
    /*try {
        long int id = std::stol(connectionID, nullptr, 10);
        dummyUser.setId(id);
    }catch (std::out_of_range& e){
        return connectionID;
    }*/

    AccountManager accountManager;
    auto answer = accountManager.login(connectionID, fullCommand[0], fullCommand[1]);
    switch(answer) {
        case accountmanager::AccountManager::ACCOUNT_CODE::SUCCESFUL_LOGIN:
            return "You are now logged in.\n";
        case accountmanager::AccountManager::ACCOUNT_CODE::USER_NOT_FOUND:
            return "Error! Username not found. Please try again.\n";
        case accountmanager::AccountManager::ACCOUNT_CODE::USER_ALREADY_LOGGED_IN:
            return "Error! You are already logged in.\n";
        case accountmanager::AccountManager::ACCOUNT_CODE::USER_NOT_ONLINE:
        case accountmanager::AccountManager::ACCOUNT_CODE::USER_LOGGED_OUT:
        case accountmanager::AccountManager::ACCOUNT_CODE::INVALID_USERNAME:
        case accountmanager::AccountManager::ACCOUNT_CODE::INVALID_PASSWORD:
        case accountmanager::AccountManager::ACCOUNT_CODE::ACCOUNT_CREATED:
            ;
    }
    //swallow
    return "";
}

std::string GameManager::commandLogout(const std::string& connectionID, const std::vector<std::string>& fullCommand) {
    AccountManager accountManager;
    auto answer = accountManager.logOut(connectionID);
    switch(answer) {
        case accountmanager::AccountManager::ACCOUNT_CODE::USER_LOGGED_OUT:
            return "You are now logged out.\n";
        case accountmanager::AccountManager::ACCOUNT_CODE::USER_NOT_ONLINE:
            return "Error! You are not logged in.\n";
        case accountmanager::AccountManager::ACCOUNT_CODE::USER_ALREADY_LOGGED_IN:
        case accountmanager::AccountManager::ACCOUNT_CODE::USER_NOT_FOUND:
        case accountmanager::AccountManager::ACCOUNT_CODE::SUCCESFUL_LOGIN:
        case accountmanager::AccountManager::ACCOUNT_CODE::INVALID_USERNAME:
        case accountmanager::AccountManager::ACCOUNT_CODE::INVALID_PASSWORD:
        case accountmanager::AccountManager::ACCOUNT_CODE::ACCOUNT_CREATED:
            ;
    }
    //swallow
    return "";
}

std::string GameManager::commandCreate(const std::string& connectionID, const std::vector<std::string>& fullCommand) {
    AccountManager accountManager;
    auto answer = accountManager.createUser(fullCommand[0], fullCommand[1]);
    switch(answer) {
        case accountmanager::AccountManager::ACCOUNT_CODE::INVALID_USERNAME:
            return "Error! Invalid username.\n";
        case accountmanager::AccountManager::ACCOUNT_CODE::INVALID_PASSWORD:
            return "Error! Invalid password.\n";
        case accountmanager::AccountManager::ACCOUNT_CODE::ACCOUNT_CREATED:
            return "Account created. Please log in to play the game.\n";
        case accountmanager::AccountManager::ACCOUNT_CODE::SUCCESFUL_LOGIN:
        case accountmanager::AccountManager::ACCOUNT_CODE::USER_NOT_FOUND:
        case accountmanager::AccountManager::ACCOUNT_CODE::USER_ALREADY_LOGGED_IN:
        case accountmanager::AccountManager::ACCOUNT_CODE::USER_NOT_ONLINE:
        case accountmanager::AccountManager::ACCOUNT_CODE::USER_LOGGED_OUT:
            ;
    }
    //swallow
    return "";
}

std::string GameManager::commandAddToActionList(const std::string& connectionID, const std::vector<std::string>& fullCommand) {
    // std::string combined;
    // for (const auto &commandPart : fullCommand){
    //     combined += commandPart;
    //     combined += " ";
    // }
    dummy.addCommandToList(fullCommand);
    auto& commands = dummy.getCommands();
    std::cout<<commands.size()<<"\n";
    return "command-add-test\n";
}

std::string GameManager::commandHelp(const std::string& connectionID, const std::vector<std::string>& fullCommand) {
    std::ostringstream answer;
    answer << "--------------------------------------------------\n";
    answer << "Supported commands: \n";
    for (const auto& [command, guideline] : tableOfCommands) {
        answer << command << guideline.helpText << std::endl;
    }   
    return answer.str();
}

std::string GameManager::commandSay(User* user, const std::vector<std::string>& fullCommand) {
    Avatar avatar = user->getAvatar();
    return world->say(&avatar, fullCommand[1]);
}

std::string GameManager::commandYell(User* user, const std::vector<std::string>& fullCommand) {
    /* Waiting for implementation in WorldManager
    Avatar avatar = user->getAvatar();
    return world->say(&avatar, fullCommand[1]);
    */
    return "test-yell";
}

std::string GameManager::commandTell(User* user, const std::vector<std::string>& fullCommand){
    /* Waiting for implementation in WorldManager, AccountManager, UserManager
    Avatar speaker = user->getAvatar();

    auto listenerUser = getUser(fullCommand[1]);
    if(listenerUser == nullptr) {
        return "Invalid name";
    }
    Avatar listener = listenerUser->getAvatar();

    return world->say(&speaker, &listener, fullCommand[2]);
    */
    return "test-tell";
}

std::string GameManager::commandMove(User* user, const std::vector<std::string>& fullCommand) {
    Avatar avatar = user->getAvatar();
    /* Change API to accept raw string
    LocationCoordinates newLocation = world->move(&avatar, fullCommand[1]);
    std::ostringstream answer;
    answer << "Current location: Area:" << newLocation.area << ", Room: " << newLocation.room << "\n";
    return answer */
    return "test-move";
}

std::string GameManager::commandLook(User* user, const std::vector<std::string>& fullCommand) {
    Avatar avatar = user->getAvatar();
    return world->look(&avatar);
}

std::string GameManager::commandExamine(User* user, const std::vector<std::string>& fullCommand) {
    Avatar avatar = user->getAvatar();
    return world->look(&avatar, fullCommand[1]);
}

std::string GameManager::commandError(User* user, const std::vector<std::string>& fullCommand){
    //Intended to be a null-function. Normally it should never reach this.
    return "";
}




std::unique_ptr<std::unordered_map<std::string, std::string>> GameManager::heartbeat() {
    auto map = std::make_unique<std::unordered_map<std::string, std::string>>();
    /*TODO:
        Get list of top commands of all online users
        Loop through and process each command
        Gather return messages and put in the table
       */

/*
    User *currentUser = &dummyUser;
    std::string userID;
    try {
        userID = std::to_string(currentUser->getId());
    }catch(std::out_of_range& e){
        std::cout << e.what();
        return map;
    }

    auto commandQueue = currentUser->getCommands();
    if(!commandQueue.empty()){
        const auto commandParts = commandQueue.front();
        const auto commandName = commandParts.at(0);

        auto found = tableOfCommands.find(commandName);
        commandGuideline guideline = found->second;
        //calls the command function
        (this->*guideline.heartbeatReply)(currentUser, commandParts);

        const auto userMessage = commandName + "\n";

        map->insert({userID, userMessage});
        currentUser->popCommand();
    }
*/
    return std::move(map);
}

//This should just return a User object
User* GameManager::getUser(const std::string& userName) const {
    User user{"",""};
    //AccountManager accountManager;
    //auto user = accountManager.findByUsername(userName);
    return &user; //Note: nullptr = not online, processed in the upper level


}


/*
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
