#include "User.h"
#include <string>
#include "AccountManager.h"

#include <iostream> 
#include <unordered_map>

#include "json.hpp"
#include <fstream>

using namespace std;
using nlohmann::json;
using user::User; 

using accountmanager::AccountManager;

    
    User fakeUser{"name", "password"};
    User nullUser{"", ""};

    unordered_map<string, User> usersDB = {{"name", fakeUser}};
    unordered_map<string, User> onlineUsers;

    std::string AccountManager::login(std::string name, std::string pwd){
        //Check if user is logged in in the usersDB
        auto resultUser = usersDB.find(name);

        if (resultUser != usersDB.end()) {
            //TODO: add to onlineUsers
            return "Welcome " + resultUser->second.getUserName() + "!";
        }
        else {
            return "Invalid Credentials: User not Found.";
        }



    }

    std::string AccountManager::logOut(std::string name, std::string pwd){
        auto search = onlineUsers.find(name);

        if (search != onlineUsers.end()) {
            //TODO: remove from onlineUsers
            return "You are logged out.";
        }
        else {
            return "Please login!"; //to log out lol
        }
    }

    std::string AccountManager::createUser(std::string name, std::string pwd){
        auto search = usersDB.find(name);
        if(search != usersDB.end()){
            return "Username already exits, Sorry! :(";
        }
        else{
            User user(name,pwd);
            usersDB.insert(pair<std::string,User>(name, User{name,pwd}));

            //TODO: add to onlineUsers
            return "User Created.";
        }
    }

    bool AccountManager::isOnline(){
        return false;
    }

    void AccountManager::updateOnlineStatus(){
        std::cout << "checking" << "\n";
    }
