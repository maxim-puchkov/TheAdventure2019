#ifndef CommandSay_h
#define CommandSay_h

#include "Command.h"

using usermanager::OnlineUserManager;
using avatarmanager::AvatarManager;

class CommandSay : public Command
{
public:
	CommandSay(AvatarManager& a, OnlineUserManager& u, WorldManager& w): Command(a, u, w) {}
	virtual void executeInHeartbeat(const std::string& connectionID, const std::vector<std::string>& fullCommand);
private:
	const int SAY_RANGE = 0;
};




#endif
