#include <iostream>
#include "sprite.hpp"
using namespace std;

void assertEqual(string expected, string actual, string test){
    if(expected == actual){
        cout << "Passed: " << test << endl;
    }
    else{
        cout << "Failed: " << test << endl;
        cout << "Expected: \n" << expected << endl;
        cout << "Actual: \n" << actual << endl;
    }
}

void assertEqual(double expected, double actual, string test){
    if(expected == actual){
        cout << "Passed: " << test << endl;
    }
    else{
        cout << "Failed: " << test << endl;
        cout << "Expected: \n" << expected << endl;
        cout << "Actual: \n" << actual << endl;
    }
}

void assertEqual(bool expected, bool actual, string test){
    if(expected == actual){
        cout << "Passed: " << test << endl;
    }
    else{
        cout << "Failed: " << test << endl;
        cout << "Expected: \n" << expected << endl;
        cout << "Actual: \n" << actual << endl;
    }
}

int main(){
    Sprite s1;
    assertEqual("default is a sprite of size 1.000000 at location (0.000000, 0.000000).", s1.printSprite(), "defaultPrintTest");
    s1.step(3);
    s1.step(2);
    s1.step(2);
    assertEqual("default is a sprite of size 1.000000 at location (-2.000000, -1.000000).", s1.printSprite(), "stepTest");
    Sprite s2("Hal", 3.2);
    assertEqual("Hal is a sprite of size 3.200000 at location (0.000000, 0.000000).", s2.printSprite(), "constructor1PrintTest1");
    Sprite s3("Sally", 1.5);
    assertEqual("Sally is a sprite of size 1.500000 at location (0.000000, 0.000000).", s3.printSprite(), "constructor1PrintTest2");
    Sprite s4("Fry", 5, 6.5, 2.2);
    assertEqual("Fry is a sprite of size 2.200000 at location (5.000000, 6.500000).", s4.printSprite(), "constructor2PrintTest1");
    Sprite s5("Hamlet", 1, 1, -3.5);
    assertEqual(1, s5.getSize(), "negativeSizeTest");
    assertEqual("Hal", s2.getName(), "getNameTest");
    assertEqual(1, s3.isTouching(0,0.7), "isTouchingTest1");
    assertEqual(1, s3.isTouching(0,0.8), "isTouchingTest2");
    assertEqual(0, s2.isTouching(3,3), "isTouchingTest3");
    assertEqual(1, s2.isTouching(1,-2.5), "isTouchingTest4");
    assertEqual(5,s4.getXPosition(), "getXPositionTest");
    assertEqual(6.5, s4.getYPosition(), "getYPositionTest");
    s5.setXPosition(-2);
    s5.setYPosition(5.6);
    assertEqual("Hamlet is a sprite of size 1.000000 at location (-2.000000, 5.600000).", s5.printSprite(), "setXYPositionTest");
    s5.setLocation(0,-1);
    assertEqual("Hamlet is a sprite of size 1.000000 at location (0.000000, -1.000000).", s5.printSprite(), "setLocationTest");
    assertEqual(2.2, s4.getSize(), "getSizeTest");
    return 0;
}
