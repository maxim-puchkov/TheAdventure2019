#ifndef CommandMove_h
#define CommandMove_h

#include "Command.h"
#include <sstream>

using usermanager::OnlineUserManager;
using avatarmanager::AvatarManager;

class CommandMove : public Command
{
public:
	CommandMove(AvatarManager& a, OnlineUserManager& u, WorldManager& w): Command(a, u, w) {}
	
	virtual void executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand);
	virtual std::vector<std::string> reassembleCommand(std::string& fullCommand, bool& commandIsValid);
};


#endif