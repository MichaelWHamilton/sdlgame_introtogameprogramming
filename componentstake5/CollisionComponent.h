#pragma once
#include <box2d/box2d.h>
#include "Component.h"

class CollisionComponent : public Component {
public:
    CollisionComponent(GameObject& parentObj, float x, float y, float width, float height, b2World* world) :Component(parentObj){
        // Define the body
        b2BodyDef bodyDef;
        bodyDef.type = b2_dynamicBody; // or b2_staticBody for non-moving objects
        bodyDef.position.Set(x, y);
        body = world->CreateBody(&bodyDef);

        // Create a box shape
        b2PolygonShape box;
        box.SetAsBox(width / 2, height / 2); // Half width and height

        // Define the fixture
        b2FixtureDef fixtureDef;
        fixtureDef.shape = &box;
        fixtureDef.density = 1.0f; // Set density
        fixtureDef.friction = 0.5f; // Friction

        body->CreateFixture(&fixtureDef);
    }

    //~CollisionComponent() override{
    //    // Cleanup logic if necessary
    //    if (body) {
    //        body->GetWorld()->DestroyBody(body);
    //    }
    //}

    void update() override {
        
    }
    void draw() override {};
    b2Body* getBody() const {
        return body;
    }

private:
    b2Body* body; // Box2D body associated with this component
};
