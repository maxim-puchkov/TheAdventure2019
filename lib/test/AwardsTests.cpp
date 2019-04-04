//
//  AwardsTests.cpp
//  
//
//  Created by admin on 2019-03-04.
//

#include <vector>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Awards.h"

using std::string;



namespace awards {



/* RankList Stub */
class RankListStub : public RankList {
public:
    
    // Get next name
    std::string getNext() override {
        return names.at(++index);
    }
    
    // Add a new name to the list
    void add(const string &name) {
        names.push_back(name);
    }
  
private:
    
    int index = -1;
    std::vector<std::string> names;
    
};



/* AwardCeremonyActions Mock */
class AwardCeremonyActionsMock : public AwardCeremonyActions {
public:
    
    MOCK_METHOD0(playAnthem, void());
    
    MOCK_METHOD0(turnOffTheLightsAndGoHome, void());
    
    MOCK_METHOD1(awardBronze, void(string recipient));
    
    MOCK_METHOD1(awardSilver, void(string recipient));
    
    MOCK_METHOD1(awardGold, void(string recipient));
    
};



/* AwardsTests Fixture */
class AwardsTests : public ::testing::Test {
protected:
    
    // Set up: add three names to the list
    void SetUp() override {
        list.add("Bob");
        list.add("Max");
        list.add("Nick");
    }
    
    // Award ceremony actions
    AwardCeremonyActionsMock ceremony;
    
    // List and names to be added
    RankListStub list;
    
};





// Test correctness of performance
TEST_F(AwardsTests, performAwardCeremony) {
    // Read three names from the list
    string name1 = list.getNext();
    string name2 = list.getNext();
    string name3 = list.getNext();
    
    // Expected ceremony actions
    EXPECT_CALL(ceremony, playAnthem())
        .Times(1);
    EXPECT_CALL(ceremony, awardBronze(name1))
        .Times(1);
    EXPECT_CALL(ceremony, awardSilver(name2))
        .Times(1);
    EXPECT_CALL(ceremony, awardGold(name3))
        .Times(1);
    EXPECT_CALL(ceremony, turnOffTheLightsAndGoHome())
        .Times(1);
    
    // Actual actions
    ceremony.playAnthem();
    ceremony.awardBronze(name1);
    ceremony.awardSilver(name2);
    ceremony.awardGold(name3);
    ceremony.turnOffTheLightsAndGoHome();
}



}
