#ifndef CommandHelp_h
#define CommandHelp_h

#include "Command.h"
#include <sstream>

using usermanager::OnlineUserManager;
using avatarmanager::AvatarManager;

class CommandHelp : public Command
{
public:
	CommandHelp(AvatarManager& a, OnlineUserManager& u, WorldManager& w): Command(a, u, w) {}
	
	virtual std::string executePromptReply(const std::string& connectionID, const std::vector<std::string>& fullCommand);
	virtual std::vector<std::string> reassembleCommand(std::string& fullCommand, bool& commandIsValid);
};


#endif