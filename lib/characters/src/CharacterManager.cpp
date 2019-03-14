
#include <CharacterManager.h>

#include "CharacterManager.h"


using charactermanager::CharacterManager;

LocationCoordinates CharacterManager::spawnCharacter(const std::string& username) {
	Character character = characterDB.getCharacter(username);
	onlineCharacters.insert(std::make_pair(username, character));
	auto spawnLocation = LocationCoordinates{0, 0};
	changeCharacterLocation(username, spawnLocation);
	return spawnLocation;
}


void CharacterManager::kickCharacter(const std::string& username) {
	auto found = onlineCharacters.find(username);
	if (found != onlineCharacters.end()) {
		characterDB.updateCharacter(found->second);
		onlineCharacters.erase(username);
	} else {
		//swallow, log error
	}
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

bool CharacterManager::isCharacterCreated(const std::string& username) {
	return (characterDB.getCharacter(username).getName() != "");
}

CharacterManager::CHARACTER_CODE CharacterManager::createCharacter(const std::string& username) {
	if(characterDB.createCharacter(username)) {
		return CharacterManager::CHARACTER_CODE::CHARACTER_CREATED;
	}
	return CharacterManager::CHARACTER_CODE::CHARACTER_FAILED;
}

CharacterManager::CHARACTER_CODE CharacterManager::isCharacterFullyCustomized(const std::string& username) {
	auto found = onlineCharacters.find(username);
	if (found == onlineCharacters.end()) {
		return CharacterManager::CHARACTER_CODE::CHARACTER_NOT_FOUND;
	}

	if(found->second.getShortdesc() == "") {
		return CharacterManager::CHARACTER_CODE::CHARACTER_CUSTOMIZED_MISSING_SHORT_DESC;
	} else if (found->second.getLongdesc() == "") {
		return CharacterManager::CHARACTER_CODE::CHARACTER_CUSTOMIZED_MISSING_LONG_DESC;
	} else if (found->second.getDescription() == "") {
		return CharacterManager::CHARACTER_CODE::CHARACTER_CUSTOMIZED_MISSING_DESCRIPTION;
	}
	return CharacterManager::CHARACTER_CODE::CHARACTER_IS_CUSTOMIZED;
}

CharacterManager::CHARACTER_CODE CharacterManager::editCharacter(const std::string& username, const std::string& attribute, const std::string& value) {
	auto found = onlineCharacters.find(username);
	if (found == onlineCharacters.end()) {
		return CharacterManager::CHARACTER_CODE::CHARACTER_NOT_FOUND;
	}

	auto answer = CharacterManager::CHARACTER_CODE::CHARACTER_UPDATED;
	if(attribute == SHORT_DESC) {
		found->second.setShortdesc(value);
	} else if (attribute == LONG_DESC) {
		found->second.setLongdesc(value);
	} else if (attribute == DESCRIPTION) {
		found->second.setDescription(value);
	} else {
		answer = CharacterManager::CHARACTER_CODE::CHARACTER_FAILED;
	}
	characterDB.updateCharacter(found->second);
	return answer; 
}

CharacterManager::CHARACTER_CODE CharacterManager::isThisFirstTimeSetup(const std::string& username) const {
	auto found = onlineCharacters.find(username);
	if (found == onlineCharacters.end()) {
		return CharacterManager::CHARACTER_CODE::CHARACTER_NOT_FOUND;
	}

	if(found->second.getIsDoneFirstTimeSetup()) {
		return CharacterManager::CHARACTER_CODE::CHARACTER_THIS_IS_NOT_FIRST_TIME_SET_UP;
	}
	return CharacterManager::CHARACTER_CODE::CHARACTER_THIS_IS_FIRST_TIME_SET_UP;
}

void CharacterManager::setCharacterIsDoneFirstTimeSetup(std::string& username) {
    auto found = onlineCharacters.find(username);
    if (found == onlineCharacters.end()) {
        found->second.setFirstTimeSetup();
    }
}

MiniGameLobby& CharacterManager::getMiniGameLobby(){
	return minigameLobby;
}


