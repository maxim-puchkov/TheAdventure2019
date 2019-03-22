//
//  KeywordsTests.cpp
//  adventure2019: Object
//  com.maximpuchkov.Faworki.adventure2019.ObjectTests
//
//  Created by mpuchkov on 2019-03-21. macOS 10.13, Xcode 10.1.
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "KeywordSet.h"


namespace objects {


    
    
/// ItemBuilderTests Fixture
class KeywordsTests : public testing::Test {
protected:

    bool initialized = false;
    
    
    void SetUp() override {
        // Initial set up before each test...
        initialized = true;
    }
    
    void TearDown() override {
        // Test ends...
    }
    

    
    
    
    /* * *         Variables        * * */
    using S = std::string;
    using V = std::vector<S>;
    
    V keys_1{"Keyword 1", "Keyword 2", "Keyword 3"};
    
    V keys_3a{"Sword", "rare"};
    V keys_3b{"Shield", "rare"};
    V keys_3c{"Armor", "rare"};
    
    
    V keys_2a{"UPPER", "lower", "3AlphaNum", "4_Keyword Matching."};
    V keys_2b{"upper", "LOWER", "3aLPHAnUM", "4_Keyword Matching."};
    

    V keys_4a{"Partial matching", "Testing Keywords"};
    S search4a{"Partial ma"};
    S search4b{"This will not match any keyword"};
    
    
};




using Keywords = KeywordSet;




/* Object Fixture Tests */

// Testing test fixture set up
TEST_F(KeywordsTests, FixtureInitialization) {
    EXPECT_TRUE(initialized);
}

// Testing default constructor
TEST_F(KeywordsTests, Instantiation) {
    Keywords keys = KeywordSet(keys_1);
    EXPECT_EQ(keys_1, keys.toVector());
}
    

    
TEST_F(KeywordsTests, Size) {
    Keywords keys3a{keys_3a};
    Keywords keys3b{keys_3b};
    Keywords keys3c{keys_3c};
    
    EXPECT_EQ(keys_3a.size(), keys3a.size());
    EXPECT_EQ(keys_3b.size(), keys3b.size());
    EXPECT_EQ(keys_3c.size(), keys3c.size());
}

TEST_F(KeywordsTests, Clear) {
    Keywords keys{keys_1};
    EXPECT_NE(0, keys.size());
    
    keys.clear();
    EXPECT_EQ(0, keys.size());
}

TEST_F(KeywordsTests, Contains) {
    Keywords keys{keys_1};
    for (auto &key : keys_1) {
        EXPECT_TRUE(keys.contains(key));
    }
}

TEST_F(KeywordsTests, FirstKeyword) {
    Keywords keys{keys_1};
    EXPECT_EQ(keys_1.front(), keys.first());
}

TEST_F(KeywordsTests, LastKeyword) {
    Keywords keys{keys_1};
    EXPECT_EQ(keys_1.back(), keys.last());
}
    
TEST_F(KeywordsTests, Equality) {
    Keywords sword{keys_3a};
    Keywords shield{keys_3b};
    
    EXPECT_TRUE(sword == sword);
    EXPECT_TRUE(shield == shield);
    EXPECT_FALSE(sword == shield);
    EXPECT_FALSE(shield == sword);
}

TEST_F(KeywordsTests, Inequality) {
    Keywords sword{keys_3a};
    Keywords shield{keys_3b};
    
    EXPECT_TRUE(sword != shield);
    EXPECT_TRUE(shield != sword);
    EXPECT_FALSE(sword != sword);
    EXPECT_FALSE(shield != shield);
}
    
    
    
    // TEST_F(KeywordsTests, CaseInsensetivity) { }
    
    // TEST_F(KeywordsTests, PartialMatching) { }

} /* namespace objects */
