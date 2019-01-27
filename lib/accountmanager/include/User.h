#ifndef USER_H
#define USER_H

#include <string>
//#include "../../gamelogic/character/include/Character.h"
namespace user {
  
class User {
  private:
    std::string userName;
    std::string userPasswd;
    //Character playerCharacter;

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