#include <iostream>
#include <unordered_map> 
#include <string>
#include <boost/algorithm/string.hpp>
#include "OnlineUserManager.h"
#include "User.h"

using user::User;
using usermanager::OnlineUserManager;

bool OnlineUserManager::insertUser(const std::string &id, const User &user){
    return onlineUsers.insert(std::make_pair(id, user)).second;
}

User OnlineUserManager::removeUser(const std::string& id){
    auto search = onlineUsers.find(id);
    if (search != onlineUsers.end()) {
        onlineUsers.erase(id);
        return search->second;
    }else{
        return User{"",""};
    }
}

User OnlineUserManager::getUserById(const std::string& id){
    auto search = onlineUsers.find(id);
    if (search != onlineUsers.end()) {
        return search->second;
    }else{
        User user {"",""};
        return user;
    }
}

User OnlineUserManager::getUserByUsername(const std::string& userName){
    for (auto &element : onlineUsers) {
        if(element.second.getUserName() == userName) {
            return element.second;
        }
    }
    User user{"", ""};
    return user;
}

std::string OnlineUserManager::getConnectionID(const std::string& userName) {
	for (auto &element : onlineUsers) {
        if(element.second.getUserName() == userName) {
            return element.first;
        }
    }
    return "Invalid";
}

void OnlineUserManager::updateUserTimeStamp(const std::string& id, int timeStamp) {
    auto user = removeUser(id);
    user.setId(timeStamp);
    insertUser(id, user);
}

void OnlineUserManager::printTable() {
    for(auto& p: onlineUsers){
        std::cout << p.first << " => " << p.second.getUserName() << " "
                  << p.second.getId() << " " << p.second.getCommandSize() << "\n";
    }
}

std::vector<std::pair<std::string, std::string>> OnlineUserManager::getOnlineUserMessageList() {

	std::vector<std::pair<std::string, std::string>> messageList;

	for (auto &element : onlineUsers) {
        auto messageQueue = element.second.getMessages();
        if(messageQueue.size() > 0) {
        	std::string returnMessage = "";
        	for(auto& message: messageQueue) {
        		returnMessage.append(message);
        	}      
            messageList.push_back(std::make_pair(element.first, returnMessage));
        }
    }

    return std::move(messageList);
}


void OnlineUserManager::addMessage(const std::string& userName, const std::string& message) {
	for (auto &element : onlineUsers) {
        if(element.second.getUserName() == userName) {
            element.second.addMessage(message);
            return;
        }
    }
}

bool OnlineUserManager::onlineUserAddCommandToList(const std::string& id, const std::vector<std::string>& command){
    //auto commandUser = getUserByUsername(userName);
	auto search = onlineUsers.find(id);
	if(search != onlineUsers.end()) {
		search->second.addCommandToList(command);
		return true;
	}
	return false;

/*
    for (auto &element : onlineUsers) {
        if(element.second.getUserName() == userName) {
            element.second.addCommandToList(commands);
            return;
        }
    }
*/
    /*std::vector<std::string> commandParts;
    boost::split(commandParts, command, boost::is_any_of(" "));

    for(auto& value: commandParts) {
        boost::trim(value);
    }
    onlineUserCommandsList.insert(std::make_pair(userName, commandParts)).second;
     */
}

std::vector<std::pair<User, std::vector<std::string>>> OnlineUserManager::getOnlineUserCommandList() {
    std::vector<std::pair<User, std::vector<std::string>>> commandList;
    for (auto &element : onlineUsers) {
        auto currentUser = element.second;
        if(currentUser.getCommandSize() > 0) {
            auto fullCommand = element.second.popCommand();
            auto userCommandPair = std::make_pair(currentUser, fullCommand);

            commandList.push_back(userCommandPair);
        }
    }

    return std::move(commandList);
}

/*std::unordered_map<std::string, std::vector<std::string>>& OnlineUserManager::getOnlineUserCommandList() {
    return onlineUserCommandsList;
}*/




// ******* Functions that Uses UserDB *******

OnlineUserManager::USER_CODE OnlineUserManager::login(const std::string& userName, const std::string& pwd, const std::string& id){

    User user = userDB.getUser(userName,pwd);
    if(user.getUserName() != ""){
        onlineUsers.insert(std::make_pair(id, user));
        return OnlineUserManager::USER_CODE::USER_LOGGED_IN;
    }
    else{
        return OnlineUserManager::USER_CODE::USER_NOT_FOUND;
    }
}

OnlineUserManager::USER_CODE OnlineUserManager::logout(const std::string& userName, const std::string& id){
    
    //update the user in DB
    auto search = onlineUsers.find(id);
    if (search != onlineUsers.end()) {
        
        onlineUsers.erase(id);
        userDB.updateUser(search->second);

        return OnlineUserManager::USER_CODE::USER_LOGGED_OUT;
    }else{
        return OnlineUserManager::USER_CODE::USER_NOT_FOUND;
    }
} 

UserDB::DB_CODE OnlineUserManager::createUser(const std::string& userName, const std::string& pwd){
    return userDB.createUser(userName, pwd);
}      


