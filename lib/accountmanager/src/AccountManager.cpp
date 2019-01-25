#include "User.h"
#include <string>
#include "AccountManager.h"
#include "OnlineUserManager.h"

#include <iostream> 
#include <unordered_map>

#include "json.hpp"
#include <fstream>

using namespace std;
using nlohmann::json;
using user::User; 

using accountmanager::AccountManager;
using usermanager::OnlineUserManager;

    User fakeUser{"name", "password"};
    User nullUser{"", ""};

    unordered_map<string, User> usersDB = {{"name", fakeUser}};
    unordered_map<string, User> onlineUsers;

    auto onlineUserMananger = OnlineUserManager();

    bool jsonProcessed = false;
    json users_json;


    AccountManager::AccountManager(){
        processUsersJSON();
    }
    AccountManager::~AccountManager(){
        saveUsersJSON();
    }

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


            if(!onlineUserMananger.inserUser("testid", User{name,pwd})){
                return AccountManager::ACCOUNT_CODE::USER_LOGGED_IN;
            }

            return AccountManager::ACCOUNT_CODE::SUCCESFUL_LOGIN;
        }
        else{
            cout << "Invalid Credentials: User not Found" << "\n";
            return AccountManager::ACCOUNT_CODE::USER_NOT_FOUND;

        }
    }

    AccountManager::ACCOUNT_CODE AccountManager::logOut(std::string name, std::string pwd){
        auto search = onlineUsers.find(name);

        if ((onlineUserMananger.removeUser("test123").getUserName() == "")) {
            //TODO: remove from onlineUsers
            return AccountManager::ACCOUNT_CODE::USER_LOGGED_OUT;
        }
        else {
            return AccountManager::ACCOUNT_CODE::USER_NOT_ONLINE; 
        }
    }

    AccountManager::ACCOUNT_CODE AccountManager::createUser(std::string name, std::string pwd){

        if(jsonProcessed == false){
            processUsersJSON();
        }

        if((onlineUserMananger.getUser("test123").getUserName() == "")){
            return AccountManager::ACCOUNT_CODE::INVALID_USERNAME;
        }
        else{
            users_json[name]["password"] = pwd;
            cout << users_json << "\n";
            saveUsersJSON();
            return AccountManager::ACCOUNT_CODE::ACCOUNT_CREATED;
        }
    }

    bool AccountManager::isOnline(){
        return false;
    }

    void AccountManager::updateOnlineStatus(){
        std::cout << "checking" << "\n";
    }
