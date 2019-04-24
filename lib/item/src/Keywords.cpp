//
//  Keywords.cpp
//  objects
//  com.maximpuchkov.Faworki.adventure2019.Keywords
//
//  Package:             adventure2019
//  Project:             adventure2019
//  Workspace:           Faworki
//  Organization:        maximpuchkov
//  Prefix:              com
//
//  Author:              Maxim Puchkov (mpuchkov@sfu.ca)
//  Full username:       admin
//  Created on:          2019-03-17 at 3:21 PM
//  System:              macOS 10.13
//  Tools:               Xcode v.10.1 (10B61); Swift 4.0
//
//  Created by admin (Maxim Puchkov).
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#include "Keywords.h"

namespace items {


/* Constructors */

Keywords::Keywords(const std::vector<Keyword> &keywords)
    : set(std::make_move_iterator(keywords.cbegin()),
          std::make_move_iterator(keywords.cend()))
{ }

//Keywords::Keywords(const Set &keywords)
//    : set(keywords)
//{ }





/* ObjectData Protocol */


std::size_t Keywords::size() const noexcept {
    return this->set.size();
}
    

std::string Keywords::toString() const noexcept {
    // If set is empty, return empty string
    if (this->empty()) {
        return EMPTY;
    }
    
    // Start from the first keyword
    auto iterator = this->set.cbegin();
    OStream stream;
    stream << *iterator;
    
    // Add delimiter and next keyword until the end
    const auto DEL = ui::text::styles::CS;
    for (iterator++; iterator != this->set.cend(); iterator++) {
    // while (iterator != this->set.cend()) {
        stream << DEL << *iterator;
        // iterator++;
    }
    
    return stream.str();
}


vector<string> Keywords::toVector() const noexcept {
    return {
        this->set.cbegin(), this->set.cend()
    };
}





/* Set functions */

bool Keywords::contains(const Keyword &key) const {
    return (this->set.find(key) != this->set.cend());
}

bool Keywords::empty() const {
    return this->set.empty();
}




/* Keywords */

Set Keywords::all() const {
    return this->set;
}


Keyword Keywords::first() const {
    return *(this->set.cbegin());
}

Keyword Keywords::last() const {
    return *(this->set.crbegin());
}




// !
/* Operators */

// Assignment
//Keywords& Keywords::operator=(Keywords &&other) noexcept {
//    this->set = std::move(other.set);
//    return *this;
//}
//
//Keywords& Keywords::operator=(const Keywords &other) noexcept {
//    this->set = other.set;
//    return *this;
//}


// Equality
bool Keywords::operator==(Keywords &&other) const noexcept {
    return (this->set == other.set);
}

bool Keywords::operator==(const Keywords &other) const noexcept {
    return (this->set == other.set);
}


// Inequality
bool Keywords::operator!=(Keywords &&other) const noexcept {
    return (this->set != other.set);
}

bool Keywords::operator!=(const Keywords &other) const noexcept {
    return (this->set != other.set);
}


void Keywords::clear() noexcept {
    this->set.clear();
}
    
//Keywords Keywords::default_data_instance() const noexcept {
//    return Keywords::DEFAULT_INSTANCE;
//}

    
//    Keywords Keywords::restoreDefaults() noexcept {
//        return Keywords{};
//    }

} /* namespace items */
