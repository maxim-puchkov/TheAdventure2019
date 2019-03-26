#ifndef CommandHelp_h
#define CommandHelp_h

#include "Command.h"
#include <sstream>

using usermanager::OnlineUserManager;
using charactermanager::CharacterManager;

class CommandHelp : public Command
{
public:
	CommandHelp(CharacterManager& c, OnlineUserManager& u, WorldManager& w): Command(c, u, w) {}
	
	virtual std::string executePromptReply(const std::string& connectionID, const std::vector<std::string>& fullCommand);
	virtual std::vector<std::string> reassembleCommand(std::string& fullCommand, bool& commandIsValid);

private:
	std::string printAccountCommands(OnlineUserManager::USER_CODE userRole);
	std::string printAvatarCommands(OnlineUserManager::USER_CODE userRole);
	std::string printCommunicationCommands(OnlineUserManager::USER_CODE userRole);
	std::string printWorldInteractionCommands(OnlineUserManager::USER_CODE userRole);
	std::string printInventoryCommands(OnlineUserManager::USER_CODE userRole);
	std::string printMinigameCommands(OnlineUserManager::USER_CODE userRole);
	std::string printCombatCommands(OnlineUserManager::USER_CODE userRole);
	std::string printUtilityCommands(OnlineUserManager::USER_CODE userRole);
};


#endif