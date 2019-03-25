//
//  Keywords.h
//  objects
//  com.maximpuchkov.Faworki.adventure2019.Keywords
//
//  Package:             objects
//  Project:             adventure2019
//  Workspace:           Faworki
//  Organization:        maximpuchkov
//  Prefix:              com
//
//  Author:              Maxim Puchkov (mpuchkov@sfu.ca)
//  Full username:       admin
//  Created on:          2019-03-17 at 3:16 PM
//  System:              macOS 10.13
//  Tools:               Xcode v.10.1 (10B61); Swift 4.0
//
//  Created by admin (Maxim Puchkov).
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#ifndef Keywords_h
#define Keywords_h

#include "objects.hpp"

namespace objects {

inline namespace structures {


struct Keywords {
public:
    
    /* Constructors */
    
    Keywords();
    
    Keywords(const std::vector<Key> &container);

    
    
    
    
    /* Keywords */
    
    /// All keywords
    Set all() const;
    
    /// First keyword in the set
    Key first() const;
    
    /// Last keyword in the set
    Key last() const;
    
    /// Convert to text
    Text asString() const;
    
    /// Convert to text seperated by delimiter
    Text asString(const Text &delimiter) const;
    
    
    
    
    
    /* Set functions */
    
    /// Insert new keyword
    void insert(); /* undefined */
    
    /// Erase a keyword
    void erase(); /* undefined */
    
    /// Check if keyword is in the set
    bool contains(const Key &key) const;
    
    /// Check if set is empty
    bool empty() const;
    
    /// Clear set contents
    void clear();
    
    /// Current set size
    size_t size() const;
    
    
    
    
    
    /* Convert */
    
    std::vector<Key> toVector() const;
    
    
    
    
    
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
    
private:
    
    Set set;
    
};


} /* namespace structures */

} /* namespace objects */

#endif /* Keywords_h */
