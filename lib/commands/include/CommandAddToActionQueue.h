#ifndef CommandAddToActionQueue_h
#define CommandAddToActionQueue_h

#include "CommandPromptReply.h"

using usermanager::OnlineUserManager;
using avatarmanager::AvatarManager;

class CommandAddToActionQueue : public CommandPromptReply
{
public:
	CommandAddToActionQueue(AvatarManager& a, OnlineUserManager& u, WorldManager& w): CommandPromptReply(a, u, w) {}
	virtual std::string execute(const std::string& connectionID, const std::vector<std::string>& fullCommand);
};




#endif
