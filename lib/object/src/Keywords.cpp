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

using namespace objects;

inline namespace defaults {
    const Text SET_DELIMITER = ", ";
}





/* Constructors */

Keywords::Keywords()
: set({})
{}


Keywords::Keywords(const std::vector<Key> &container)
: set(std::make_move_iterator(container.cbegin()), std::make_move_iterator(container.cend()))
{ }





/* Set functions */

void Keywords::clear() {
    this->set.clear();
}


bool Keywords::contains(const Key &key) const {
    return this->set.find(key) != this->set.cend();
}


bool Keywords::empty() const {
    return this->set.empty();
}


size_t Keywords::size() const {
    return this->set.size();
}





/* Keywords */

Set Keywords::all() const {
    return this->set;
}


Key Keywords::first() const {
    return *this->set.cbegin();
}


Key Keywords::last() const {
    return *this->set.crbegin();
}


Text Keywords::asString() const {
    return this->asString(SET_DELIMITER);
}


Text Keywords::asString(const Text &delimiter) const {
    // If set is empty, return empty string
    if (this->empty()) {
        const Text EmptyText = "";
        return EmptyText;
    }
    
    // Start from the first keyword
    auto iterator = this->set.cbegin();
    std::ostringstream oss;
    oss << *iterator;
    iterator++;
    
    // Add delimiter and next keyword until the end
    while (iterator != this->set.cend()) {
        oss << delimiter << *iterator;
        iterator++;
    }
    
    return oss.str();
}





/* Convert */

std::vector<Key> Keywords::toVector() const {
    return {this->set.cbegin(), this->set.cend()};
}






/* Operators */

// Assignment
Keywords& Keywords::operator=(Keywords &other) {
    this->set = other.set;
    return *this;
}

Keywords& Keywords::operator=(const Keywords &other) {
    this->set = other.set;
    return *this;
}


// Equality
bool Keywords::operator==(Keywords &other) const {
    return (this->set == other.set);
}

bool Keywords::operator==(const Keywords &other) const {
    return (this->set == other.set);
}


// Inequality
bool Keywords::operator!=(Keywords &other) const {
    return (this->set != other.set);
}

bool Keywords::operator!=(const Keywords &other) const {
    return (this->set != other.set);
}
