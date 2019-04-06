//
//  InventoryTests.cpp
//  adventure2019: adventure2019
//  com.maximpuchkov.Faworki.adventure2019.InventoryTests
//
//  Created by mpuchkov on 2019-03-24. macOS 10.13, Xcode 10.1.
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Item.h"
#include "Inventory.h"


namespace items {


/// ItemBuilderTests Fixture
class InventoryTests : public testing::Test {
protected:
    
    bool initialized = false;
    
    void SetUp() override {
        // Initial set up before each test...
        initialized = true;
        
//        builder = ItemBuilder();
    }
    
    void TearDown() override {
        // Test ends...
    }
    

    
    
    
    /* * *         Variables        * * */
    
    Inventory inventory = Inventory();
    
};









/* Inventory Fixture Tests */

// Testing test fixture set up
TEST_F(InventoryTests, FixtureInitialization) {
    EXPECT_TRUE(initialized);
}


// Testing instantiation
TEST_F(InventoryTests, Instantiation) {
    Inventory test_inventory = Inventory();
    EXPECT_EQ(0, inventory.size());
}


// Testing add function
TEST_F(InventoryTests, Add) {
    Identifier id = 0;
    inventory.add(id);
    // EXPECT_EQ(id, inventory[0]);
    EXPECT_EQ(1, inventory.size());
}


/* Remove not implemented */
// Testing add function
TEST_F(InventoryTests, DISABLED_Remove) {
    // Add identifier to inventory
    Identifier id = 0;
    inventory.add(id);
    // EXPECT_EQ(id, inventory[0]);
    EXPECT_EQ(1, inventory.size());
    
    // Then remove it
    inventory.remove(id);
    EXPECT_EQ(0, inventory.size());
}
    
    
    
    TEST_F(InventoryTests, DISABLED_Contains) {
        Identifier id = 0;
        EXPECT_FALSE(inventory.contains(id));
        
        inventory.add(id);
        EXPECT_TRUE(inventory.contains(id));
        
        inventory.remove(id);
        EXPECT_FALSE(inventory.contains(id));
    }

    
    
    TEST_F(InventoryTests, Order) {
        const int size = 3;
        Identifier ids[size] = {1, 2, 3};
        
        for (auto id : ids) {
            inventory.add(id);
        }
        
        EXPECT_EQ(size, inventory.size());
        
//        for (auto id : inventory) {
//            EXPECT_EQ();
//        }
        
        
    }


} /* namespace items */
