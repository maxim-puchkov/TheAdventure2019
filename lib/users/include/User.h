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
    
    const string& getUserName() const;
    Avatar& getAvatar();

    void setId(long int id);
    long int getId();

    void addMessage(std::string message);

    std::vector<std::string>& getMessages();

    void addCommandToList(std::vector<std::string> command);

    std::deque<std::vector<std::string>>& getCommands();

    std::vector<std::string> popCommand();
    
    int getCommandSize() const;
    int getMessageSize() const;
    void setTimeStamp(const long timeStamp);
    long getTimeStamp();

    virtual bool operator==(const User &other);
    virtual bool operator!=(const User &other);
private:
    //using as connection id
    long int id;

    std::vector<std::string> messages;
    std::deque<std::vector<std::string>> commands;

    void init();
    
    std::string name;
    
    std::string password;

    long timeStamp;
    
    Avatar avatar;
    
    void test();

};
    
}

#endif
