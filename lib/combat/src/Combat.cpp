#include "Combat.h"
#include <iostream>

Combat::Combat(){
    this->roundTime = HEARTBEATS_PER_ROUND;
    combatants.emplace_back("");
    combatants.emplace_back("");
    std::vector<std::string> emptyVec;
    queuedActions.push_back(emptyVec);
    queuedActions.push_back(emptyVec);
}

Combat::Combat(const std::string& player1Name, const std::string& player2Name){
    this->roundTime = HEARTBEATS_PER_ROUND;
    combatants.push_back(player1Name);
    combatants.push_back(player2Name);
    std::vector<std::string> emptyVec;
    queuedActions.push_back(emptyVec);
    queuedActions.push_back(emptyVec);
}

bool Combat::hasPlayer(const std::string& name) const{
    if(combatants.empty()) return false;

    auto result = std::find(combatants.begin(), combatants.end(), name);

    return result != combatants.end();
}

int Combat::getRoundTime() const {
    return this->roundTime;
}

void Combat::queueCommand(const std::string& name, std::vector<std::string> command){
    auto iterator = std::find(combatants.begin(), combatants.end(), name);
    auto index = iterator - combatants.begin();

    queuedActions.at(index) = std::move(command);
}

void Combat::clearCommands(){
    for (auto& queue : queuedActions){
        queue.clear();
    }
}

std::string Combat::getOpponent(const std::string& name) const{
    for(auto& combatantName : combatants){
        if(combatantName != name)
            return combatantName;
    }
    return "";
}

void Combat::decrementRoundTime(){
    std::cerr << "round time left: " << std::to_string(roundTime - 1) << "\n";
    this->roundTime --;
}
void Combat::resetRoundTime(){
    this->roundTime = HEARTBEATS_PER_ROUND;
}

std::string Combat::getPlayer(int playerNum) const{
    if(playerNum < 0 || playerNum >= combatants.size()) return "";
    return combatants.at(playerNum);
}
std::vector<std::string> Combat::getCommand(int playerNum){
    if(playerNum < 0 || playerNum >= queuedActions.size()) return std::vector<std::string>{};
    return queuedActions.at(playerNum);
}



