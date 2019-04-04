#include "CharacterManager.h"


using charactermanager::CharacterManager;





/**
 * Returns the long description of a NPC.
 * If an NPC and PC cannot share the same name, but I left the code to display both regardless
 * @param userName - The username of a playable character, or the name of a NPC
 * @return - The long description of a character
 */
const std::string CharacterManager::getLongDescription(const std::string &userName) const {

    std::string result;
    //Looking at playable characthers
    auto onlineChar = onlineCharacters.find(userName);
    if(onlineChar != onlineCharacters.end() ){
        result.append("Looking at userName: '" + userName + "' description: " + onlineChar->second.getLongdesc() + "\n");

    }

    const auto &computerControlled = std::find_if(computerControlledCharacters.begin(),computerControlledCharacters.end(),
            [&] (auto &iter) {return iter.getName() == userName; });


    if(computerControlled != computerControlledCharacters.end()){
        result.append("Looking at NPC: "+ userName + " description: " + (*computerControlled).getLongdesc() + "\n" );
    }

    const auto &nonPlayable = std::find_if(NPCs.begin(),NPCs.end(),
                                   [&] (const auto &iter) {return iter.getName() == userName; });

    if(nonPlayable != NPCs.end()){
        result.append("Looking at NPC: "+ userName + " description: " + (*nonPlayable).getLongdesc() + "\n" );
    }



    if(result.empty()){
        result.append(" No object with name " + userName + "\n");
    }

    return std::move(result);
}

//Returns the string of a userName along with a short description of that particular character
const std::string CharacterManager::getShortDescription(const std::string &userName) const {

    //Once for playable characters
    std::string result;
    const auto &onlineChar = onlineCharacters.find(userName);
    if(onlineChar != onlineCharacters.end()){
        result.append(userName + " - " + onlineChar->second.getShortdesc() + "\n");
    }

    //Once for CPU
    const auto &compControlled = std::find_if(computerControlledCharacters.begin(), computerControlledCharacters.end(),
                [&](const auto &iter) {return iter.getName() == userName;});

    if(compControlled != computerControlledCharacters.end()){
        result.append(userName + " - " + (*compControlled).getShortdesc()  + "\n");
    }

    //One more time for NPC's
    const auto &nonPlayable = std::find_if(NPCs.begin(), NPCs.end(),
        [&](const auto &iter) {return iter.getName() == userName;} );

    if(nonPlayable != NPCs.end()){
        result.append(userName + " - " + (*nonPlayable).getShortdesc() + "\n" );
    }


    return std::move(result);
}




LocationCoordinates CharacterManager::spawnCharacter(const std::string& username, LocationCoordinates location) {
	Character character = characterDB.getCharacter(username);
	onlineCharacters.insert(std::make_pair(username, character));
	// auto spawnLocation = LocationCoordinates{0, 0};
	auto spawnLocation = location;
	changeCharacterLocation(username, character.getCurrentLocation());
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
		found->second.setFirstTimeSetup(true);
	}
}

MiniGameLobby& CharacterManager::getMiniGameLobby(){
	return minigameLobby;
}

CombatManager& CharacterManager::getCombatManager(){
	return combatManager;
}

CharacterManager::CHARACTER_CODE CharacterManager::damageCharacter(const std::string& username, int amount){
	auto found = onlineCharacters.find(username);
	if (found == onlineCharacters.end()) {
		return CharacterManager::CHARACTER_CODE::CHARACTER_NOT_FOUND;
	}

	found->second.damageCharacter(amount);

	return CharacterManager::CHARACTER_CODE::CHARACTER_UPDATED;
}

int CharacterManager::getCharacterAttack(const std::string& username){
	auto found = onlineCharacters.find(username);
	if (found == onlineCharacters.end()) {
		return -1;
	}

	return found->second.getAttributes().getDamage();
}

int CharacterManager::getCharacterHealth(const std::string& username){
	auto found = onlineCharacters.find(username);
	if (found == onlineCharacters.end()) {
		return -1;
	}

	return found->second.getAttributes().getHealth();
}

std::string CharacterManager::listNPCs() {
	std::cout << "NPC size: " << NPCs.size() << "\n";
    std::string NPCList = "";
    for(auto& npc : NPCs){
        NPCList += npc.getShortdesc();
        NPCList += "\n";
    }
    return NPCList;
}

std::string CharacterManager::getCharArea(const std::string& userName){
	std::string charArea = characterDB.getArea(userName);
	return charArea;
}
int CharacterManager::getCharRoom(const std::string& userName){
	int charRoom = characterDB.getRoom(userName);
	return charRoom;
}

bool CharacterManager::updateCharLocation(const std::string& userName, LocationCoordinates location){
	bool result = characterDB.updateCharLocation(userName, location);
	return result;
}

