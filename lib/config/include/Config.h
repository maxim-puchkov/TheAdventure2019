#ifndef CONFIG_H
#define CONFIG_H

#include <unordered_map>
#include <string>
#include <iostream> 
#include <fstream>

#include "JsonParser.h"

using namespace std;
using nlohmann::json;



class Config {
  public:
    int heartbeat_freq = 0;
    int heartbeat_combat = 0;
    int reset_freq = 0;

  private:
    JsonParser jsonParser;
    json config_json;
    std::string json_filePath = "data/config/config.json";

  public:
    Config(){
        config_json = jsonParser.processJSON(json_filePath);

        if(config_json == nullptr){
            cout<< "JSON NOT FOUND\n";
        }else{
            this->heartbeat_freq = config_json["heartbeat_freq"];
            this->heartbeat_combat = config_json["heartbeat_combat"];
            this->reset_freq = config_json["reset_freq"];
        }
    };

};
#endif
