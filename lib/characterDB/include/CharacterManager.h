#ifndef CHARACTER_MANAGER_H
#define CHARACTER_MANAGER_H

#include <unordered_map>
#include <algorithm>
#include <string>
#include <vector>
#include "Character.h"
#include "CharacterDB.h"
#include "LocationCoordinates.h"
#include "MiniGameLobby.h"
#include "CombatManager.h"

namespace charactermanager{

    const static unsigned int SWAP_SPELL_LENGTH = 2;
    const static unsigned int CONFUSE_SPELL_LENGTH = 3;
    const static unsigned int DECOY_SPELL_LENGTH = 1;

class CharacterManager{
private:

    std::unordered_map<std::string, Character> onlineCharacters;
    std::vector<Character> NPCs;

    Character nullCharacter{""};
    CharacterDB characterDB;
    MiniGameLobby minigameLobby;
    LocationCoordinates nullLocation{"WRONG AREA", -1};

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

    LocationCoordinates spawnCharacter(const std::string& username, LocationCoordinates location);
    const std::string getLongDescription(const std::string &userName) const;
    const std::string getShortDescription(const std::string &userName) const;

    void kickCharacter(const std::string& username);

    std::string getUsernameFromCharacter(const std::string& username) const;
    std::string getCharacterNameFromUser(const std::string& username) const;

    LocationCoordinates getCharacterLocation(const std::string& username) const;
    void changeCharacterLocation(const std::string& username, LocationCoordinates newLocation);

    bool isCharacterCreated(const std::string& username);
    CHARACTER_CODE createCharacter(const std::string& username);

    CHARACTER_CODE isCharacterFullyCustomized(const std::string& username);
    CHARACTER_CODE editCharacter(const std::string& username, const std::string& attribute, const std::string& value);
    CHARACTER_CODE isThisFirstTimeSetup(const std::string& username) const;
    void setCharacterIsDoneFirstTimeSetup(std::string& username);

    std::string getCharArea(const std::string& userName);
    int getCharRoom(const std::string& userName);
    bool updateCharLocation(const std::string& userName, LocationCoordinates location);

    //MiniGame commands
    MiniGameLobby& getMiniGameLobby();
    //combat commands
    std::string getCombatReply(const std::string& username);
    std::string getAttackReply(const std::string& username);
    std::string getCastReply(const std::string& username);

    CHARACTER_CODE damageCharacter(const std::string& username, int amount);
    int getCharacterAttack(const std::string& username);
    int getCharacterHealth(const std::string& username);
    //spells
    bool isConfused(const std::string& username) const;
    bool isSwapped(const std::string& username) const;
    bool isDecoy(const std::string& username) const;

    void setConfused(const std::string& username, const bool status);
    void setSwapped(const std::string& username, const bool status);
    void setDecoy(const std::string& username, const bool status);

    bool swapCharacters(const std::string& username1, const std::string& username2);
    std::string confuseMessage(std::string& message);

    void spellCooldown(const std::string& username);

    // NPC STUFF
    void addNPC(Character NPC){
        NPCs.push_back(NPC);
    }
    std::string getNPCshortDesc(int id){
         for(auto npc: NPCs){
             if (npc.getID() == id){
                 return npc.getShortdesc();
             }
         }
        return "NO NPC";
    }

    std::vector<Character>& getListNPCs(){return NPCs;}
    std::string listNPCs();
    //for combat testing
    void addNPC(const std::string& name){
        Character newNPC = Character{name};
        newNPC.setMode("aggro");
        auto description = name + " is the toughest guy around.\n";
        newNPC.setDescription(description);
        newNPC.setLongdesc(description);
        newNPC.setShortdesc(description);
        NPCs.push_back(newNPC);
    }
};

}

#endif
