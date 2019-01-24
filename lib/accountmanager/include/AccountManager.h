#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H

#include "User.h"
#include <string>
#include <iostream> 
#include <unordered_map> 


using user::User; 
namespace accountmanager {

class AccountManager {
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