#ifndef Command_h
#define Command_h

#include "AvatarManager.h"
#include "OnlineUserManager.h"
#include "WorldManager.h"
#include <string>
#include <vector>

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
	virtual std::string executePromptReply(const std::string& connectionID, const std::vector<std::string>& fullCommand);
	virtual void executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand);
};

#endif
