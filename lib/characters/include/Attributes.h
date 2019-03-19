/////////////////////////////////////////////////////////////////////////////
//                              Attributes
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

#ifndef Attributes_h
#define Attributes_h

const int DEF_HEALTH = 100;
const int DEF_DAMAGE = 10;

/**
 *  @class Attributes
 *
 *  @brief Manages characters' attributes.
 *
 *  Character has health, damage.
 *  Equipment can improve some attributes.
 */
class Attributes {
public:
    
    Attributes();
    
    Attributes(int health, int damage);
    
    ~Attributes();
    
    int getHealth() const;
    
    int getDamage() const;

    void setHealth(const int &value);

    void setDamage(const int &value);
    
    Attributes operator+(const Attributes &other);
    
private:
    
    int health;
    
    int damage;
    
};

#endif /* Attributes_h */
