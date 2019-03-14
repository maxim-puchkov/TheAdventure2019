#include "CombatManager.h"

CombatManager::CombatManager(){}

Combat& CombatManager::createCombat(const std::string& player1Name, const std::string& player2Name) {
    Combat newCombat{player1Name, player2Name};
    this->combatList.emplace_back(newCombat);
    return combatList.back();
}

Combat& CombatManager::getCombatWithPlayer(const std::string& playerName){
    for(auto& combat : combatList){
        if (combat.hasPlayer(playerName)){
            return combat;
        }
    }
    return nullCombat;
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
        if(combat.getRoundTime() == 0){
            //temporary implementation
            std::vector<std::string> tempVector1;
            std::vector<std::string> tempVector2;
            tempVector1.push_back(combat.getCommand(0));
            tempVector2.push_back(combat.getCommand(1));

            auto player1Pair = std::make_pair(combat.getPlayer(0), tempVector1);
            auto player2Pair = std::make_pair(combat.getPlayer(1), tempVector2);
            commandList.push_back(player1Pair);
            commandList.push_back(player2Pair);
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
            return true;
        }
    }
    return false;
}