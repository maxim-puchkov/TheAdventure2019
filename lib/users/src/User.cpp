#include <boost/algorithm/string.hpp>
#include "User.h"
#include <iostream>

using user::User;
using std::string;

User::User(const string &name, const string &password) {
    this->name = name;
    this->password = password;
    //this->avatar = newAvatar;
}

User::User(const string &name, const string &password, Avatar &&avatar) {
    this->name = name;
    this->password = password;
    this->avatar = avatar;
}

User::~User() = default;

string User::getUserName() {
    return this->name;
}

Avatar User::getAvatar() const {
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
    messages.push(message);
}

std::queue<std::string>& User::getMessages() {
    return messages;
}

void User::addCommandToList(const std::vector<std::string>& command){
    commands.push(command);
}

std::queue<std::vector<std::string>>& User::getCommands(){
    return commands;
}

void User::popCommand(){
    if(!commands.empty()){
        commands.pop();
    }
}

int User::getCommandSize(){
    return commands.size();
}
