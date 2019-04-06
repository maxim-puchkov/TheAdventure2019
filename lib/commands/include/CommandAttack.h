#ifndef CommandAttack_h
#define CommandAttack_h

#include "Command.h"

using usermanager::OnlineUserManager;
using charactermanager::CharacterManager;

class CommandAttack : public Command
{
protected:
	CombatManager& combatManager;
public:
	CommandAttack(CharacterManager& c, OnlineUserManager& u, WorldManager& w, CombatManager& x): Command(c, u, w), combatManager(x) {}
	
	virtual void executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand);
	virtual void executeCombatRound(const std::string& username, const std::vector<std::string>& fullCommand);
	virtual std::vector<std::string> reassembleCommand(std::string& fullCommand, bool& commandIsValid);
};


#endif