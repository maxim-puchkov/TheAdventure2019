#ifndef EXIT_H
#define EXIT_H

#include <string>

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
    std::string getName() const;
    std::string getDescription() const;
    short getDirection() const;
    unsigned int getTargetID() const;
    //setters
    void setName(std::string newName);
    void setDescription(std::string newDescription);
    void setDirection(short newDirection);
    void setTargetID(int newTargetID);

};

#endif
