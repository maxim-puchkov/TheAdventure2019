#ifndef CommandLogout_h
#define CommandLogout_h

#include "Command.h"

using usermanager::OnlineUserManager;
using avatarmanager::AvatarManager;

class CommandLogout : public Command
{
public:
	CommandLogout(AvatarManager& a, OnlineUserManager& u, WorldManager& w): Command(a, u, w) {}
	virtual std::string executePromptReply(const std::string& connectionID, const std::vector<std::string>& fullCommand);
};




#endif
