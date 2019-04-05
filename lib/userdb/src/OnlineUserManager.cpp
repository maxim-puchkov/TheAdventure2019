#include <iostream>
#include <unordered_map> 
#include <string>
#include <chrono>
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

bool OnlineUserManager::checkUserIsOnline(const std::string &userName)  {
     auto &user = getUserByUsername(userName);
     return ( !(user == nullUser) );

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

//TODO: switch this to a type
std::string OnlineUserManager::getConnectionID(const std::string& userName) {
	for (auto &element : onlineUsers) {
        if(element.second.getUserName() == userName) {
            return element.first;
        }
    }
    return "Invalid";
}

std::string OnlineUserManager::getUsernameFromConnectionID(const std::string& connectionID){
    auto user = getUserById(connectionID);
	return user.getUserName();
}

long OnlineUserManager::currentTimeStamp(){
    auto now = std::chrono::system_clock::now();
    auto now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);
    auto epoch = now_ms.time_since_epoch();
    auto value = std::chrono::duration_cast<std::chrono::milliseconds>(epoch);
    long timeStamp = value.count();
    return timeStamp;
}

bool OnlineUserManager::updateUserTimeStamp(const std::string& id) {
    long timeStamp = currentTimeStamp();
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

bool sortFunction(User i, User j) {
    return i.getTimeStamp() < j.getTimeStamp();
}

// User who unactive for more than 300000 millisecond will be kicked
std::vector<std::string> OnlineUserManager::unactiveUser(){
    long currentTime = currentTimeStamp();
    long timeToKick = currentTime - 300000;
    std::vector<std::string> unactiveUserIDs;
    if(onlineUsers.size() != 0) {
        std::vector<User> listUsers;
        for (auto &element : onlineUsers) {
            listUsers.push_back(element.second);
        }
        std::sort(listUsers.begin(), listUsers.end(), sortFunction);
        for(auto& value: listUsers) {
            if(value.getTimeStamp() < timeToKick) {
                unactiveUserIDs.push_back(getConnectionID(value.getUserName()));
            }
        }
    }
    return unactiveUserIDs;
}

OnlineUserManager::USER_CODE OnlineUserManager::getUserRole(const std::string& username) {
    auto& user = getUserByUsername(username);
    if(user == nullUser) {
        return OnlineUserManager::USER_CODE::USER_NOT_FOUND;
    } else if (user.getRole() == User::USER_ROLE::ADMIN) {
        return OnlineUserManager::USER_CODE::USER_ADMIN;
    } else if (user.getRole() == User::USER_ROLE::NORMAL_USER) {
        return OnlineUserManager::USER_CODE::USER_NORMAL_USER;
    } else {
        //error state
        return OnlineUserManager::USER_CODE::INVALID_USERNAME;
    }
}



// ******* Functions that Uses UserDB *******

OnlineUserManager::USER_CODE OnlineUserManager::login(const std::string& id, const std::string& userName, const std::string& pwd){
    auto user = userDB.getUser(userName,pwd);
    if(user.getUserName() != ""){
        auto search = onlineUsers.find(id);
        if (search != onlineUsers.end()) {
            return OnlineUserManager::USER_CODE::USER_ALREADY_LOGGED_IN;
        }else{
            user.setTimeStamp(currentTimeStamp());
            insertUser(id, user);
            return OnlineUserManager::USER_CODE::USER_LOGGED_IN;
        }
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


