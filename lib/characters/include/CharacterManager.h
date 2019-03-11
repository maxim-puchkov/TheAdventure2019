#ifndef CHARACTER_MANAGER_H
#define CHARACTER_MANAGER_H

#include <unordered_map> 
#include <string>
#include "Character.h"
#include "LocationCoordinates.h"

namespace charactermanager{
class CharacterManager{
    private:
        std::unordered_map<std::string, Character> onlineCharacters;
        Character nullCharacter{""};
        LocationCoordinates nullLocation{-1, -1};
    public:
        LocationCoordinates spawnCharacter(const std::string& username);
        void kickCharacter(const std::string& username);
        std::string getUsernameFromCharacter(const std::string& username) const; //for now character name and user name are the same
        LocationCoordinates getCharacterLocation(const std::string& username) const;
        void changeCharacterLocation(const std::string& username, LocationCoordinates newLocation);
};
}

#endif
