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

    bool jsonProcessed = false;
    json users_json;

    void AccountManager::processUsersJSON(){

        try{
            std::ifstream users_file("/Users/ParmJohal/Desktop/373project/users.json");
            users_json << users_file;
        }
        catch(nlohmann::detail::type_error e){
            cout << e.what() << "\n";
        }
    }

    void saveUsersJSON(){
        std::ofstream file("/Users/ParmJohal/Desktop/373project/users.json");
        file << users_json;
    }

    AccountManager::ACCOUNT_CODE AccountManager::login(std::string name, std::string pwd){
        
        if(jsonProcessed == false){
            processUsersJSON();
        }

        if((users_json[name]["password"] == pwd)){

            // Insert into the usermanager hash table
            onlineUsers.insert( pair<std::string,User>(name, User{name,pwd}) );
            return AccountManager::ACCOUNT_CODE::SUCCESFUL_LOGIN;
        }
        else{
            cout << "Invalid Credentials: User not Found" << "\n";
            return AccountManager::ACCOUNT_CODE::USER_NOT_FOUND;
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

        if(jsonProcessed == false){
            processUsersJSON();
        }

        // TODO: REPLACE WITH NEW USERMANAGER CODE
        auto search = usersDB.find(name);
        if(search != usersDB.end()){
            return nullUser;
        }
        else{
            users_json[name]["password"] = pwd;
            cout << users_json << "\n";
            saveUsersJSON();
            return User{name,pwd};
        }
    }

    bool AccountManager::isOnline(){
        return false;
    }

    void AccountManager::updateOnlineStatus(){
        std::cout << "checking" << "\n";

    }
