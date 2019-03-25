//
// Created by jordan on 24/01/19.
//

#ifndef WEBSOCKETNETWORKING_AREA_H
#define WEBSOCKETNETWORKING_AREA_H

#include <string>
#include "Room.h"

class Area {
    private:
        std::string name;
        std::string description;
        std::vector<Room> rooms;
        std::vector<Character> NPCS;
    public:
        Area()
                : name("DEFAULT_NAME"),
                  description("DEFAULT_DESCRIPTION")
        {}
        Area(std::string rName, std::string rDescription)
                : name(rName),
                  description(rDescription)
        {}
        Room& getRoom(unsigned int index);

        void addRoom(Room room);

        unsigned long size() const;

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::string &getDescription() const;

    void setDescription(const std::string &description);

    //WORLD JSON Functions
    std::vector<Room> getRooms();
    void setNPCs(std::vector<Character> NPCs){
        NPCS = NPCs;
    };
    bool addNPCtoRooms(std::string shortDesc, int ID);

};




#endif //WEBSOCKETNETWORKING_AREA_H
