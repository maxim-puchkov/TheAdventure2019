#ifndef ONLINE_USER_MANAGER_H
#define ONLINE_USER_MANAGER_H

#include <unordered_map> 
#include <string>
#include <vector>
// #include "../../accountManager/include/User.h"
#include "User.h"

using user::User; 

namespace usermanager{
class OnlineUserManager{
    private:
        std::unordered_map<std::string, User> onlineUsers;
        //std::unordered_map<std::string, std::vector<std::string>> onlineUserCommandsList;
    public:
        bool insertUser(const std::string &id, const User &user);
        User removeUser(const std::string& id);
        User& getUserById(const std::string& id);
        User& getUserByUsername(const std::string& userName);
        std::string getConnectionID(const std::string& userName);
        bool onlineUserAddCommandToList(const std::string& id, const std::vector<std::string>& command);
        std::vector<std::pair<User, std::vector<std::string>>> getOnlineUserCommandList();
        std::vector<std::pair<std::string, std::string>> getOnlineUserMessageList();
        void addMessage(const std::string& userName, const std::string& message);
        //std::unordered_map<std::string, std::vector<std::string>>& getOnlineUserCommandList();
        bool updateUserTimeStamp(const std::string& id, const long timeStamp);
        void printTable();
};
}

#endif
