#include <string>
#include "WorldManager.h"
#include "UserManager.h"
#include "User.h"

class GameManager{

	private:
		GameManager();
		User getUser(std::string userName);

	public:
		std::string extractCommands(std::string command) const;
		void heartbeat() const;
};

GameManager() {
	//singleton implementation
}

std::string GameManager::extractCommands(const std::string command) {
	return "you did the thing";
}

void GameManager::heartbeat() {
	//fill this
}

User* GameManager::getUser(std::string userName) {
	return nullptr;
}
