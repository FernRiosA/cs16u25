#include "sprite.hpp"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;


Sprite::Sprite() {
    name = "default";
    xPosition = 0.0;
    yPosition = 0.0;
    size = 1.0;
}


Sprite::Sprite(string name, double size) {
    this->name = name;
    xPosition = 0.0;
    yPosition = 0.0;
    
    if (size <= 0) {
        cout << "Size must be a nonzero positive value." << endl;
        this->size = 1.0;
    } else {
        this->size = size;
    }
}


Sprite::Sprite(string name, double x, double y, double size) {
    this->name = name;
    xPosition = x;
    yPosition = y;
    
    if (size <= 0) {
        cout << "Size must be a nonzero positive value." << endl;
        this->size = 1.0;
    } else {
        this->size = size;
    }
}


void Sprite::step(int direction) {
    switch (direction) {
        case 0:
            xPosition += 1.0;
            break;
        case 1:
            yPosition += 1.0;
            break;
        case 2:
            xPosition -= 1.0;
            break;
        case 3:
            yPosition -= 1.0;
            break;
        default:
            break;
    }
}


bool Sprite::isTouching(double x, double y) {
    double distance = sqrt(pow(x - xPosition, 2) + pow(y - yPosition, 2));
    return distance <= size;
}


string Sprite::printSprite() {
    return name + " is a sprite of size " + to_string(size) + 
           " at location (" + to_string(xPosition) + ", " + 
           to_string(yPosition) + ").";
}


string Sprite::getName() {
    return name;
}

double Sprite::getXPosition() {
    return xPosition;
}

double Sprite::getYPosition() {
    return yPosition;
}

double Sprite::getSize() {
    return size;
}


void Sprite::setName(string name) {
    this->name = name;
}

void Sprite::setXPosition(double x) {
    xPosition = x;
}

void Sprite::setYPosition(double y) {
    yPosition = y;
}

void Sprite::setSize(double size) {
    if (size <= 0) {
        cout << "Size must be a nonzero positive value." << endl;
        this->size = 1.0;
    } else {
        this->size = size;
    }
}

void Sprite::setLocation(double x, double y) {
    xPosition = x;
    yPosition = y;
}
