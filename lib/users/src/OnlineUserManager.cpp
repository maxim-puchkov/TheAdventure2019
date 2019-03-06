#include <iostream>
#include <unordered_map> 
#include <string>
#include <boost/algorithm/string.hpp>
#include "OnlineUserManager.h"
#include "User.h"

using user::User;
using usermanager::OnlineUserManager;

bool OnlineUserManager::insertUser(const std::string &id, const User &user){
    if (getUserByUsername(user.getUserName()) != nullUser) return false;
    bool result = onlineUsers.insert(std::make_pair(id, user)).second;
    return result;
}

User OnlineUserManager::removeUser(const std::string& id){
    auto search = onlineUsers.find(id);
    if (search != onlineUsers.end()) {
        onlineUsers.erase(id);
        return search->second;
    }else{
        return nullUser;
    }
}

User& OnlineUserManager::getUserById(const std::string& id){
    auto search = onlineUsers.find(id);
    if (search != onlineUsers.end()) {
        return search->second;
    }else{
        return nullUser;
    }
}

User& OnlineUserManager::getUserByUsername(const std::string& userName){
    for (auto &element : onlineUsers) {
        if(element.second.getUserName() == userName) {
            return element.second;
        }
    }
    return nullUser;
}

Avatar& OnlineUserManager::getAvatarById(const std::string& id){
    auto& search = getUserById(id);
    if(search.getUserName() != "") {
    	return search.getAvatar();
    }
    return nullAvatar;
}

Avatar& OnlineUserManager::getAvatarByUsername(const std::string& userName){
    auto& search = getUserByUsername(userName);
    if(search.getUserName() != "") {
    	return search.getAvatar();
    }
    return nullAvatar;
}

std::string OnlineUserManager::getConnectionID(const std::string& userName) {
	for (auto &element : onlineUsers) {
        if(element.second.getUserName() == userName) {
            return element.first;
        }
    }
    return "Invalid";
}

bool OnlineUserManager::updateUserTimeStamp(const std::string& id, const long timeStamp) {
    std::cout << "connection id to update: " << id;
    std::cout << "\n";
    auto &user = getUserById(id);
    if(user.getUserName() != "") {
        user.setTimeStamp(timeStamp);
        return true;
    }
    return false;
}

void OnlineUserManager::printTable() {
    for(auto& p: onlineUsers){
        std::cout << p.first << " => " << p.second.getUserName() << "\n";
        auto message = p.second.getMessages();
        for(auto& m: message) {
            std::cout << m <<" ";
        }
        std::cout <<"\n";
    }
}

std::vector<std::pair<std::string, std::string>> OnlineUserManager::getOnlineUserMessageList() {

	std::vector<std::pair<std::string, std::string>> messageList;

	for (auto &element : onlineUsers) {
        //get the gut of user Messages Vector
        auto messageQueue = std::move (element.second.getMessages());
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


bool OnlineUserManager::addMessageToUser(const std::string& userName, const std::string& message) {
	auto& user = getUserByUsername(userName);
    if(user.getUserName() != ""){
        user.addMessage(message);
        return true;
    }
    return false;
}

bool OnlineUserManager::onlineUserAddCommandToList(const std::string& id, const std::vector<std::string>& command){
    auto search = onlineUsers.find(id);
    if (search != onlineUsers.end()) {
        search->second.addCommandToList(command);
        return true;
    }else{
        return false;
    }

}

std::vector<std::pair<std::string, std::vector<std::string>>> OnlineUserManager::getOnlineUserCommandList() {
    std::vector<std::pair<std::string, std::vector<std::string>>> commandList;
    for (auto &element : onlineUsers) {
        auto& currentUser = element.second;
        if(currentUser.getCommandSize() > 0) {
            auto fullCommand = currentUser.popCommand();
            auto userCommandPair = std::make_pair(currentUser.getUserName(), fullCommand);

            commandList.push_back(userCommandPair);
        }
    }

    return std::move(commandList);
}

void OnlineUserManager::removeUnactiveUser(){
    if(onlineUsers.size() != 0) {
        auto user = onlineUsers.begin()->second;
        auto timeStamp = user.getTimeStamp();
        for (auto &element : onlineUsers) {
            if(element.second.getTimeStamp() < timeStamp) {
                user = element.second;
                timeStamp = user.getTimeStamp();
            }
        }
        std::cout << "Username: " << user.getUserName();
        std::cout << "\n";
        std::cout << "Timestamp: " << user.getTimeStamp();
        std::cout << "\n";
    }
}





// ******* Functions that Uses UserDB *******

OnlineUserManager::USER_CODE OnlineUserManager::login(const std::string& id, const std::string& userName, const std::string& pwd){
    auto user = userDB.getUser(userName,pwd);
    if(user.getUserName() != ""){
        if(!insertUser(id, user)){
            return OnlineUserManager::USER_CODE::USER_ALREADY_LOGGED_IN;
        }
        onlineUsers.insert(std::make_pair(id, user));
        return OnlineUserManager::USER_CODE::USER_LOGGED_IN;
    }
    else{
        return OnlineUserManager::USER_CODE::USER_NOT_FOUND;
    }

}

OnlineUserManager::USER_CODE OnlineUserManager::logout(const std::string& id){
    
    //update the user in DB
    auto search = onlineUsers.find(id);
    if (search != onlineUsers.end()) {
        
        onlineUsers.erase(id);
        userDB.updateUser(search->second);

        return OnlineUserManager::USER_CODE::USER_LOGGED_OUT;
    }else{
        return OnlineUserManager::USER_CODE::USER_NOT_ONLINE;
    }
} 

UserDB::DB_CODE OnlineUserManager::createUser(const std::string& userName, const std::string& pwd){
    return userDB.createUser(userName, pwd);
}      


