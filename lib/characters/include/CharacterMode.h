
#ifndef ADVENTURE2019_CHARACTERMODE_H
#define ADVENTURE2019_CHARACTERMODE_H

class CharacterMode{
public:
    virtual std::string getCombatReply() const {   return "";  }
    virtual std::string getAttackReply() const {  return "";  }
};

class UserControlled : public CharacterMode{
public:
    std::string getCombatReply() const override {   return "";  }
    std::string getAttackReply() const override {  return "";  }
};

class AggressiveNPC : public CharacterMode{
public:
    std::string getCombatReply() const override {   return "combat accept";  }
    std::string getAttackReply() const override {  return "attack";  }
};

class PacifistNPC : public CharacterMode{
public:
    std::string getCombatReply() const override {   return "say: I am a pacifist and will not fight you";  }
    std::string getAttackReply() const override {  return "flee";  }
};

#endif //ADVENTURE2019_CHARACTERMODE_H
