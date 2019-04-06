#ifndef CommandLogin_h
#define CommandLogin_h

#include "Command.h"
#include <sstream>

using usermanager::OnlineUserManager;
using charactermanager::CharacterManager;
using internationalization::Internationalization;

class CommandLogin : public Command
{
public:
	CommandLogin(CharacterManager& c, OnlineUserManager& u, WorldManager& w, Internationalization& s):
					Command(c, u, w, s) {}

	virtual std::string executePromptReply(const std::string& connectionID, const std::vector<std::string>& fullCommand);
	virtual std::vector<std::string> reassembleCommand(std::string& fullCommand, bool& commandIsValid);
};


#endif