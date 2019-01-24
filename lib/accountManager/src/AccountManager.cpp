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

using accountManager::AccountManager;

    
    User fakeUser{"name", "password"};
    User nullUser{"", ""};

    unordered_map<string, User> usersDB = {{"name", fakeUser}};
    unordered_map<string, User> onlineUsers;

    User AccountManager::login(std::string name, std::string pwd){

        std::ifstream users_file("users.json");
        json users_json = json::parse(users_file);
        
        for(json tmp: users_json){
            
            usersDB.insert( pair<std::string,User>(name, User{name,pwd}) );

        }
        
        //Check if user is logged in in the usersDB
        auto search = usersDB.find(name);

        if (search != usersDB.end() && onlineUsers.find(name) == onlineUsers.end()) {

            // if they are logged in add to onlineUsers and return User
            onlineUsers.insert( pair<std::string,User>(name, search->second) );
            return search->second;
        }
        else{
            cout << "Invalid Credentials: User not Found" << "\n";
            return nullUser;
        }
    }

    User AccountManager::logOut(std::string name, std::string pwd){

        auto search = onlineUsers.find(name);

        if (search != onlineUsers.end()) {
            onlineUsers.erase(name);
            return search->second;
        }
        else{
            return nullUser;
        }

    }

    User AccountManager::createUser(std::string name, std::string pwd){

        auto search = usersDB.find(name);
        if(search != usersDB.end()){
            return nullUser;
        }
        else{
            User user(name,pwd);
            usersDB.insert( pair<std::string,User>(name, User{name,pwd}) );

            return user;
        }
    }

    bool AccountManager::isOnline(){
        return false;
    }

    void AccountManager::updateOnlineStatus(){
        std::cout << "checking" << "\n";

    }
