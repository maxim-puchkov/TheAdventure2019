#ifndef CommandPickup_h
#define CommandPickup_h

#include "Command.h"

using usermanager::OnlineUserManager;
using charactermanager::CharacterManager;

class CommandPickup : public Command
{
public:
	CommandPickup(CharacterManager& c, OnlineUserManager& u, WorldManager& w): Command(c, u, w) {}
	
	virtual void executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand);
	virtual std::vector<std::string> reassembleCommand(std::string& fullCommand, bool& commandIsValid);
};


#endif