#ifndef ONLINE_USER_MANAGER_H
#define ONLINE_USER_MANAGER_H

#include <unordered_map> 
#include <string>
#include <vector>
#include <chrono>
#include "User.h"
#include "UserDB.h"

using user::User; 

namespace usermanager{
class OnlineUserManager{
    public:
    enum class USER_CODE : uint8_t {
      INVALID_USERNAME,
      ACCOUNT_CREATED,
      USER_UPDATED,
      USER_DELETED,
      USER_NOT_FOUND, 
      USER_LOGGED_OUT,
      USER_LOGGED_IN,
      USER_ALREADY_LOGGED_IN,
      USER_NOT_ONLINE,
      USER_ADMIN,
      USER_NORMAL_USER
    };
    private:
        std::unordered_map<std::string, User> onlineUsers;
        UserDB userDB {};
        User nullUser{"", ""};

        User& getUserById(const std::string& id);
        
        
    public:
        User& getUserByUsername(const std::string& userName);
        bool insertUser(const std::string &id, const User &user);      
        User removeUser(const std::string& id);
        bool checkUserIsOnline(const std::string &userName);


        long currentTimeStamp();
        std::string getConnectionID(const std::string& userName);
        std::string getUsernameFromConnectionID(const std::string& connectionID);
        
        bool onlineUserAddCommandToList(const std::string& id, const std::vector<std::string>& command);
        std::vector<std::pair<std::string, std::vector<std::string>>> getOnlineUserCommandList();
        
        bool addMessageToUser(const std::string& userName, const std::string& message);
        std::vector<std::pair<std::string, std::string>> getOnlineUserMessageList();
        
        long getTimeStamp();
        bool updateUserTimeStamp(const std::string& id);
        std::vector<std::string> unactiveUser();
        
        USER_CODE getUserRole(const std::string& username);

        void printTable();


        // ******* Functions that Uses UserDB *******
        USER_CODE login(const std::string& userName, const std::string& pwd, const std::string& id);
        USER_CODE logout(const std::string& id);  
        UserDB::DB_CODE createUser(const std::string& userName, const std::string& pwd);
        void updateAdmin(const std::string& userName);

};
}

#endif
