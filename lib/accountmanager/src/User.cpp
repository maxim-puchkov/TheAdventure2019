#include <boost/algorithm/string.hpp>
#include "User.h"

using user::User;
using std::string;

User::User(const string &name, const string &password) {
    this->name = name;
    this->password = password;
    this->avatar = Avatar();
    
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

void User::addAction(std::string action){
    std::vector<std::string> actionParts;
    boost::split(actionParts, action, boost::is_any_of(" "));
    actions.push(actionParts);
}

std::queue<std::vector<std::string>>& User::getActions(){
    return actions;
}

void User::init() {
    
}

void User::test() {
    string name = this->avatar.getName();
    this->avatar.say("hi");
}

