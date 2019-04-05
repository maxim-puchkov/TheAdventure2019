//
// Created by jordan on 18/01/19.
//

#ifndef WEBSOCKETNETWORKING_WORLDMANAGER_H
#define WEBSOCKETNETWORKING_WORLDMANAGER_H

#include "Area.h"
#include "Room.h"
// #include "Character.h"
#include "LocationCoordinates.h"
#include "ItemController.h"
#include "Item.h"
#include "print.h"


using items::ItemController;
using WorldIdentifier = uint64_t;

// Debug WM construction counter
static long wmcc = 0;

class WorldManager {
private:
    Internationalization& stringManager;
    // std::vector<Area> areas;
    std::unordered_map<std::string, Area> areas;
    int roomToSpawnUser;
    Area nullArea{};
    std::string areaToSpawnFirstTimer = "";
public:
    WorldManager(Internationalization& i): stringManager(i) {}
    
    
    //WorldManager();
    void generateWorld();
    Room& findRoomByLocation(LocationCoordinates location);

    //commands
    bool kick(const std::string& characterName, LocationCoordinates location);
    bool spawn(const std::string& characterName, LocationCoordinates location);
    std::string listExits(LocationCoordinates location) ;
    // std::string listPeople(const Character& character);
    const std::vector<std::string>& getUserNamesInRoom (LocationCoordinates location) ;
    const std::vector<std::string> getUserNamesInRange (LocationCoordinates location, unsigned int range) ;
    LocationCoordinates move(const std::string& characterName, LocationCoordinates location, const std::string& direction) ;
    std::string look(LocationCoordinates location) ;
    std::string look(LocationCoordinates location, std::string objName) ;
    
    void createArea();
    void createRoom(const LocationCoordinates & location, const std::string& direction, const std::string& name);
    void printRoomsInArea(Area area);
    int getRoomToSpawnUser();
    std::string getAreaToSpawnUser();
    std::string worldDetail(LocationCoordinates location);
    void setAreaToSpawnFirstTimer(std::string locationName){
        areaToSpawnFirstTimer = locationName;
    }

    Area& getAreaByLocation(LocationCoordinates location);

    void addArea(Area area);
    /*! All items are created and stored in the item controller */
    const ItemController<WorldIdentifier> items;
    
};




#endif //WEBSOCKETNETWORKING_WORLDMANAGER_H
