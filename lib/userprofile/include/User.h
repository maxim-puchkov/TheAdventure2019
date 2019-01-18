#ifndef USERPROFILE_USER_H
#define USERPROFILE_USER_H

#include <string>
namespace userprofile {
  
class User {
  private:
    std::string userName;
    std::string userPasswd;

  public:

    User(const std::string uName, const std::string uPwd);

    ~User();

    void setUserName(std::string userName);

    void setUserPasswd(std::string userPasswd);

    std::string getUserName();

    std::string getUserPasswd();
};
}
#endif