

#ifndef ADVENTURE2019_COMBAT_H
#define ADVENTURE2019_COMBAT_H

#include <vector>
#include <string>
#include <algorithm>
#include "../../config/include/Config.h"

const static unsigned int HEARTBEATS_PER_ROUND = Config{}.heartbeat_combat;

class Combat{
public:
    Combat();
    Combat(const std::string& player1Name, const std::string& player2Name);
    bool hasPlayer(const std::string& name) const;
    int getRoundTime() const;
    std::string getOpponent(const std::string& name) const;
    void queueCommand(const std::string& name, const std::string& command);
    void clearCommands();
    void decrementRoundTime();
    void resetRoundTime();
    std::string getPlayer(unsigned int playerNum) const;
    std::string getCommand(unsigned int playerNum) const;

private:
    std::vector<std::string> combatants;
    std::vector<std::string> queuedActions;

    int roundTime;
};

#endif //ADVENTURE2019_COMBAT_H
