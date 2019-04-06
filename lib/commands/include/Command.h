#ifndef Command_h
#define Command_h

#include <string>
#include <vector>

#include "CharacterManager.h"
#include "OnlineUserManager.h"
#include "WorldManager.h"
#include "LocationCoordinates.h"
#include "Internationalization.h"

using usermanager::OnlineUserManager;
using charactermanager::CharacterManager;
using internationalization::Internationalization;


/*!
 @class Command
 
 @brief Abstract base class for all game commands
 */
class Command
{
protected:
	CharacterManager& characterManager;
	OnlineUserManager& onlineUserManager;
	WorldManager& worldManager;
	Internationalization& stringManager;

public:
	Command(CharacterManager& c, OnlineUserManager& u, WorldManager& w, Internationalization& s):
			characterManager(c), onlineUserManager(u), worldManager(w), stringManager(s) {}
	
	virtual std::vector<std::string> reassembleCommand(std::string& fullCommand, bool& commandIsValid) = 0;
	virtual std::string executePromptReply(const std::string& connectionID, const std::vector<std::string>& fullCommand);
	virtual void executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand);
	virtual void executeCombatRound(const std::string& username, const std::vector<std::string>& fullCommand);

};

#endif
