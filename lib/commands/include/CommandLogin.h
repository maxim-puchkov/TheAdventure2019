#ifndef CommandLogin_h
#define CommandLogin_h

#include "Command.h"
#include "LocationCoordinates.h"

using usermanager::OnlineUserManager;
using avatarmanager::AvatarManager;

class CommandLogin : public Command
{
public:
	CommandLogin(AvatarManager& a, OnlineUserManager& u, WorldManager& w): Command(a, u, w) {}
	virtual std::string execute(const std::string& connectionID, const std::vector<std::string>& fullCommand);
};




#endif
