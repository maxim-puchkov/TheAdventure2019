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

Avatar& User::getAvatar() {
    return avatar;
}

void User::setId(long int id){
    this->id = id;
}

long int User::getId() {
    long int myId = this->id;
    return myId;
}

void User::addMessage(std::string message) {
    messages.push_back(message);
}

std::deque<std::string> User::getMessages() {
    std::deque<std::string> result;
    std::swap(result, messages);
    return result;
}

void User::addCommandToList(std::vector<std::string> command){
    commands.push(command);
}

std::queue<std::vector<std::string>>& User::getCommands() {
    return commands;
}

std::vector<std::string> User::popCommand(){
    std::vector<std::string> command;
    if(!commands.empty()){
        command = commands.front();
        commands.pop();
    }
    return command;
}

int User::getCommandSize() const {
    return commands.size();
}

void User::init() {
    
}

void User::test() {
    std::cout << "Debug: User " << this->name << " created\n";
}

