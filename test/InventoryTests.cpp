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


// Testing add function
TEST_F(InventoryTests, Add) {
    
    string desc = "Testing Inventory";
    
    builder.setKeywords({"sword", "slot 1"});
    builder.setDescription(desc);
    Item sword = builder.create();
    
    inventory.add(sword.id());
    
    EXPECT_TRUE(inventory.size() == 1);
    
}
