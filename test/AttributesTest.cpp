#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Attributes.h"

TEST(AttributesTest, ConstructorCorrectValues) {
    int healthValue = 1;
    int damageValue = 2;
    Attributes testObject(healthValue, damageValue);

    EXPECT_EQ(healthValue, testObject.getHealth());
    EXPECT_EQ(damageValue, testObject.getDamage());
}

TEST(AttributesTest, OverloadedOperatorWorkCorrectly) {
    int healthValue1 = 50;
    int healthValue2 = 100;
    int damageValue1 = 2;
    int damageValue2 = 20;
    Attributes testObject1(healthValue1, damageValue1);
    Attributes testObject2(healthValue2, damageValue2);

    testObject1 = testObject1 + testObject2;

    EXPECT_EQ(healthValue1 + healthValue2, testObject1.getHealth());
    EXPECT_EQ(damageValue1 + damageValue2, testObject1.getDamage());
    EXPECT_EQ(healthValue2, testObject2.getHealth());
    EXPECT_EQ(damageValue2, testObject2.getDamage());
}

TEST(AttributesTest, Setters) {
    Attributes testObject(100, 100);
    testObject.setHealth(10);
    testObject.setDamage(10);
    
    EXPECT_EQ(10, testObject.getHealth());
    EXPECT_EQ(10, testObject.getDamage());
}