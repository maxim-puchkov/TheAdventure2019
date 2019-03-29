#include "CharacterDB.h"

CharacterDB::CharacterDB(){
    characters_json = jsonParser.processJSON(json_filePath);
    // cout<< "USER DB CONS()\n";

    if(characters_json == nullptr){
        cout<< "CHARACTERDB JSON NOT FOUND\n Creating new JSON file.\n";
        std::ofstream("charaters_db.json");
    }
}

CharacterDB::~CharacterDB(){
    jsonParser.saveJSON(characters_json, json_filePath);
}

bool CharacterDB::createCharacter(const std::string& name){
    if(characters_json[name] != nullptr){
        return false;
    }
    else{
        characters_json[name]["shortdesc"] = "";
        characters_json[name]["longdesc"] = "";
        characters_json[name]["description"] = "";
        characters_json[name]["FirstTimeSetup"] = false;
        // characters_json[name]["LocationCoordinates"]["area"] = "Mirkwood";
        // characters_json[name]["LocationCoordinates"]["room"] = 8800;

        //cout << characters_json << "\n";
        jsonParser.saveJSON(characters_json, json_filePath);
        return true;
    }
}

bool CharacterDB::updateCharacter(Character& character){

    auto characterName = character.getName();
    if(characters_json[characterName] == nullptr){

        return false;
    }
    else{
        characters_json[characterName]["shortdesc"] = character.getShortdesc();
        characters_json[characterName]["longdesc"] = character.getLongdesc();
        characters_json[characterName]["description"] = character.getDescription();
        characters_json[characterName]["FirstTimeSetup"] = character.getIsDoneFirstTimeSetup();
        // characters_json[characterName]["LocationCoordinates"]["area"] = character.getCurrentLocation().area;
        // characters_json[characterName]["LocationCoordinates"]["room"] = character.getCurrentLocation().room;

        jsonParser.saveJSON(characters_json, json_filePath);

        return true;
    }
}

Character CharacterDB::getCharacter(const std::string& name){

    if(characters_json[name] == nullptr){
        return Character{""};
    }
    else{
        //cout<<"Character FOUND\n";
        // cout << characters_json ;
        Character character{name};
        character.setLongdesc(characters_json[name]["longdesc"]);
        character.setShortdesc(characters_json[name]["shortdesc"]);
        character.setDescription(characters_json[name]["description"]);
        character.setFirstTimeSetup(characters_json[name]["FirstTimeSetup"]);
        // character.setCurrentLocation(LocationCoordinates{characters_json[name]["LocationCoordinates"]["area"],characters_json[name]["LocationCoordinates"]["room"]});

        return character;
    }
}



