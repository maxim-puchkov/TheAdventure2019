#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H

#include "User.h"
#include <string>
#include <iostream> 


using user::User; 
namespace accountmanager {

class AccountManager {
  public:
    enum class ACCOUNT_CODE : uint8_t {
      SUCCESFUL_LOGIN,    
      USER_NOT_FOUND,  
      USER_ALREADY_LOGGED_IN,
      USER_NOT_ONLINE,
      USER_LOGGED_OUT,
      INVALID_USERNAME,
      INVALID_PASSWORD,
      ACCOUNT_CREATED      
    };

  private:
    
    void processUsersJSON();
    void saveUsersJSON();

  public:
    AccountManager();
    ~AccountManager();
    ACCOUNT_CODE login(std::string id, std::string, std::string );

    ACCOUNT_CODE logOut(std::string);

    ACCOUNT_CODE createUser(std::string, std::string);

    bool isOnline();

    void updateOnlineStatus();
    // User* getOnlineUser(std::string);

    };
}

#endif