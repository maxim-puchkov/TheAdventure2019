#ifndef CommandLogin_h
#define CommandLogin_h

#include "Command.h"

using usermanager::OnlineUserManager;
using charactermanager::CharacterManager;

class CommandLogin : public Command
{
public:
	CommandLogin(CharacterManager& c, OnlineUserManager& u, WorldManager& w): Command(c, u, w) {}

	virtual std::string executePromptReply(const std::string& connectionID, const std::vector<std::string>& fullCommand);
	virtual std::vector<std::string> reassembleCommand(std::string& fullCommand, bool& commandIsValid);
};


#endif