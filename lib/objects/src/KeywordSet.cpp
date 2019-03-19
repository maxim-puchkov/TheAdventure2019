//
//  KeywordSet.cpp
//  objects
//  com.maximpuchkov.Faworki.adventure2019.KeywordSet
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

#include "KeywordSet.h"

using namespace objects::data;

KeywordSet::KeywordSet() {
    this->set = std::unordered_set<Key>();
    
}


void KeywordSet::clear()
{ }


bool KeywordSet::contains(const Key &key) const {
    return true;
}


Key KeywordSet::first() const {
    return *this->set.cbegin();
}


Key KeywordSet::last() const {
    return *this->set.cend();
}

Text KeywordSet::asString() const {
    return this->asString(SET_DELIMETER);
}


Text KeywordSet::asString(const Text &delimeter) const {
    std::ostringstream oss;
    
    for (auto &key : this->set) {
        oss << key << delimeter;
    }
    
    return oss.str();
}


KeywordSet& KeywordSet::operator=(KeywordSet &other) {
    this->set = other.set;
    return *this;
}


KeywordSet& KeywordSet::operator=(const KeywordSet &other) {
    this->set = other.set;
    return *this;
}
