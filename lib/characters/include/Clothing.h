//
//  Clothing.h
//  test
//
//  Created by admin on 2019-01-17.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#ifndef Clothing_h
#define Clothing_h

class Clothing {
public:
    
    Clothing() {
        // this->attributes = Attributes(10, 0);
    }
    
    Clothing(const Attributes &attr) {
        this->attributes = attr;
    }
    
    virtual ~Clothing() { }
    
    virtual Attributes getAttributes() const {
        return this->attributes;
    }
    
private:
    
    Attributes attributes;
    
};


#endif /* Clothing_h */
