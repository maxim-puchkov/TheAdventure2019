//
//  KeywordSet.h
//  objects
//  com.maximpuchkov.Faworki.adventure2019.KeywordSet
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

#ifndef KeywordSet_h
#define KeywordSet_h

#include <string>
#include <vector>
#include <unordered_set>
#include <sstream>

#include "Object.h"



namespace objects::data::structures {


struct KeywordSet {
public:
    
    KeywordSet();
    //template<template<typename> class Container>
    KeywordSet(const std::vector<Key> &container);
    
    bool contains(const Key &key) const;
    //void insert()
    void clear();
    unsigned int size() const;
    
    Text asString() const;
    Text asString(const Text &delimeter) const;
    
    Key first() const;
    Key last() const;
    
    
    KeywordSet& operator=(KeywordSet &);
    KeywordSet& operator=(const KeywordSet &);
    bool operator==(KeywordSet &ks) const { return this->set == ks.set; };
    bool operator==(const KeywordSet &ks) const { return this->set == ks.set; };
    
private:
    
    Set set;
    const Text SET_DELIMETER = ", ";
    
};


} /* namespace objects */



#endif /* KeywordSet_h */
