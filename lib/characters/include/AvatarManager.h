#ifndef AVATAR_MANAGER_H
#define AVATAR_MANAGER_H

#include <unordered_map> 
#include <string>
#include "Avatar.h"
#include "LocationCoordinates.h"

namespace avatarmanager{
class AvatarManager{
    private:
        std::unordered_map<std::string, Avatar> onlineAvatars;
        Avatar nullAvatar{""};
        LocationCoordinates nullLocation{-1, -1};
    public:
        LocationCoordinates spawnAvatar(const std::string& username);
        void kickAvatar(const std::string& username);
        std::string getUsernameFromAvatar(const std::string& username) const; //for now avatar name and user name are the same
        LocationCoordinates getAvatarLocation(const std::string& username) const;
        void changeAvatarLocation(const std::string& username, LocationCoordinates newLocation);
};
}

#endif
