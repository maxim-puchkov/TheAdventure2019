
#ifndef ADVENTURE2019_CHARACTERMODE_H
#define ADVENTURE2019_CHARACTERMODE_H

class CharacterMode{
public:
    virtual std::string getCombatReply() const = 0;
    virtual std::string getAttackReply() const = 0;
    virtual std::string getCastReply() const = 0;
};

class UserControlled : public CharacterMode{
public:
    std::string getCombatReply() const override {   return "";  }
    std::string getAttackReply() const override {  return "";  }
    std::string getCastReply() const override { return "";  }
};

class AggressiveNPC : public CharacterMode{
public:
    std::string getCombatReply() const override {   return "combat accept";  }
    std::string getAttackReply() const override {  return "attack";  }
    std::string getCastReply() const override   {   return "cast confuse";   }
};

class PacifistNPC : public CharacterMode{
public:
    std::string getCombatReply() const override {   return "say: I am a pacifist and will not fight you";  }
    std::string getAttackReply() const override {  return "flee";  }
    std::string getCastReply() const override { return "say: Please listen to me";  }
};

#endif //ADVENTURE2019_CHARACTERMODE_H
