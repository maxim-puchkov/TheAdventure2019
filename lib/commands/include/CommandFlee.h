#ifndef CommandFlee_h
#define CommandFlee_h

#include "Command.h"

using usermanager::OnlineUserManager;
using charactermanager::CharacterManager;
using internationalization::Internationalization;

class CommandFlee : public Command
{
protected:
	CombatManager& combatManager;
public:
	CommandFlee(CharacterManager& c, OnlineUserManager& u, WorldManager& w, Internationalization& s, CombatManager& x): Command(c, u, w, s), combatManager(x) {}
	
	virtual void executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand);
	virtual void executeCombatRound(const std::string& username, const std::vector<std::string>& fullCommand);
	virtual std::vector<std::string> reassembleCommand(std::string& fullCommand, bool& commandIsValid);
};


#endif