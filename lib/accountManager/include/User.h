#ifndef USER_H
#define USER_H

#include <string>
namespace user {
  
class User {
  private:
    std::string userName;
    std::string userPasswd;
    int roomID;

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