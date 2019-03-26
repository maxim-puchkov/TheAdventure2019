#ifndef Command_h
#define Command_h

#include <string>
#include <vector>

#include "CharacterManager.h"
#include "OnlineUserManager.h"
#include "WorldManager.h"
#include "LocationCoordinates.h"
// #include <boost/algorithm/string.hpp>

using usermanager::OnlineUserManager;
using charactermanager::CharacterManager;

class Command
{
protected:
	CharacterManager& characterManager;
	OnlineUserManager& onlineUserManager;
	WorldManager& worldManager;

public:
	Command(CharacterManager& c, OnlineUserManager& u, WorldManager& w): characterManager(c), onlineUserManager(u), worldManager(w) {}
	//Command(CharacterManager& c, OnlineUserManager& u, WorldManager& w, CombatManager& x): characterManager(c), onlineUserManager(u), worldManager(w), combatManager(x) {}
	
	virtual std::vector<std::string> reassembleCommand(std::string& fullCommand, bool& commandIsValid) = 0;
	virtual std::string executePromptReply(const std::string& connectionID, const std::vector<std::string>& fullCommand);
	virtual void executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand);
	virtual void executeCombatRound(const std::string& username, const std::vector<std::string>& fullCommand);

};

#endif
