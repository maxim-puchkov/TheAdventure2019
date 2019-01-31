#ifndef ONLINE_USER_MANAGER_H
#define ONLINE_USER_MANAGER_H

#include <unordered_map> 
#include <string>
// #include "../../accountManager/include/User.h"
#include "User.h"

using user::User; 

namespace usermanager{
class OnlineUserManager{
    private:
        std::unordered_map<std::string, User> onlineUsers;
    public:
        bool inserUser(std::string id, const User& user);
        User removeUser(std::string id);
        User getUserById(std::string id);
        User getUserByUsername(std::string userName);
        void updateUserTimeStamp(std::string id, int timeStamp);
        void printTable();
};
}

#endif
