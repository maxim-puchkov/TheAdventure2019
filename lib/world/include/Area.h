//
// Created by jordan on 24/01/19.
//

#ifndef WEBSOCKETNETWORKING_AREA_H
#define WEBSOCKETNETWORKING_AREA_H

#include <string>
#include <iostream>
#include "Room.h"

class Area {
    private:
        std::string name;
        std::string description;
        std::unordered_map<int, Room> roomList;
        int firstRoomInTheArea;
        int nextRoomID;
        // Room nullRoom{};
        //std::vector<Character> NPCS;
    public:
        Area()
                : name("DEFAULT_NAME"),
                  description("DEFAULT_DESCRIPTION")
        {}
        Area(std::string rName, std::string rDescription)
                : name(rName),
                  description(rDescription)
        {}
        // Room& getRoom(unsigned int index);

        Room& getRoom(int roomId);

        bool removeRoom(int roomId);

        std::unordered_map<int, Room>& getRoomList();

        void addRoom(Room room);

        unsigned long size() const;

        const std::string &getName() const;

        void setName(const std::string &name);

        const std::string &getDescription() const;

        void setDescription(const std::string &description);

        std::vector<int> getRoomIdList();

        //WORLD JSON Functions
        // std::vector<Room> getRooms();
        void setFirstRoomInArea(int id){
            firstRoomInTheArea = id;
        };

        int getFirstRoomID() {
            return firstRoomInTheArea;
        }
        // void setNPCs(std::vector<Character> NPCs){
        //     NPCS = NPCs;
        // };
        bool addNPCtoRooms(std::string shortDesc, int ID);
        // std::vector<Character> & getNPCs() {return NPCS;}
        // std::string listNPCs();
        void updateRoomExits(int id, std::string name);

        //for admin
        void setNextRoomID(int id);

        int getNextRoomID();

        std::vector<std::string> getRoomNameList();
        std::vector<std::string> getRoomNameIDListAdmin();

};




#endif //WEBSOCKETNETWORKING_AREA_H
