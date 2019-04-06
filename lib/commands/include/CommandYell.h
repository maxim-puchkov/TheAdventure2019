#ifndef CommandYell_h
#define CommandYell_h

#include "Command.h"

using usermanager::OnlineUserManager;
using charactermanager::CharacterManager;
using internationalization::Internationalization;

class CommandYell : public Command
{
public:
	CommandYell(CharacterManager& c, OnlineUserManager& u, WorldManager& w, Internationalization& s):
					Command(c, u, w, s) {}

	virtual void executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand);
	virtual std::vector<std::string> reassembleCommand(std::string& fullCommand, bool& commandIsValid);
private:
	const int YELL_RANGE = 1;
};


#endif