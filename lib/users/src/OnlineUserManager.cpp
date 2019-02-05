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
        User user {"",""};
        return user;
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

void OnlineUserManager::updateUserTimeStamp(const std::string& id, int timeStamp) {
    auto user = removeUser(id);
    user.setId(timeStamp);
    insertUser(id, user);
}

void OnlineUserManager::printTable() {
    for(auto& p: onlineUsers){
        std::cout << p.first << " => " << p.second.getUserName() << " "
                  << p.second.getId() << "\n";
    }
}

void OnlineUserManager::onlineUserAddCommandToList(const std::string& userName, const std::vector<std::string>& commands){
    //auto commandUser = getUserByUsername(userName);

    for (auto &element : onlineUsers) {
        if(element.second.getUserName() == userName) {
            element.second.addCommandToList(commands);
            return;
        }
    }

    /*std::vector<std::string> commandParts;
    boost::split(commandParts, command, boost::is_any_of(" "));

    for(auto& value: commandParts) {
        boost::trim(value);
    }
    onlineUserCommandsList.insert(std::make_pair(userName, commandParts)).second;
     */
}

std::unordered_map<User, std::vector<std::string>>& OnlineUserManager::getOnlineUserCommandList() {
    std::unordered_map<User, std::vector<std::string>> commandMap;

    for (auto &element : onlineUsers) {
        auto& currentUser = element.second;
        if(currentUser.getCommandSize() > 0) {
            auto fullCommand = currentUser.getCommands().front();
            commandMap.insert(std::make_pair(currentUser, fullCommand));
            currentUser.getCommands().pop();
        }
    }

    return std::move(commandMap);
}

/*std::unordered_map<std::string, std::vector<std::string>>& OnlineUserManager::getOnlineUserCommandList() {
    return onlineUserCommandsList;
}*/

