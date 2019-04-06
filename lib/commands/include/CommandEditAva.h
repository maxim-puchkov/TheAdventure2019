#ifndef CommandEditAva_h
#define CommandEditAva_h

#include "Command.h"
#include <sstream>

using usermanager::OnlineUserManager;
using charactermanager::CharacterManager;
using internationalization::Internationalization;

class CommandEditAva : public Command
{
public:
	CommandEditAva(CharacterManager& c, OnlineUserManager& u, WorldManager& w, Internationalization& s):
					Command(c, u, w, s) {}
	
	virtual std::string executePromptReply(const std::string& connectionID, const std::vector<std::string>& fullCommand);
	virtual std::vector<std::string> reassembleCommand(std::string& fullCommand, bool& commandIsValid);
private:
	std::string editUserAvatar(const std::string& connectionID, const std::vector<std::string>& fullCommand);
	std::string spawnAvatar(const std::string& username);
};


#endif