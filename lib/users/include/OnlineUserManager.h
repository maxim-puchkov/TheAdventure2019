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
        User getUserById(const std::string& id);
        User getUserByUsername(const std::string& userName);
        void onlineUserAddCommandToList(const std::string& userName, const std::vector<std::string>& commands);
        std::unordered_map<std::string, std::vector<std::string>> getOnlineUserCommandList() const ;
        //std::unordered_map<std::string, std::vector<std::string>>& getOnlineUserCommandList();
        void updateUserTimeStamp(const std::string& id, int timeStamp);
        void printTable();
};
}

#endif
