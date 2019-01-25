#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H

#include "User.h"
#include <string>
#include <iostream> 
#include <unordered_map> 


using user::User; 
namespace accountmanager {

class AccountManager {
  public:
    enum class ACCOUNT_CODE : uint8_t {
      SUCCESFUL_LOGIN,    
      USER_NOT_FOUND,  
      USER_LOGGED_IN       
    };

  private:
    
    void processUsersJSON();

  public:
    ACCOUNT_CODE login(std::string, std::string );

    User logOut(std::string, std::string );

    User createUser(std::string, std::string );

    bool isOnline();

    void updateOnlineStatus();
    };
}

#endif