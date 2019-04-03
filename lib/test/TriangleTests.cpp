//
//  TriangleTests.cpp
//  
//
//  Created by admin on 2019-03-03.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Triangle.h"



namespace shapes {



class TriangleTests : public ::testing::Test {
protected:
    
    // Side lengths
    int a = 7;
    int b = 5;
    int c = 4;

};





// Test perimeter (fails)
TEST_F(TriangleTests, scaleneGetPerimeter) {
    Triangle triangle(a, b, c);
    int triangle_perimeter = a + b + c;
    EXPECT_EQ(triangle_perimeter, triangle.getPerimeter());
}


// Test formula (fails)
TEST_F(TriangleTests, heronsFormula) {
    Triangle triangle(a, b, c);
    double s = (a + b + c) / 2.0; // half_perimeter
    double herons_formula = sqrt(s * (s - a) * (s - b) * (s - c));
    EXPECT_EQ(herons_formula, triangle.getArea());
}
    

// Test kind (fails)
TEST_F(TriangleTests, equilateralGetKind) {
    Triangle::Kind kind = Triangle(a, a, a).getKind();
    EXPECT_EQ(Triangle::Kind::EQUILATERAL, kind);
}


// Test perimeter
TEST_F(TriangleTests, isoscelesGetPerimeter) {
    Triangle triangle(a, b, b);
    int triangle_perimeter = a + b + b;
    EXPECT_EQ(triangle_perimeter, triangle.getPerimeter());
}
    
// Test half perimieter calculation
TEST_F(TriangleTests, isoscelesHalfPerimeter) {
    Triangle triangle(a, b, b);
    double half_perimeter = (a + b + b) / 2.0;
    EXPECT_EQ(triangle.getPerimeter(), half_perimeter * 2.0);
}


// Test kind
TEST_F(TriangleTests, isoscelesGetKind) {
    Triangle::Kind kind = Triangle(a, b, b).getKind();
    EXPECT_EQ(Triangle::Kind::ISOSCELES, kind);
}

 

}
