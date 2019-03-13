#include <boost/algorithm/string.hpp>
#include "User.h"
#include <iostream>

using user::User;
using std::string;

User::User(const string &name, const string &password) {
    this->name = name;
    this->password = password;
    this->timeStamp = 0;
    
    //TODO: change this
    this->role = USER_ROLE::ADMIN;
    //this->test();
}


User::~User() = default;

string User::getUserName() const {
    return this->name;
}

void User::addMessage(std::string message) {
    messages.push_back(message);
}

std::vector<std::string>& User::getMessages() {
    return messages;
}

void User::addCommandToList(std::vector<std::string> command){
    commands.push_back(command);
}

std::deque<std::vector<std::string>>& User::getCommands() {
    return commands;
}

std::vector<std::string> User::popCommand(){
    std::vector<std::string> command;
    if(!commands.empty()){
        command = commands.front();
        commands.pop_front();
    }
    return command;
}

int User::getCommandSize() const {
    return commands.size();
}

int User::getMessageSize() const{
    return messages.size();
}

void User::setTimeStamp(const long timeStamp){
    this->timeStamp = timeStamp;
}

long User::getTimeStamp(){
    return timeStamp;
}

void User::init() {
    
}

void User::test() {
    std::cout << "Debug: User " << this->name << " created\n";
}

bool User::operator==(const User &other) {
    return this->name.compare(other.name) == 0;
}

bool User::operator!=(const User &other) {
    return this->name.compare(other.name) != 0;
}

User::USER_ROLE User::getRole() const {
    return role;
}