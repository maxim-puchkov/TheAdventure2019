//
//  Attributes.h
//  test
//
//  Created by admin on 2019-01-17.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#ifndef Attributes_h
#define Attributes_h

class Attributes {
public:
    
    Attributes();
    
    // Add character's base + equipment attributes together
    Attributes operator+(Attributes other);
    
private:
    int health;
    int damage;
    int speed;
    int attackSpeed;
    int regeneration;
};


#endif /* Attributes_h */
