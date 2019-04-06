#ifndef CommandCombat_h
#define CommandCombat_h

#include "Command.h"

using usermanager::OnlineUserManager;
using charactermanager::CharacterManager;
using internationalization::Internationalization;

class CommandCombat : public Command
{
protected:
	CombatManager& combatManager;
public:
	CommandCombat(CharacterManager& c, OnlineUserManager& u, WorldManager& w, Internationalization& s, CombatManager& x): Command(c, u, w, s), combatManager(x) {}
	
	virtual void executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand);
	virtual std::vector<std::string> reassembleCommand(std::string& fullCommand, bool& commandIsValid);
};


#endif