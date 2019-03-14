

#ifndef ADVENTURE2019_COMBAT_H
#define ADVENTURE2019_COMBAT_H

#include <vector>
#include <string>
#include <algorithm>

const static unsigned int HEARTBEATS_PER_ROUND = 200;

class Combat{
public:
    Combat();
    Combat(const std::string& player1Name, const std::string& player2Name);
    bool hasPlayer(const std::string& name) const;
    unsigned int getRoundTime() const;
    std::string getOpponent(const std::string& name) const;
    void queueCommand(const std::string& name, const std::string& command);
    void decrementRoundTime();
    void resetRoundTime();
    std::string getPlayer(int playerNum) const;
    std::string getCommand(int playerNum) const;

private:
    std::vector<std::string> combatants;
    std::vector<std::string> queuedActions;

    unsigned int roundTime;
};

#endif //ADVENTURE2019_COMBAT_H
