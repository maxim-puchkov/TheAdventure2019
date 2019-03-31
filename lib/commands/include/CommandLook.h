#ifndef CommandLook_h
#define CommandLook_h

#include "Command.h"

using usermanager::OnlineUserManager;
using charactermanager::CharacterManager;

class CommandLook : public Command
{
public:
	CommandLook(CharacterManager& c, OnlineUserManager& u, WorldManager& w): Command(c, u, w) {}
	
	virtual void executeInHeartbeat(const std::string& userName, const std::vector<std::string>& fullCommand);
	virtual std::vector<std::string> reassembleCommand(std::string& fullCommand, bool& commandIsValid);

private:
    std::string lookObject(const std::string &userName, const std::string &target,) const ;

};


#endif