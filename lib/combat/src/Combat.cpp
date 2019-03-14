#include "Combat.h"

Combat::Combat(){
    combatants.push_back("");
    combatants.push_back("");
    queuedActions.push_back("");
    queuedActions.push_back("");
}

Combat::Combat(const std::string& player1Name, const std::string& player2Name){
    combatants.push_back(player1Name);
    combatants.push_back(player2Name);
    queuedActions.push_back("");
    queuedActions.push_back("");
}

bool Combat::hasPlayer(const std::string& name) const{
    if(combatants.empty()) return false;

    auto result = std::find(combatants.begin(), combatants.end(), name);

    return result != combatants.end();
}

unsigned int Combat::getRoundTime() const {
    return this->roundTime;
}

void Combat::queueCommand(const std::string& name, const std::string& command){ //PROBABLY PROBLEM HERE
    auto iterator = std::find(combatants.begin(), combatants.end(), name);
    auto index = iterator - combatants.begin();

    queuedActions.at(index) = command;
}

//for now return first non-input combatant. currently supporting 2 people per combat
std::string Combat::getOpponent(const std::string& name) const{
    for(auto& combatantName : combatants){
        if(combatantName != name)
            return combatantName;
    }
    return "";
}

void Combat::decrementRoundTime(){
    this->roundTime --;
}
void Combat::resetRoundTime(){
    this->roundTime = HEARTBEATS_PER_ROUND;
}

std::string Combat::getPlayer(int playerNum) const{
    if(playerNum < 0 || playerNum >= combatants.size()) return "";
    return combatants.at(playerNum);
}
std::string Combat::getCommand(int playerNum) const{
    if(playerNum < 0 || playerNum >= queuedActions.size()) return "";
    return queuedActions.at(playerNum);
}



