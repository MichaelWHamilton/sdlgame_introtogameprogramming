#pragma once
#include "Component.h"
#include <SDL2/SDL.h>
#include <vector>
#include <string>
#include <map>

class AnimatorComponent : public Component {
public:
    AnimatorComponent(GameObject& parent) : Component(parent), currentAnimation(""), frameIndex(0), frameTime(0) {}

    void addAnimation(const std::string& name, const std::vector<SDL_Rect>& frames, int speed) {
        animations[name] = { frames, speed };
    }

    void setAnimation(const std::string& name) {
        if (animations.find(name) != animations.end()) {
            currentAnimation = name;
            frameIndex = 0;  // Reset to the first frame of the new animation
            frameTime = 0;   // Reset the frame time
        }
    }

    void update() override {
        if (currentAnimation.empty()) return;

        auto& anim = animations[currentAnimation];
        frameTime++;

        // Update frame based on frameTime and speed
        if (frameTime >= anim.speed) {
            frameIndex = (frameIndex + 1) % anim.frames.size();
            frameTime = 0;  // Reset the frame time
        }
    }
    void draw() override {};

    SDL_Rect getCurrentFrame() const {
        if (currentAnimation.empty()) return SDL_Rect{ 0, 0, 0, 0 };
        return animations.at(currentAnimation).frames[frameIndex];
    }

private:
    struct Animation {
        std::vector<SDL_Rect> frames; // The frames of the animation
        int speed;                    // Frames per update
    };

    std::map<std::string, Animation> animations; // All animations
    std::string currentAnimation;                 // The current animation name
    size_t frameIndex;                            // Current frame index
    int frameTime;                                // Frame timer
};
