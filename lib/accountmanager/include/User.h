#ifndef USER_H
#define USER_H

#include <string>
#include "Avatar.h"

using std::string;

namespace user {

class User {
public:
    
    // First time logins
    User(const string &name, const string &password);
    
    // Returning players whose avatar exists
    User(const string &name, const string &password, const Avatar &avatar);
    
    ~User();
    
    string getUserName();
    
    /*
     
     void setUserName(string name);
     
     void setUserPassword(string password);
     
     string getUserPassword();
     
     */
    
private:
    
    void init();
    
    string name;
    
    string password;
    
    Avatar avatar;
    
    void test();
    
};
    
}

#endif
