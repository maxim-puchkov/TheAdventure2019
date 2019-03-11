#ifndef CommandCast_h
#define CommandCast_h

#include "Command.h"

using usermanager::OnlineUserManager;
using avatarmanager::AvatarManager;

class CommandCast : public Command
{
public:
	CommandCast(AvatarManager& a, OnlineUserManager& u, WorldManager& w): Command(a, u, w) {}
	
	virtual void executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand);
	virtual std::vector<std::string> reassembleCommand(std::string& fullCommand, bool& commandIsValid);
};


#endif