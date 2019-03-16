#ifndef CHARACTER_MANAGER_H
#define CHARACTER_MANAGER_H

#include <unordered_map> 
#include <string>
#include <vector>
#include "Character.h"
#include "CharacterDB.h"
#include "LocationCoordinates.h"
#include "MiniGameLobby.h"
#include "CombatManager.h"

namespace charactermanager{

class CharacterManager{
private:
    std::unordered_map<std::string, Character> onlineCharacters;
    std::vector<Character> computerControlledCharacters;
    Character nullCharacter{""};
    CharacterDB characterDB;
    MiniGameLobby minigameLobby;
    CombatManager combatManager;
    LocationCoordinates nullLocation{-1, -1};

    const std::string SHORT_DESC = "shortdesc";
    const std::string LONG_DESC = "longdesc";
    const std::string DESCRIPTION = "description";

public:
    enum class CHARACTER_CODE : uint8_t {
      CHARACTER_CREATED,
      CHARACTER_UPDATED,
      CHARACTER_DELETED,
      CHARACTER_NOT_FOUND,
      CHARACTER_CUSTOMIZED_MISSING_SHORT_DESC,
      CHARACTER_CUSTOMIZED_MISSING_LONG_DESC,
      CHARACTER_CUSTOMIZED_MISSING_DESCRIPTION,
      CHARACTER_IS_CUSTOMIZED,
      CHARACTER_THIS_IS_FIRST_TIME_SET_UP,
      CHARACTER_THIS_IS_NOT_FIRST_TIME_SET_UP,
      CHARACTER_FAILED
    };

    LocationCoordinates spawnCharacter(const std::string& username);
    void kickCharacter(const std::string& username);
    
    std::string getUsernameFromCharacter(const std::string& username) const; //for now character name and user name are the same
    //std::string getCharacterNameFromUser(const std::string& username) const;
    
    LocationCoordinates getCharacterLocation(const std::string& username) const;
    void changeCharacterLocation(const std::string& username, LocationCoordinates newLocation);
    
    bool isCharacterCreated(const std::string& username);
    CHARACTER_CODE createCharacter(const std::string& username);

    CHARACTER_CODE isCharacterFullyCustomized(const std::string& username);
    CHARACTER_CODE editCharacter(const std::string& username, const std::string& attribute, const std::string& value);
    CHARACTER_CODE isThisFirstTimeSetup(const std::string& username) const;
    void setCharacterIsDoneFirstTimeSetup(std::string& username);

    //MiniGame commands
    MiniGameLobby& getMiniGameLobby();
    //Combat commands
    CombatManager& getCombatManager();
    CHARACTER_CODE damageCharacter(const std::string& username, int amount);
    int getCharacterAttack(const std::string& username);
    int getCharacterHealth(const std::string& username);

};

}

#endif
