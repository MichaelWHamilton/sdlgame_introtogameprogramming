#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "Component.h"
#include "BodyComponent.h"
#include "GameObject.h"

class CharacterControllerComponent : public Component {
public:
    CharacterControllerComponent(GameObject& owner, float speed)
        : Component(owner), speed(speed) {}

    void update() override {
        const Uint8* state = SDL_GetKeyboardState(nullptr);
        if (state[SDL_SCANCODE_W]) { move(0, -1); }
        if (state[SDL_SCANCODE_S]) { move(0, 1); }
        if (state[SDL_SCANCODE_A]) { move(-1, 0); }
        if (state[SDL_SCANCODE_D]) { move(1, 0); }
    }

    void draw() override{}
private:
    float speed;

    void move(float dx, float dy) {
        auto body = getParent().get<BodyComponent>();
        if (body) {
            body->x() += dx * speed;
            body->y() += dy * speed;
        }
    }
};