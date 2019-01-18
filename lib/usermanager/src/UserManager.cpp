#include "UserManager.h"
#include "User.h"
#include <string>
#include <iostream> 
#include <unordered_map> 
using namespace std;
using usermanager::User; 
using usermanager::UserManager;

    
    User fakeUser{"name", "password"};
    User nullUser{"", ""};

    unordered_map<string, User> usersDB = {{"name", fakeUser}};
    unordered_map<string, User> onlineUsers;


  
    User UserManager::login(std::string name, std::string pwd){
        
        //Check if user is logged in in the usersDB

        auto search = usersDB.find(name);
        if (search != usersDB.end() && onlineUsers.find(name) != onlineUsers.end()) {

            // if they are logged in add to onlineUsers and return User
            onlineUsers.insert( pair<std::string,User>(name, search->second) );
            return search->second;
        }
        else{
            cout << "Invalid Credentials: User not Found";
             return nullUser;
        }
    }

    User UserManager::logOut(std::string name, std::string pwd){

        auto search = onlineUsers.find(name);

        if (search != onlineUsers.end()) {
            onlineUsers.erase(name);
            return search->second;
        }
        else{
            return nullUser;
        }

    }

    User UserManager::createUser(std::string name, std::string pwd){

        auto search = usersDB.find(name);
        if(search == usersDB.end()){
            return nullUser;
        }
        else{
            User user(name,pwd);
            usersDB.insert( pair<std::string,User>(name, User{name,pwd}) );

            return user;
        }
    }

    bool UserManager::isOnline(){
        return false;
    }

    void UserManager::updateOnlineStatus(){
        std::cout << "checking" << "\n";

    }
