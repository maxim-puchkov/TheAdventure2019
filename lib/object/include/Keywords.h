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

#include "objects.hpp"
#include "ObjectData.h"


namespace objects {

inline namespace data {


/*!
 @struct Keywords
 
 @brief Object's set of keywords
 
 @helps Object process and use keywords
 
 Container and processor of all keywords associated with an object.
 */
class Keywords: public ObjectData<Keywords> {
public:
    
    /* Constructors */
    
    Keywords();
    
    Keywords(const std::vector<Key> &container);

    
    
    
    
    /* ObjectData Protocol */
    
    string toString() const noexcept override;
    
    vector<string> toVector() const noexcept override;
    
    
    
    
    
    /* Keywords */
    
    /*! All keywords */
    Set all() const;
    
    /*! First keyword in the set */
    Key first() const;
    
    /*! Last keyword in the set */
    Key last() const;
    
    
    
    
    
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
    bool contains(const Key &key) const;
    
    /*! Check if set is empty */
    bool empty() const;
    
    /*! Clear set contents */
    void clear();
    
    /*! Current set size */
    size_t size() const;
    
    
    
    
    
    /* Operators */
    
    // Assignment
    Keywords& operator=(Keywords &);
    Keywords& operator=(const Keywords &);
    
    // Equality
    bool operator==(Keywords &other) const;
    bool operator==(const Keywords &other) const;
    
    // Inequality
    bool operator!=(Keywords &other) const;
    bool operator!=(const Keywords &other) const;
    
    // Stream insertion
    // friend std::ostream& operator<<(std::ostream& stream, const ObjectData *data);
    
private:
    
    /*! Set that contains all of the keywords */
    Set set;
    
};


} /* namespace structures */

} /* namespace objects */

#endif /* Keywords_h */
