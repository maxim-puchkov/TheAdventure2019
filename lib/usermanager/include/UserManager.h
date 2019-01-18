#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <string>
#include <User.h>
#include <iostream> 
#include <unordered_map> 

class UserManager
{
  private:
    
    unordered_map<string, class User> usersDB;
    std::unordered_map<string, class User> test;

  public:
    class User login(std::string, std::string );

    class User logOut(std::string, std::string );

    class User createUser(std::string, std::string );

    bool isOnline();

    void updateOnlineStatus();
};

#endif