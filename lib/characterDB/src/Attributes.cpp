/////////////////////////////////////////////////////////////////////////////
//                              Attributes
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

#include "Attributes.h"

Attributes::Attributes()
: health(DEF_HEALTH), damage(DEF_DAMAGE) { }

Attributes::Attributes(int health, int damage)
: health(health), damage(damage) { }

Attributes::~Attributes() { }

int Attributes::getHealth() const {
    return this->health;
}

int Attributes::getDamage() const {
    return this->damage;
}

void Attributes::setHealth(const int &value) {
    this->health = value;
}

void Attributes::setDamage(const int &value) {
    this->damage = value;
}

Attributes Attributes::operator+(const Attributes &other) const {
    int h = this->health + other.health;
    int d = this->damage + other.damage;
    return Attributes(h, d);
}
