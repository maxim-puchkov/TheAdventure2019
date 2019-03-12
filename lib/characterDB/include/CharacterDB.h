#ifndef CHARACTERDB_H
#define CHARACTERDB_H

#include "User.h"
#include "Character.h"
#include "JsonParser.h"
#include "json.hpp"

#include <unordered_map>
#include <string>
#include <iostream> 
#include <fstream>

using namespace std;
using nlohmann::json;
using user::User; 

class CharacterDB {
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
    json characters_json;
    std::string json_filePath = "../adventure2019/data/db/charters.json";
  public:
    CharacterDB();
    ~CharacterDB();

    DB_CODE createCharacter(const std::string&, const std::string&);

    DB_CODE updateCharacter(User&);

    User getCharacter(const std::string&, const std::string&);

    DB_CODE deleteCharacter(const std::string& );
};
#endif
