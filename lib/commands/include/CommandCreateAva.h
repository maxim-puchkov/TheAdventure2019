#ifndef CommandCreateAva_h
#define CommandCreateAva_h

#include "Command.h"

using usermanager::OnlineUserManager;
using avatarmanager::AvatarManager;

class CommandCreateAva : public Command
{
public:
	CommandCreateAva(AvatarManager& a, OnlineUserManager& u, WorldManager& w): Command(a, u, w) {}
	
	virtual std::string executePromptReply(const std::string& connectionID, const std::vector<std::string>& fullCommand);
	virtual std::vector<std::string> reassembleCommand(std::string& fullCommand, bool& commandIsValid);
};


#endif