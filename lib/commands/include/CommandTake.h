#ifndef CommandTake_h
#define CommandTake_h

#include "Command.h"

using usermanager::OnlineUserManager;
using charactermanager::CharacterManager;

/*!
 @class CommandTake
 
 @brief Character will take an item in the room.
 */
class CommandTake : public Command
{
public:
	CommandTake(CharacterManager& c, OnlineUserManager& u, WorldManager& w): Command(c, u, w) {}
	
	virtual void executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand);
	virtual std::vector<std::string> reassembleCommand(std::string& fullCommand, bool& commandIsValid);
};


#endif /* CommandTake_h */
