//
//  Appearance.h
//  Test2
//
//  Created by admin on 2019-01-18.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#ifndef Appearance_h
#define Appearance_h

namespace Custom {
    
    // Customizable charateristics will
    // determine Avatar's Appearance and Attributes
    enum Sex { Male, Female };
    enum Age { Old, Young };
    enum Skill { Fighting, Programming };
    
    class Appearance {
    public:
        
        Appearance() { }
        
        Appearance(Sex sex, Age age, Skill skill)
        : sex(sex), age(age), skill(skill) { }
        
        void setSex(Sex s) { this->sex = s; }
        
        void setAge(Age a) { this->age = a; }
        
        void setSkill(Skill s) { this->skill = s; }
        
    private:
        
        Sex sex;
        
        Age age;
        
        Skill skill;
        
    };
    
}

#endif /* Appearance_h */
