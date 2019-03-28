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
#include "ItemBuilder.h"
#include "Inventory.h"


namespace items {


/// ItemBuilderTests Fixture
class InventoryTests : public testing::Test {
protected:
    
    bool initialized = false;
    
    void SetUp() override {
        // Initial set up before each test...
        initialized = true;
        
        inventory = Inventory();
        builder = ItemBuilder();
    }
    
    void TearDown() override {
        // Test ends...
    }
    

    
    
    
    /* * *         Variables        * * */
    Inventory inventory;
    
    ItemBuilder builder;
    
    
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
    
    // Build an item
    builder.setKeywords({"sword", "slot 1"});
    builder.setDescription("Testing Inventory");
    Item sword = builder.build();
    
    // Add its identifier to inventory
    inventory.add(sword.id());
    EXPECT_EQ(1, inventory.size());
    
}


// Testing add function
TEST_F(InventoryTests, Remove) {
    
    // Build an item
    builder.setKeywords({"sword", "slot 1"});
    builder.setDescription("Testing Inventory");
    Item sword = builder.build();
    
    // Add its identifier to inventory
    Identifier id = sword.id();
    inventory.add(id);
    EXPECT_EQ(1, inventory.size());
    
    // Then remove it
    inventory.remove(id);
    EXPECT_EQ(0, inventory.size());
    
}


} /* namespace items */
