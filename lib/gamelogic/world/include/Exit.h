//
// Created by jordan on 17/01/19.
//

#ifndef WEBSOCKETNETWORKING_EXIT_H
#define WEBSOCKETNETWORKING_EXIT_H


class Exit{

private:
    std::string exitName;
    std::string exitDescription;
    short cardinalDirection;
    unsigned int targetRoomID;

public:
    Exit(std::string exName, std::string exDescription, short cDirection, int targetID);
    Exit();

    //getters
    const std::string &getExitName() const;
    const std::string &getExitDescription() const;
    short getCardinalDirection() const;
    unsigned int getTargetRoomID() const;


    //Setters
    void setExitName(const std::string &exitName);
    void setExitDescription(const std::string &exitDescription);
    void setCardinalDirection(short cardinalDirection);
    void setTargetRoomID(unsigned int targetRoomID);
};


#endif //WEBSOCKETNETWORKING_EXIT_H
