//
//  Keywords.h
//  adventure2019: objects
//  com.maximpuchkov.Faworki.adventure2019.ObjectController
//
//  Created by mpuchkov on 2019-03-17 at 3:16 PM with macOS 10.13, Xcode 10.1.
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#ifndef Keywords_h
#define Keywords_h

#include "items.hpp"

namespace items {


/*!
 @class Keywords
 
 @brief Object's set of keywords
 
 @helps Object process and use keywords
 
 Container and processor of all keywords associated with an object.
 */
class Keywords: public objects::ObjectData<Keywords> {
public:
    
    /* Constructors */
    Keywords() = default;
    
    Keywords(const Keywords &keywords) = default;
    
    Keywords(const std::vector<Keyword> &keywords);
    
    // Keywords(const Set &keywords);
    
    
    
    
    /* ObjectData Protocol */
    
    std::size_t size() const noexcept override;
    
    std::string toString() const noexcept override;
    
    std::vector<std::string> toVector() const noexcept override;
    
    
    
    
    
    
    /* Keywords original functionality */
    
    /*! Set of all keywords */
    Set all() const;
    
    /*! First keyword in the set */
    Keyword first() const;
    
    /*! Last keyword in the set */
    Keyword last() const;
    
    
    
    
    
    /* Set functions */
    
    /*!
     Insert new keyword
     @warning Undefined
    */
    void insert(); /* undefined */
    
    /*!
     Erase a keyword
     @warning undefined
     */
    void erase(); /* undefined */
    
    /*! Check if keyword is in the set */
    bool contains(const Keyword &keyword) const;
    
    /*! Check if set is empty */
    bool empty() const;
    
    void clear() noexcept override;
    
    
    /* Operators */
    
    // Assignment
    Keywords& operator=(Keywords &&) noexcept;
    Keywords& operator=(const Keywords &) noexcept;
    
    // Equality
    bool operator==(Keywords &&) const noexcept;
    bool operator==(const Keywords &) const noexcept;
    
    // Inequality
    bool operator!=(Keywords &&) const noexcept;
    bool operator!=(const Keywords &) const noexcept;
    
    // operator Set() { return this->set; }
    // operator Text() { return "keywords text"; }
    
    // Stream insertion
    // friend std::ostream& operator<<(std::ostream& stream, const ObjectData *data);
    
private:
    
    /*! Container of all keywords */
    Set set;
    
    // Keywords default_data_instance() const noexcept override;

    
    // Keywords& reset() noexcept override;
    
//    Keywords default_object() const noexcept {
//        return {};
//    }
    
    //static Keywords default_object() noexcept override;
    
};


} /* namespace items */

#endif /* Keywords_h */
