#ifndef Command_h
#define Command_h

#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>

#include "AvatarManager.h"
#include "OnlineUserManager.h"
#include "WorldManager.h"
#include "LocationCoordinates.h"

using usermanager::OnlineUserManager;
using avatarmanager::AvatarManager;

class Command
{
protected:
	AvatarManager& avatarManager;
	OnlineUserManager& onlineUserManager;
	WorldManager& worldManager;

public:
	Command(AvatarManager& a, OnlineUserManager& u, WorldManager& w): avatarManager(a), onlineUserManager(u), worldManager(w) {}
	
	virtual std::vector<std::string> reassembleCommand(std::string& fullCommand, bool& commandIsValid) = 0;
	virtual std::string executePromptReply(const std::string& connectionID, const std::vector<std::string>& fullCommand);
	virtual void executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand);
};

#endif
