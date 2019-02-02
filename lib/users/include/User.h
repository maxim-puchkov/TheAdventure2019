#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include <queue>
#include "Avatar.h"




namespace user {

class User {
public:
    
    // First time logins
    User(const string &name, const string &password);
    
    // Returning players whose avatar exists
    User(const string &name, const string &password, const Avatar &avatar);
    
    ~User();
    
    string getUserName();

    void setId(int id);
    int getId();

    void addMessage(std::string message);

    std::queue<std::string>& getMessages();

    void addCommandToList(const std::string& command);

    std::queue<std::vector<std::string>>& getCommands();
    
    
private:
    //using as connection id
    int id;

    std::queue<std::string> messages;
    std::queue<std::vector<std::string>> commands;

    void init();
    
    std::string name;
    
    std::string password;
    
    Avatar avatar;
    
    void test();

};
    
}

#endif
