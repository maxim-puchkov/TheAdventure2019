#ifndef CommandExamine_h
#define CommandExamine_h

#include "Command.h"

using usermanager::OnlineUserManager;
using avatarmanager::AvatarManager;

class CommandExamine : public Command
{
public:
	CommandExamine(AvatarManager& a, OnlineUserManager& u, WorldManager& w): Command(a, u, w) {}
	virtual void executeInHeartbeat(const std::string& connectionID, const std::vector<std::string>& fullCommand);
private:
	const int YELL_RANGE = 1;
};




#endif
