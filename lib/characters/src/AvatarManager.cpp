#include "AvatarManager.h"

using avatarmanager::AvatarManager;

LocationCoordinates AvatarManager::spawnAvatar(const std::string& username) {
	Avatar avatar = Avatar(username);
	onlineAvatars.insert(std::make_pair(username, avatar));
	auto spawnLocation = LocationCoordinates{0, 0};
	changeAvatarLocation(username, spawnLocation);
	return spawnLocation;
}


void AvatarManager::kickAvatar(const std::string& username) {
	onlineAvatars.erase(username);
}


std::string AvatarManager::getUsernameFromAvatar(const std::string& username) const {
	//for now username = avatar name
	return username;
}


LocationCoordinates AvatarManager::getAvatarLocation(const std::string& username) const {
	auto found = onlineAvatars.find(username);
	if (found != onlineAvatars.end()) {
		auto currentLocation = found->second.getCurrentLocation();
        return currentLocation;
    } else{
        return nullLocation;
    }
}


void AvatarManager::changeAvatarLocation(const std::string& username, LocationCoordinates newLocation) {
	auto found = onlineAvatars.find(username);
	if (found != onlineAvatars.end()) {
		found->second.setCurrentLocation(newLocation);
    }
}
