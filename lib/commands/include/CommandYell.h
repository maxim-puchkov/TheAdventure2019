#ifndef CommandYell_h
#define CommandYell_h

#include "Command.h"

using usermanager::OnlineUserManager;
using avatarmanager::AvatarManager;

class CommandYell : public Command
{
public:
	CommandYell(AvatarManager& a, OnlineUserManager& u, WorldManager& w): Command(a, u, w) {}

	virtual void executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand);
	virtual std::vector<std::string> reassembleCommand(std::string& fullCommand, bool& commandIsValid);
private:
	const int YELL_RANGE = 1;
};


#endif