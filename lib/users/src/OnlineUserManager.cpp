#include <iostream>
#include <unordered_map> 
#include <string>
#include <boost/algorithm/string.hpp>
#include "OnlineUserManager.h"
#include "User.h"

using user::User;
using usermanager::OnlineUserManager;

bool OnlineUserManager::insertUser(const std::string &id, const User &user){
    bool result = onlineUsers.insert(std::make_pair(id, user)).second;
    return result;
}

User OnlineUserManager::removeUser(const std::string& id){
    auto search = onlineUsers.find(id);
    if (search != onlineUsers.end()) {
        onlineUsers.erase(id);
        return search->second;
    }else{
        User user {"",""};
        return user;
    }
}

User& OnlineUserManager::getUserById(const std::string& id){
    auto search = onlineUsers.find(id);
    if (search != onlineUsers.end()) {
        return search->second;
    }else{
        User user {"",""};
        return user;
    }
}

User& OnlineUserManager::getUserByUsername(const std::string& userName){
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

bool OnlineUserManager::updateUserTimeStamp(const std::string& id, const long timeStamp) {
    auto user = getUserById(id);
    if(user.getUserName() != "") {
        user.setTimeStamp(timeStamp);
        return true;
    }
    return false;
}

void OnlineUserManager::printTable() {
    for(auto& p: onlineUsers){
        std::cout << p.first << " => " << p.second.getUserName() << " "
                  << p.second.getId() << " " << p.second.getMessageSize() << "\n";
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


void OnlineUserManager::addMessage(const std::string& userName, const std::string& message) {
    std::cout << userName << "\n";
	auto& user = getUserByUsername(userName);
    if(user.getUserName() != ""){
        user.addMessage(message);
    }

}

bool OnlineUserManager::onlineUserAddCommandToList(const std::string& id, const std::vector<std::string>& command){
    auto user = getUserById(id);
    if(user.getUserName() != "") {
        user.addCommandToList(command);
        return true;
    }
    return false;
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




