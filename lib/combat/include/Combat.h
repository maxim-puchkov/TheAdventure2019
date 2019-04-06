

#ifndef ADVENTURE2019_COMBAT_H
#define ADVENTURE2019_COMBAT_H

#include <vector>
#include <string>
#include <algorithm>

const static unsigned int HEARTBEATS_PER_ROUND = 10;

class Combat{
public:
    Combat();
    Combat(const std::string& player1Name, const std::string& player2Name);
    //Combat(const std::vector<std::string>& players);
    bool hasPlayer(const std::string& name) const;
    int getRoundTime() const;
    std::string getOpponent(const std::string& name) const;
    void queueCommand(const std::string& name, std::vector<std::string> command);
    void clearCommands();
    void decrementRoundTime();
    void resetRoundTime();
    std::string getPlayer(int playerNum) const;
    std::vector<std::string> getCommand(int playerNum);

private:
    std::vector<std::string> combatants;
    std::vector<std::vector<std::string>> queuedActions;

    int roundTime;
};

#endif //ADVENTURE2019_COMBAT_H
