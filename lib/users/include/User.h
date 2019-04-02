#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include <queue>




namespace user {

class User {
public:
    enum class USER_ROLE : uint8_t {
      ADMIN,
      NORMAL_USER
    };

    User(const std::string &name, const std::string &password);  
    ~User();
    
    std::string getUserName() const;

    USER_ROLE getRole() const;
    void setRole(USER_ROLE newRole){
        role = newRole;
    };

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
    std::string name;    
    std::string password;

    std::vector<std::string> messages;
    std::deque<std::vector<std::string>> commands;

    USER_ROLE role;
    
    

    long timeStamp;
    
    void init();  
    void test();

};
    
}

#endif
