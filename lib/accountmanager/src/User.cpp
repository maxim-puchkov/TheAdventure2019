#include "User.h"
#include <iostream>

using user::User;
using std::string;

User::User(const string &name, const string &password) {
    this->name = name;
    this->password = password;
    this->avatar = Avatar(name);
    
    this->test();
}

User::User(const string &name, const string &password, const Avatar &avatar) {
    this->name = name;
    this->password = password;
    this->avatar = avatar;
    
    this->test();
}

User::~User() = default;

string User::getUserName() {
    return this->name;
}

void User::init() {
    
}

void User::test() {
    std::cout << "Debug: User " << this->name << " created\n";
}

/*
 void User::setUserName(string userName) {
 this->name = userName;
 }
 
 void User::setUserPassword(string password) {
 this->password = password;
 }
 
 string User::getUserPassword() {
 return this->password;
 }
 */
