#ifndef CommandHelp_h
#define CommandHelp_h

#include "Command.h"
#include <sstream>

using usermanager::OnlineUserManager;
using avatarmanager::AvatarManager;

class CommandHelp : public Command
{
public:
	CommandHelp(AvatarManager& a, OnlineUserManager& u, WorldManager& w): Command(a, u, w) {}
	
	virtual std::string executePromptReply(const std::string& connectionID, const std::vector<std::string>& fullCommand);
	virtual std::vector<std::string> reassembleCommand(std::string& fullCommand, bool& commandIsValid);

private:
	std::string printAccountCommands(const std::string& userRole);
	std::string printAvatarCommands(const std::string& userRole);
	std::string printCommunicationCommands(const std::string& userRole);
	std::string printWorldInteractionCommands(const std::string& userRole);
	std::string printInventoryCommands(const std::string& userRole);
	std::string printMinigameCommands(const std::string& userRole);
	std::string printCombatCommands(const std::string& userRole);
	std::string printUtilityCommands(const std::string& userRole);
};


#endif