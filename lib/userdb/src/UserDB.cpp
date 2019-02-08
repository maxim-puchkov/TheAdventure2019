#include "UserDB.h"

UserDB::UserDB(){
    users_json = jsonParser.processJSON(json_filePath);
    if(users_json == nullptr){
        cout<< "In Account Manager Cons";
        std::ofstream("users.json");
    }
}

UserDB::~UserDB(){
    jsonParser.saveJSON(users_json, json_filePath);
}

UserDB::DB_CODE UserDB::createUser(const std::string& name, const std::string& pwd){
    if(users_json[name] != nullptr){
        return UserDB::DB_CODE::INVALID_USERNAME;
    }
    else{
        users_json[name]["password"] = pwd;
        cout << users_json << "\n";
        jsonParser.saveJSON(users_json, json_filePath);
        return UserDB::DB_CODE::ACCOUNT_CREATED;
    }
}

UserDB::DB_CODE UserDB::updateUser(User& user){

    if(users_json[user.getUserName()] != nullptr){
        return UserDB::DB_CODE::USER_NOT_FOUND;
    }
    else{
        // UPDATE THE USER IN DB HERE
        cout << users_json << "\n";
        jsonParser.saveJSON(users_json, json_filePath);
        return UserDB::DB_CODE::USER_UPDATED;
    }
}

User UserDB::getUser(const std::string& name, const std::string& pwd){

    if(users_json[name] != nullptr){
        return User{"",""};
    }
    else if (users_json[name]["password"] == pwd){
        // UPDATE when User Constructor changes and you want to get more than just name and pwd
        return User{name,pwd};
    }
}

UserDB::DB_CODE UserDB::deleteUser(const std::string& name){

    if(users_json.at(name) != nullptr){
        users_json.erase(name);
        return UserDB::DB_CODE::USER_DELETED;
    }else{
        return UserDB::DB_CODE::USER_NOT_FOUND;
    }
}
