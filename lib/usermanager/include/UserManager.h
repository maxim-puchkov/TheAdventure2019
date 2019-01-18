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
    User login(std::string, std::string );

    User logOut(std::string, std::string );

    User createUser(std::string, std::string );

    bool isOnline();

    void updateOnlineStatus();
};
}

#endif