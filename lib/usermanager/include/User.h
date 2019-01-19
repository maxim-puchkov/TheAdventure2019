#ifndef USERPROFILE_USER_H
#define USERPROFILE_USER_H

#include <string>
namespace usermanager {
  
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

    //QUICK HACK TO GET GAMEMANAGER.cpp & WORLDMANAGER.cpp running
    int getRoomID(){
        return roomID;
    }
    void setRoomID(int newroomID){
        roomID = newroomID;
    }
};
}
#endif