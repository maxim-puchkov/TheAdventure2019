#include "User.h"
#include <string>

using user::User;

User::User(const std::string uName, const std::string uPwd) {
    userName = uName;
    userPasswd = uPwd;
}

void User::setUserName(std::string userName) {
    this->userName = userName;
}

void User::setUserPasswd(std::string userPasswd) {
    this->userPasswd = userPasswd;
}

std::string User::getUserName() {
    return this->userName;
}

std::string User::getUserPasswd() {
    return this->userPasswd;
}

User::~User() = default;