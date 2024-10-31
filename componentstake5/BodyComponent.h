#pragma once
#include "Component.h"
#include <iostream>

class BodyComponent : public Component {
public:
    double xPos, yPos, xVel, yVel;  // Position

    BodyComponent(GameObject& parentObj, double x, double y)
        : Component(parentObj), xPos(x), yPos(y), xVel(x), yVel(y) {}


    double& x() { return xPos; }
    double& y() { return yPos; }
    double& vx() { return xVel; }
    double& vy() { return yVel; }

    void update() override {
        //// Example: Move the object downwards
        //y += 1.0f;
        //std::cout << "BodyComponent updated position: (" << x << ", " << y << ")\n";
    }

    void draw() override {
        // Drawing logic would go here (if needed)
    }
};
