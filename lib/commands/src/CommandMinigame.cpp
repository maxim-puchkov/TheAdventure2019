#include "CommandMinigame.h"
#include <boost/algorithm/string.hpp>

void CommandMinigame::executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand) {
    //fill this
}

std::vector<std::string> CommandMinigame::reassembleCommand(std::string& fullCommand, bool& commandIsValid) {
    std::vector<std::string> processedCommand;
    commandIsValid = false;

    //Format: minigame challenge [username]
    //Format: minigame accept
    //Format: minigame accept [username]
    //Format: minigame join [username]
    //Format: minigame move [location-of-piece-to-be-moved],[new-location]
    boost::trim_if(fullCommand, boost::is_any_of(" \t"));

    //Split by ","
    std::vector<std::string> splitByComma;
    boost::split(splitByComma, fullCommand, boost::is_any_of(","), boost::token_compress_on);   
    if(splitByComma.size() == 2) {
        //validate "minigame move"
        return reassembleMinigameMove(splitByComma, commandIsValid);

    } else if (splitByComma.size() == 1) {
        //split by " "
        boost::split(processedCommand, splitByComma[0], boost::is_any_of(" \t"), boost::token_compress_on);        
        if(processedCommand.size() == 2) {
            commandIsValid = (processedCommand[1] == "accept");
        
        } else if(processedCommand.size() == 3) {
            //reassemble the command
            commandIsValid = (processedCommand[1] == "accept" ||
                                processedCommand[1] == "join" ||
                                processedCommand[1] == "challenge");
        }
    }

    return processedCommand;
}

std::vector<std::string> CommandMinigame::reassembleMinigameMove(std::vector<std::string>& splitByComma, bool& commandIsValid) {
    //Format: minigame move [location-of-piece-to-be-moved],[new-location]
    std::vector<std::string> leftSide, rightSide, processedCommand;
    commandIsValid = false;

    //trim any space before and after ","
    boost::trim_if(splitByComma[0], boost::is_any_of(" \t"));
    boost::trim_if(splitByComma[1], boost::is_any_of(" \t"));
    
    //split left side of "," by " "
    boost::split(leftSide, splitByComma[0], boost::is_any_of(" \t"), boost::token_compress_on);
    if (leftSide.size() != 3)  {    
        return processedCommand;
    }

    if(leftSide[1] != "move") {
        return processedCommand;
    }

    //split right side of "," by " "
    boost::split(rightSide, splitByComma[1], boost::is_any_of(" \t"), boost::token_compress_on);
    if (rightSide.size() != 1)  {
        return processedCommand;
    }

    //reassemble the whole thing
    std::swap(leftSide, processedCommand);
    processedCommand.push_back(rightSide[0]);

    commandIsValid = true;
    return processedCommand;
}