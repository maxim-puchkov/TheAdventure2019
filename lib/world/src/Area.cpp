//
// Created by jordan on 24/01/19.
//

#include "Area.h"

/**
 * Returns a room at a particular index from an area
 */
// Room& Area::getRoom(unsigned int index) {
//     if(index >= rooms.size()){
//         //return some invalid room
//     }
//     return rooms.at(index);
// }

Room& Area::getRoom(int roomId) {
    auto search = roomList.find(roomId);
    if(search != roomList.end()) {
        return search->second;
    }else{
        return nullRoom;
    }
}

std::unordered_map<int, Room>& Area::getRoomList(){
    return this->roomList;
}

void Area::addRoom(Room room){
    roomList.insert(std::make_pair(room.getRoomId(), room));
}

unsigned long Area::size() const{
    return roomList.size();
}

const std::string &Area::getName() const {
    return name;
}

void Area::setName(const std::string &name) {
    Area::name = name;
}

const std::string &Area::getDescription() const {
    return description;
}

void Area::setDescription(const std::string &description) {
    Area::description = description;
}

std::vector<int> Area::getRoomIdList() {
    std::vector<int> roomIds;
    roomIds.reserve(roomList.size());
    for(auto room : roomList){
        roomIds.push_back(room.first);
    }
    return roomIds;
}

bool Area::addNPCtoRooms(std::string shortDesc, int ID){
    auto search = roomList.find(ID);
    if(search != roomList.end()) {
        search->second.addNPC(shortDesc);
        return true;
    }else{
        return false;
    }
}

void Area::setNextRoomID(int id) {
    nextRoomID = id + 1;
}

int Area::getNextRoomID() {
    return nextRoomID;
}
