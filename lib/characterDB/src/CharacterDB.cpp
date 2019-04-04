#include "CharacterDB.h"

CharacterDB::CharacterDB(){
    characters_json = jsonParser.processJSON(json_filePath);
    // cout<< "USER DB CONS()\n";

    if(characters_json == nullptr){
        cout<< "CHARACTERDB JSON NOT FOUND\n Creating new JSON file.\n";
        std::ofstream(stringManager.getString(Internationalization::STRING_CODE::CHARACTERS_JSON_FILE_NAME));
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
        characters_json[name][stringManager.getString(Internationalization::STRING_CODE::SHORTDESC)] = "";
        characters_json[name][stringManager.getString(Internationalization::STRING_CODE::LONGDESC)] = "";
        characters_json[name][stringManager.getString(Internationalization::STRING_CODE::DESC)] = "";
        characters_json[name][stringManager.getString(Internationalization::STRING_CODE::CHARACTER_FIRST_TIME_SETUP)] = false;
        characters_json[name]
            [stringManager.getString(Internationalization::STRING_CODE::LOCATION_COORDINATES)]
            [stringManager.getString(Internationalization::STRING_CODE::AREA)] = "Mirkwood";
        characters_json[name]
            [stringManager.getString(Internationalization::STRING_CODE::LOCATION_COORDINATES)]
            [stringManager.getString(Internationalization::STRING_CODE::ROOM)] = 8800;
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
        characters_json[characterName][stringManager.getString(Internationalization::STRING_CODE::SHORTDESC)] = character.getShortdesc();
        characters_json[characterName][stringManager.getString(Internationalization::STRING_CODE::LONGDESC)] = character.getLongdesc();
        characters_json[characterName][stringManager.getString(Internationalization::STRING_CODE::DESC)] = character.getDescription();
        characters_json[characterName][stringManager.getString(Internationalization::STRING_CODE::CHARACTER_FIRST_TIME_SETUP)] = character.getIsDoneFirstTimeSetup();
        characters_json[characterName]
            [stringManager.getString(Internationalization::STRING_CODE::LOCATION_COORDINATES)]
            [stringManager.getString(Internationalization::STRING_CODE::AREA)] = character.getCurrentLocation().area;
        characters_json[characterName]
            [stringManager.getString(Internationalization::STRING_CODE::LOCATION_COORDINATES)]
            [stringManager.getString(Internationalization::STRING_CODE::ROOM)] = character.getCurrentLocation().room;

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
        character.setLongdesc(characters_json[name][stringManager.getString(Internationalization::STRING_CODE::LONGDESC)]);
        character.setShortdesc(characters_json[name][stringManager.getString(Internationalization::STRING_CODE::SHORTDESC)]);
        character.setDescription(characters_json[name][stringManager.getString(Internationalization::STRING_CODE::DESC)]);
        character.setFirstTimeSetup(characters_json[name][stringManager.getString(Internationalization::STRING_CODE::CHARACTER_FIRST_TIME_SETUP)]);
        character.setCurrentLocation(LocationCoordinates{
            characters_json[name]
            [stringManager.getString(Internationalization::STRING_CODE::LOCATION_COORDINATES)]
            [stringManager.getString(Internationalization::STRING_CODE::AREA)],characters_json[name][stringManager.getString(Internationalization::STRING_CODE::LOCATION_COORDINATES)]
            [stringManager.getString(Internationalization::STRING_CODE::ROOM)]
        });
/*
        cout << character.getName() << " \n";
        cout << character.getShortdesc() << " \n";
        cout << character.getLongdesc() << " \n";
        cout << character.getDescription() << " \n";
        cout << character.getIsDoneFirstTimeSetup() << " \n";
*/
        return character;
    }
}



