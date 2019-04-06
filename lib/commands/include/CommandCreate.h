#ifndef CommandCreate_h
#define CommandCreate_h

#include "Command.h"

using usermanager::OnlineUserManager;
using charactermanager::CharacterManager;
using internationalization::Internationalization;

class CommandCreate : public Command
{
public:
	CommandCreate(CharacterManager& c, OnlineUserManager& u, WorldManager& w, Internationalization& s):
					Command(c, u, w, s) {}
	
	virtual std::string executePromptReply(const std::string& connectionID, const std::vector<std::string>& fullCommand);
	virtual std::vector<std::string> reassembleCommand(std::string& fullCommand, bool& commandIsValid);
};


#endif