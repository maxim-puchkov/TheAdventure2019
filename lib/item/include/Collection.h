//
//  Collection.h
//  adventure2019
//
//  Created by admin on 2019-02-06.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#ifndef Collection_h
#define Collection_h

#include <string>
#include <unordered_set>
#include <functional>

#include "Object.h"
#include "Item.h"


namespace objects {
using objects::KeywordSet;
using objects::Description;
    
    template<typename ...T>
    struct Container {
        
        
        
    };

inline namespace items {
/*!
 @class Collection
 
 @brief Game chests, bags, inventory
 
 Collection
 */
//template<typename T, unsigned int capacity>
class Collection : public Object {
public:
    
    /* Collection slot */
    using T = Item;
    struct Slot {
        int number;
        bool empty;
        T *t;
        
        Slot(int n)
        : number(n), empty(true)
        { }
        
        bool operator<(Slot s) const {
            return (this->number < s.number);
        }
    };
    /* * * * */
    
    
    Collection() { }
    
    ~Collection() { }
    
    /*
    Collection(Identifier id,
               const KeywordSet &keywords,
               const Description &description,
               const Extras &extras)
    : collectionID(id), keywords(keywords), description(description), extras(extras) {
        for (unsigned int i = 0; i < 1; i++) {
            this->set.insert(Slot(i));
        }
    }
    */
    
    
    Collection(const Item &item, unsigned int capacity)
    : container(item), capacity(capacity) {
        for (unsigned int i = 0; i < capacity; i++) {
            // this->set.insert(Slot(i));
        }
    }

   /// Retrieve object ID
    Identifier id() const override;
    
    
    /// Set of keywords describing this item
    KeywordSet keywords;
    
    Description description;
    
    Actions actions;
    
    
    /// Display item's first keyword
    Key brief() const override;
    
    
    /// Display detailed info
    Text display() const override;
    
    
//    Actions allActions() const override {
//        return this->actions;
//    }
    
    bool hasKeyword(const Key &keyword) const;
    
    /// Examine an Extra attribute of an item
    Text examine(const Key &keyword) const override;
    
    // template<typename ...T> v
    //void print(T &&...ts) { (std::cout << ... << ts) << std::endl; }
    //template<typename N = T, typename >
    bool insert(const Item &item) {
        return this->set.insert(item.id()).second;
        // return this->set.insert(t).second;
    }
    
    bool erase(const Item &item) {
        bool valid = (this->set.find(item.id()) != this->set.cend());
        this->set.erase(item.id());
        return valid;
        // return false;
    }
    
    size_t size() {
        return this->set.size();
    }

    
private:
    
    Item container;
    
    unsigned int capacity;

    std::set<Identifier> set;
    
    Identifier collectionID;
    
    
    

    
};


} /* namespace items */
} /* namespace objects */

#endif /* Collection_h */
