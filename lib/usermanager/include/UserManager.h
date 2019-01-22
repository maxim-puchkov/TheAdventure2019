#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "User.h"
#include <string>
#include <iostream> 
#include <unordered_map> 


using usermanager::User; 
namespace usermanager {

class UserManager {
  // private:
    
  //   std::unordered_map<std::string, User> usersDB;
  //   std::unordered_map<std::string, User> test;

  public:
    std::string login(std::string, std::string);

    std::string logOut(std::string, std::string);

    std::string createUser(std::string, std::string);

    bool isOnline();

    void updateOnlineStatus();
};
}

#endif