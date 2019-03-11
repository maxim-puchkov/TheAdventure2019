#ifndef CommandUse_h
#define CommandUse_h

#include "Command.h"
#include <boost/lexical_cast.hpp>

using boost::lexical_cast;
using boost::bad_lexical_cast;
using usermanager::OnlineUserManager;
using avatarmanager::AvatarManager;

class CommandUse : public Command
{
public:
	CommandUse(AvatarManager& a, OnlineUserManager& u, WorldManager& w): Command(a, u, w) {}
	
	virtual void executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand);
	virtual std::vector<std::string> reassembleCommand(std::string& fullCommand, bool& commandIsValid);
};


#endif