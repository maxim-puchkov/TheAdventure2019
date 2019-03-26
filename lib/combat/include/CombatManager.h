
#ifndef ADVENTURE2019_COMBATMANAGER_H
#define ADVENTURE2019_COMBATMANAGER_H

#include "Match.h"
#include <vector>
#include <string>
#include <tuple>

class CombatManager {

public:
    CombatManager();

    Match& createCombat(const std::string& player1Name, const std::string& player2Name);
    void deleteCombat(const std::string& eitherName);
    bool createInvite(const std::string& inviterName, const std::string& invitedName);
    bool playerIsInCombat(const std::string& eitherName) const;
    //void clearStaleInvites();
    bool confirmInvite(const std::string& invitedName);
    void removeInvite(const std::string& eitherName);

    Match& getCombatWithPlayer(const std::string& playerName);

    std::vector<std::pair<std::string, std::vector<std::string>>> resolveCombatStep();
    std::vector<std::pair<std::string, std::vector<std::string>>> getCombatCommands();
    void roundTick();

    std::string printCombats() const;
    std::string printInvites() const;

private:
    Match nullCombat{};
    std::vector<Match> combatList;

    std::vector<std::tuple<std::string, std::string, long>> pendingInvites; // {inviterName, invitedName, timestamp}

};

#endif //ADVENTURE2019_COMBATMANAGER_H
