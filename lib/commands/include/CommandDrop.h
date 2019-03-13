#ifndef CommandDrop_h
#define CommandDrop_h

#include "Command.h"

using usermanager::OnlineUserManager;
using charactermanager::CharacterManager;

class CommandDrop : public Command
{
public:
	CommandDrop(CharacterManager& c, OnlineUserManager& u, WorldManager& w): Command(c, u, w) {}
	
	virtual void executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand);
	virtual std::vector<std::string> reassembleCommand(std::string& fullCommand, bool& commandIsValid);
};


#endif