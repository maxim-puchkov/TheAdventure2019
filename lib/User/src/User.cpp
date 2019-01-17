#include "User.h"
#include <string>

class User
{
  private:
    std::string userName;
    std::string userPasswd;

  public:
    void User::setUserName(std::string userName)
    {
        this->userName = userName;
    }

    void User::setUserPasswd(std::string userPasswd)
    {
        this->userPasswd = userPasswd;
    }

    std::string User::getUserName()
    {
        return this->userName;
    }

    std::string User::getUserPasswd()
    {
        return this->userPasswd;
    }
};