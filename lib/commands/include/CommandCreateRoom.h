#ifndef CommandCreateRoom_h
#define CommandCreateRoom_h

#include "Command.h"

using usermanager::OnlineUserManager;
using avatarmanager::AvatarManager;

class CommandCreateRoom : public Command
{
public:
	CommandCreateRoom(AvatarManager& a, OnlineUserManager& u, WorldManager& w): Command(a, u, w) {}
	
	virtual void executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand);
	virtual std::vector<std::string> reassembleCommand(std::string& fullCommand, bool& commandIsValid);
};


#endif