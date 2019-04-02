#include "CombatManager.h"


CombatManager::CombatManager(){}

Match& CombatManager::createCombat(const std::string& player1Name, const std::string& player2Name) {
    Match newCombat{player1Name, player2Name};
    this->combatList.emplace_back(newCombat);
    return combatList.back();
}

void CombatManager::deleteCombat(const std::string& eitherName){
    combatList.erase(std::remove_if(combatList.begin(), combatList.end(),
                                  [&eitherName](Match& x){return x.hasPlayer(eitherName);}),
                   combatList.end());
}

bool CombatManager::playerIsInCombat(const std::string& eitherName) const{
    auto it = std::find_if(combatList.begin(), combatList.end(), [&eitherName](const Match& x){return x.hasPlayer(eitherName);});
    return it != combatList.end();
}

Match& CombatManager::getCombatWithPlayer(const std::string& playerName){
    for(auto& combat : combatList){
        if (combat.hasPlayer(playerName)){
            return combat;
        }
    }
    return nullCombat;
}

std::vector<std::pair<std::string, std::vector<std::string>>> CombatManager::resolveCombatStep() {

    roundTick();

    return std::move(getCombatCommands());
}

void CombatManager::roundTick(){
    for (auto& combat : combatList) {
        combat.decrementRoundTime();
        if(combat.getRoundTime() < 0)
            combat.resetRoundTime();
    }
}

std::vector<std::pair<std::string, std::vector<std::string>>> CombatManager::getCombatCommands() {
    std::vector<std::pair<std::string, std::vector<std::string>>> commandList;

    for (auto &combat : combatList) {
        if(combat.getRoundTime() <= 0){
/*            //temporary implementation
            std::vector<std::string> tempVector1;
            std::vector<std::string> tempVector2;
            auto player1Command = combat.getCommand(0);
            auto player2Command = combat.getCommand(1);

            tempVector1.push_back(player1Command);
            tempVector2.push_back(player2Command);*/

            auto player1Pair = std::make_pair(combat.getPlayer(0), combat.getCommand(0));
            auto player2Pair = std::make_pair(combat.getPlayer(1), combat.getCommand(1));

            if(!player1Pair.second.empty() && player1Pair.second.at(0) == "flee"){
                commandList.push_back(player2Pair);
                commandList.push_back(player1Pair);
            } else {
                commandList.push_back(player1Pair);
                commandList.push_back(player2Pair);
            }

            combat.clearCommands();
        }
    }

    return std::move(commandList);
}

bool CombatManager::createInvite(const std::string& inviterName, const std::string& invitedName){
    for(auto& combat : combatList){
        if(combat.hasPlayer(inviterName) || combat.hasPlayer(invitedName)){
            return false;
        }
    }
    //auto invite = std::make_tuple(inviterName, invitedName, TimeStamp::getTimeStamp());
    auto invite = std::make_tuple(inviterName, invitedName, 0);

    pendingInvites.emplace_back(invite);
}

void CombatManager::removeInvite(const std::string& eitherName){
    pendingInvites.erase(std::remove_if(pendingInvites.begin(), pendingInvites.end(),
                                        [&eitherName](std::tuple<std::string, std::string, long>& x){return std::get<0>(x) == eitherName || std::get<1>(x) == eitherName;}),
                         pendingInvites.end());
}

/*void CombatManager::clearStaleInvites() {
    pendingInvites.erase(std::remove_if(pendingInvites.begin(), pendingInvites.end(),
                                        [](std::tuple<std::string, std::string, long>& x){return std::get<2>(x) == 0;}), //for now: remove if timestamp = 0. change later
                         pendingInvites.end());
}*/

bool CombatManager::confirmInvite(const std::string& invitedName){
    for(auto& invite : pendingInvites){
        auto& invited = std::get<1>(invite);
        if(invited == invitedName){
            auto& inviter = std::get<0>(invite);
            auto& combat = getCombatWithPlayer(inviter);

            if (combat.hasPlayer(inviter)){ //if inviter is now in combat, challenge invalidated
                return false;
            }
            createCombat(inviter, invited);
            removeInvite(invitedName);
            return true;
        }
    }
    return false;
}

std::string CombatManager::printCombats() const{
    std::string result = "Combat List:\n";
    for(auto combat : combatList){
        result += combat.getPlayer(0) + " vs. ";
        result += combat.getPlayer(1) + "\n";
    }
    return result;
}

std::string CombatManager::printInvites() const{
    std::string result = "Invite List:\n";
    for(auto& invite : pendingInvites){
        result += std::get<0>(invite) + ", " + std::get<1>(invite) + "\n";
    }
    return result;
}