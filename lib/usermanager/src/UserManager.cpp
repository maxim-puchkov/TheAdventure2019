#include <UserManager.h>
#include <string>
#include "User.h"
#include <iostream> 
#include <unordered_map> 
using namespace std;
using usermanager::User; 

class UserManager
{

  private:
    
    User fakeUser{"name", "password"};
    unordered_map<string, class User> usersDB = {{"name", fakeUser}};
    unordered_map<string, class User> onlineUsers;


  public:
    class User login(std::string name, std::string pwd){
        
        //Check if user is logged in in the usersDB

        auto search = usersDB.find(name);
        if (search != usersDB.end() && onlineUsers.find(name) != onlineUsers.end()) {

            // if they are logged in add to onlineUsers and return User
            onlineUsers[name] = search->second;
            return search->second;
        }
        else{
            cout << "Invalid Credentials: User not Found";
             return fakeUser;
        }
    }

    class User logOut(std::string name, std::string pwd){

        auto search = onlineUsers.find(name);

        if (search != onlineUsers.end()) {
            onlineUsers.erase(name);
            return search->second;
        }
        else{
            return fakeUser;
        }

    }

    class User createUser(std::string name, std::string pwd){

        auto search = usersDB.find(name);
        if(search == usersDB.end()){
            return fakeUser;
        }
        else{
            User user(name,pwd);
            usersDB[name] = user;
            return user;
        }
    }

    bool isOnline();

    void updateOnlineStatus();
};