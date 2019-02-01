#include "User.h"
#include <string>
#include "AccountManager.h"
#include "OnlineUserManager.h"
#include "JsonParser.h"

#include <iostream> 
#include <unordered_map>

#include "json.hpp"
#include <fstream>

using namespace std;
using nlohmann::json;
using user::User; 

using accountmanager::AccountManager;
using usermanager::OnlineUserManager;


    auto onlineUserMananger = OnlineUserManager();
    auto jsonParser = JsonParser();

    bool jsonProcessed = false;
    json users_json;
    std::string json_filePath = "/Users/ParmJohal/Desktop/373project/users.json";

    AccountManager::AccountManager(){
        users_json = jsonParser.processJSON(json_filePath);
        if(users_json == nullptr){
            cout << "BITCH";
        }
    }
    AccountManager::~AccountManager(){
        jsonParser.saveJSON(users_json, json_filePath);
    }

    AccountManager::ACCOUNT_CODE AccountManager::login(std::string& id, std::string& name, std::string& pwd){
        
        if(jsonProcessed == false){
            users_json = jsonParser.processJSON(json_filePath);
        }

        if((users_json[name]["password"] == pwd)){


            if(!onlineUserMananger.inserUser(id, User{name,pwd})){
                return AccountManager::ACCOUNT_CODE::USER_ALREADY_LOGGED_IN;
            }

            return AccountManager::ACCOUNT_CODE::SUCCESFUL_LOGIN;
        }
        else{
            cout << "Invalid Credentials: User not Found" << "\n";
            return AccountManager::ACCOUNT_CODE::USER_NOT_FOUND;

        }
    }

    AccountManager::ACCOUNT_CODE AccountManager::logOut(std::string& id){

        if ((onlineUserMananger.removeUser(id).getUserName() != "")) {
            //TODO: remove from onlineUsers
            return AccountManager::ACCOUNT_CODE::USER_LOGGED_OUT;
        }
        else {
            return AccountManager::ACCOUNT_CODE::USER_NOT_ONLINE; 
        }
    }

    AccountManager::ACCOUNT_CODE AccountManager::createUser(std::string& name, std::string& pwd){

        if(jsonProcessed == false){
            users_json = jsonParser.processJSON(json_filePath);
        }

        if(users_json[name] != nullptr){
            return AccountManager::ACCOUNT_CODE::INVALID_USERNAME;
        }
        else{
            users_json[name]["password"] = pwd;
            cout << users_json << "\n";
            jsonParser.saveJSON(users_json, json_filePath);
            return AccountManager::ACCOUNT_CODE::ACCOUNT_CREATED;
        }
    }

    bool AccountManager::isOnline(){
        return false;
    }

    void AccountManager::updateOnlineStatus(){
        std::cout << "checking" << "\n";
    }

    const OnlineUserManager& AccountManager::getUserManager(){
        return onlineUserMananger;
    }

    // User* AccountManager::getOnlineUser(std::string id){
        
    //     return &onlineUserMananger.getUser(id);
    // }
