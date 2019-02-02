#include <boost/algorithm/string.hpp>
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

void User::setId(int id){
    this->id = id;
}

int User::getId() {
    int myId = this->id;
    return myId;
}

void User::addMessage(std::string message) {
    messages.push(message);
}

std::queue<std::string>& User::getMessages() {
    return messages;
}

void User::addCommandToList(const std::string& command){
    std::vector<std::string> commandParts;
    boost::split(commandParts, command, boost::is_any_of(" "));

    for(auto& value: commandParts) {
        boost::trim(value);
    }
    commands.push(commandParts);
}

std::queue<std::vector<std::string>>& User::getCommands(){
    return commands;
}

void User::init() {
    
}

void User::test() {
    std::cout << "Debug: User " << this->name << " created\n";
}

