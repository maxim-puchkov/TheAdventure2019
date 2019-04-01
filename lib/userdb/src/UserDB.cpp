#include "UserDB.h"

UserDB::UserDB(){
    users_json = jsonParser.processJSON(json_filePath);
    // cout<< "USER DB CONS()\n";

    if(users_json == nullptr){
        cout<< "JSON NOT FOUND\n";
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
        users_json[name]["admin"] = false;
        // cout << users_json << "\n";
        jsonParser.saveJSON(users_json, json_filePath);
        return UserDB::DB_CODE::ACCOUNT_CREATED;
    }
}

UserDB::DB_CODE UserDB::updateUser(User& user){

    if(users_json[user.getUserName()] == nullptr){
        return UserDB::DB_CODE::USER_NOT_FOUND;
    }
    else{
        // UPDATE THE USER IN DB HERE

        // users_json[user.getUserName()]["password"] = user;
        if(user.getRole() == User::USER_ROLE::ADMIN){
            users_json[user.getUserName()]["admin"] = true;
        } else{
            users_json[user.getUserName()]["admin"] = false;
        }

        cout << users_json << "\n";
        jsonParser.saveJSON(users_json, json_filePath);
        return UserDB::DB_CODE::USER_UPDATED;
    }
}

User UserDB::getUser(const std::string& name, const std::string& pwd){
    if(users_json[name] == nullptr){
        return User{"",""};
    }
    if (users_json[name]["password"] == pwd){
        // UPDATE when User Constructor changes and you want to get more than just name and pwd
        cout<<"USER FOUND\n";
        
        User user{name,pwd};
        
        if(users_json[name]["admin"]){
            user.setRole(User::USER_ROLE::ADMIN);
        } else{
            user.setRole(User::USER_ROLE::NORMAL_USER);
        }
        return user;
    }else{
        return User{"",""};
    }
}

UserDB::DB_CODE UserDB::deleteUser(const std::string& name){

    if(users_json.at(name) != nullptr){
        users_json.erase(name);
        jsonParser.saveJSON(users_json, json_filePath);
        
        return UserDB::DB_CODE::USER_DELETED;
    }else{
        return UserDB::DB_CODE::USER_NOT_FOUND;
    }
}
