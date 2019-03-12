#include "CharacterManager.h"
#include "CharacterDB.h"

using charactermanager::CharacterManager;

LocationCoordinates CharacterManager::spawnCharacter(const std::string& username) {

	//DUMMY CODE DELETE
	CharacterDB a;
	a.createCharacter("murio");
	std::cout << a.getCharacter("murio\n").getName();


	//END DUMMY CODE


	Character character = Character(username);
	onlineCharacters.insert(std::make_pair(username, character));
	auto spawnLocation = LocationCoordinates{0, 0};
	changeCharacterLocation(username, spawnLocation);
	return spawnLocation;
}


void CharacterManager::kickCharacter(const std::string& username) {
	onlineCharacters.erase(username);
}


std::string CharacterManager::getUsernameFromCharacter(const std::string& username) const {
	//for now username = Character name


	return username;
}


LocationCoordinates CharacterManager::getCharacterLocation(const std::string& username) const {





	auto found = onlineCharacters.find(username);
	if (found != onlineCharacters.end()) {
		auto currentLocation = found->second.getCurrentLocation();
        return currentLocation;
    } else {
        return nullLocation;
    }
}


void CharacterManager::changeCharacterLocation(const std::string& username, LocationCoordinates newLocation) {
	auto found = onlineCharacters.find(username);
	if (found != onlineCharacters.end()) {
		found->second.setCurrentLocation(newLocation);
    }



}
