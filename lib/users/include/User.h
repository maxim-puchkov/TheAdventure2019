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
    User(const string &name, const string &password, Avatar &&avatar);
    
    ~User();
    
    string getUserName();
    Avatar getAvatar() const;

    void setId(long int id);
    long int getId();

    void addMessage(std::string message);

    std::queue<std::string>& getMessages();

    void addCommandToList(const std::vector<std::string>& command);

    std::queue<std::vector<std::string>>& getCommands();

    void popCommand();
    
    int getCommandSize();
private:
    //using as connection id
    long int id;

    std::queue<std::string> messages;
    std::queue<std::vector<std::string>> commands;
    
    std::string name;
    
    std::string password;
    
    Avatar avatar = Avatar(std::move(this->name));

};
    
}

#endif
