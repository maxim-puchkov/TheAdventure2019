#ifndef CommandMove_h
#define CommandMove_h

#include "Command.h"
#include <sstream>

using usermanager::OnlineUserManager;
using charactermanager::CharacterManager;
using internationalization::Internationalization;

class CommandMove : public Command
{
protected:
	CombatManager& combatManager;
public:
	CommandMove(CharacterManager& c, OnlineUserManager& u, WorldManager& w, Internationalization& s, CombatManager& x): Command(c, u, w, s), combatManager(x) {}

	virtual void executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand);
	virtual std::vector<std::string> reassembleCommand(std::string& fullCommand, bool& commandIsValid);
};


#endif