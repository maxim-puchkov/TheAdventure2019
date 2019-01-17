#ifndef USER_H
#define USER_H

#include <string>

class User
{
  private:
    std::string userName;
    std::string userPasswd;

  public:
    void setUserName(std::string userName);

    void setUserPasswd(std::string userPasswd);

    std::string getUserName();

    std::string getUserPasswd();
};

#endif