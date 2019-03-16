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
#include "Object.h"

using objects::Object;



template<typename T>
class Collection : public Object {
public:
    
    Collection() { }
    
    
    
private:
    
    
    std::unordered_set<T> items;
    
};


//
//using std::unordered_set;
//using std::string;
//
//
//template<typename T, int capacity>
//class Collection : public objects::Object {
//public:
//    
//    Collection();
//    
//    
//    bool add(T object);
//    bool remove(T object);
//    
//    
//    T find(T object); /* undefined */
//    void display(); /* undefined */
//    
//    
//    int sizeCapacity();
//    unsigned int size();
//    bool isFull();
//    
//private:
//    
//    unordered_set<T> items;
//
//};
//






/**
 *  @class Collection
 *
 *  @brief Collection of items.
 *
 *  Collection of items (bag, chest) is also an item.
 */

    /*
     #include <functional>
     #include <sstream>
     #include <iostream>
     const unsigned int NO_LIMIT = 0;
     
    Collection(const string &description);
    Collection(Collection &&c);
    ~Collection();
    */
    /* Retrieve */
    /*
    unordered_set<Item> getItems() const;
    string getShortDescription() const override;
    string getLongDescription() const override;
    */
    /* Modify */
    /*
    void setLimit(unsigned int limit);
    bool add(Item &&item);
    bool remove(Item &&item);
    Collection& operator=(Collection &&c) noexcept;
    */
    /* private: */
    /*
    string shortDescription;
    string longDescription;
    unordered_set<Item> items;
    unsigned int limit = NO_LIMIT;
    bool isLimited();
    bool isFull();
    */

#endif /* Collection_h */
