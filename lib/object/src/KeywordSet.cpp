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
using namespace objects;


KeywordSet::KeywordSet() {
    this->set = std::unordered_set<Key>();
    
}

//template<template<typename> class Container>
KeywordSet::KeywordSet(const std::vector<Key> &container) {
    this->set = std::unordered_set<Key>(std::make_move_iterator(container.cbegin()), std::make_move_iterator(container.cend()));
}



void KeywordSet::clear() {
    this->set.clear();
}

bool KeywordSet::contains(const Key &key) const {
    return this->set.find(key) != this->set.cend();
}

bool KeywordSet::empty() const {
    return this->set.empty();
}

size_t KeywordSet::size() const {
    return this->set.size();
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
    if (this->empty()) {
        const Text EmptyText = "";
        return EmptyText;
    }
    
    
    auto iterator = this->set.cbegin();
    std::ostringstream oss;
    oss << *iterator;
    iterator++;
    
    while (iterator != this->set.cend()) {
        oss << delimeter << *iterator;
        iterator++;
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
