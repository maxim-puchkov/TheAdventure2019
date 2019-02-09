#ifndef USERDB_H
#define USERDB_H

#include "User.h"
#include "JsonParser.h"
#include "json.hpp"

#include <unordered_map>
#include <string>
#include <iostream> 
#include <fstream>

using namespace std;
using nlohmann::json;
using user::User; 



class UserDB {
  public:
    enum class DB_CODE : uint8_t {
      INVALID_USERNAME,
      ACCOUNT_CREATED,
      USER_UPDATED,
      USER_DELETED,
      USER_NOT_FOUND,      
    };

  private:
    JsonParser jsonParser;
    json users_json;
    std::string json_filePath = "users.json";
  public:
    UserDB();
    ~UserDB();

    DB_CODE createUser(const std::string&, const std::string&);

    DB_CODE updateUser(User&);

    User getUser(const std::string&, const std::string&);

    DB_CODE deleteUser(const std::string& );
};
#endif
