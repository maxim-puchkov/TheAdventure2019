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

    const auto &computerControlled = std::find_if(NPCs.begin(),NPCs.end(),
            [&] (auto &iter) {return iter.getName() == userName; });


    if(computerControlled != NPCs.end()){
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
    const auto &compControlled = std::find_if(NPCs.begin(), NPCs.end(),
                [&](const auto &iter) {return iter.getName() == userName;});

    if(compControlled != NPCs.end()){
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


std::string CharacterManager::getUsernameFromCharacter(const std::string& charname) const {
	for (auto& element : onlineCharacters){
		if(element.second.getName() == charname)
			return element.first;
	}
	return "";
}

std::string CharacterManager::getCharacterNameFromUser(const std::string& username) const {
	auto found = onlineCharacters.find(username);
	if (found != onlineCharacters.end()) {
		return found->second.getName();
	}
	return "";
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

std::string CharacterManager::getCombatReply(const std::string& username){
	auto found = std::find_if(NPCs.begin(), NPCs.end(), [&username](Character& x){return x.getName() == username;});
	if (found == NPCs.end()) {
		return "";
	}
	return "combat accept";
	//return found->getCombatReply();
}

std::string CharacterManager::getAttackReply(const std::string& username){
	auto found = std::find_if(NPCs.begin(), NPCs.end(), [&username](Character& x){return x.getName() == username;});
	if (found == NPCs.end()) {
		return "";
	}
	return "attack";
	//return found->getAttackReply();
}

CharacterManager::CHARACTER_CODE CharacterManager::damageCharacter(const std::string& username, int amount){
	auto found = onlineCharacters.find(username);
	if (found == onlineCharacters.end()) {
		return CharacterManager::CHARACTER_CODE::CHARACTER_NOT_FOUND;
	}

	found->second.damageCharacter(amount);

	return CharacterManager::CHARACTER_CODE::CHARACTER_UPDATED;
}

bool CharacterManager::isConfused(const std::string& username)const{
	auto found = onlineCharacters.find(username);
	if (found == onlineCharacters.end()) {
		return false;
	}
	return found->second.isConfused();
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

bool CharacterManager::swapCharacters(const std::string& username1, const std::string& username2) {
    /*auto user1 = onlineCharacters.find(username1);
    auto user2 = onlineCharacters.find(username2);
    auto npc1 = std::find_if(NPCs.begin(), NPCs.end(), [&username1](Character& c){ return c.getName() == username1; });
    auto npc2 = std::find_if(NPCs.begin(), NPCs.end(), [&username2](Character& c){ return c.getName() == username2; });

    if(user1 != onlineCharacters.end() && user2 != onlineCharacters.end()){ //both users online
        auto& temp = user1->second;
        user1->second = user2->second;
        user2->second = temp;
    } else if(user1 != onlineCharacters.end() && npc2 != NPCs.end()) {
        Character temp = *npc2;
        *npc2 = user1->second;
        user1->second = temp;
    } else if(user2 != onlineCharacters.end() && npc1 != NPCs.end()) {
        Character temp = *npc1;
        *npc1 = user2->second;
        user2->second = temp;
    } else {
        return false;
    }

    return true;*/
//    Character *char1 = nullptr;
//    Character *char2 = nullptr;

//    for (auto &element : onlineCharacters) {
//        auto charName = element.second.getName();
//        if (charName == username1) {
//            char1 = &element.second;
//        } else if (charName == username2) {
//            char2 = &element.second;
//        }
//    }
    auto char1 = std::find_if(onlineCharacters.begin(), onlineCharacters.end(), [&username1](auto& c){ return c.second.getName() == username1; });
    auto char2 = std::find_if(onlineCharacters.begin(), onlineCharacters.end(), [&username2](auto& c){ return c.second.getName() == username2; });

    cerr << username1 + ", " + username2 + "\n";
    cerr << "user char name: " + char1->second.getName() + "\n";

    if(char1 == onlineCharacters.end() && char2 == onlineCharacters.end()) return false; //cannot swap 2 npcs

    if(char1 == onlineCharacters.end()){

        auto npc = std::find_if(NPCs.begin(), NPCs.end(), [&username1](auto& c){ return c.getName() == username1; });
        if(npc == NPCs.end()) return false;
        cerr <<  "1";
        auto& temp = char2->second;

        char2->second = *npc;
        cerr <<  "2";
        *npc = temp;

    } else if(char2 == onlineCharacters.end()){
        auto npc = std::find_if(NPCs.begin(), NPCs.end(), [&username2](auto& c){ return c.getName() == username2; });
        if(npc == NPCs.end()) return false;
        cerr <<  "3";
        Character temp = char1->second;

        //onlineCharacters[username1] = *npc;
        char1->second = *npc;
        cerr <<  "4";
        *npc = temp;
    } else {
        auto& temp = char1->second;
        cerr <<  "5";
        char1->second = char2->second;
        cerr <<  "6";
        char2->second = temp;
    }
    return true;
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

