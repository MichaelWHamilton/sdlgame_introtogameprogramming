// componentstake5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define SDL_MAIN_HANDLED
#include "Engine.h"
#include "GameObject.h"
#include "SpriteComponent.h"
#include "BodyComponent.h"
#include "CharacterControllerComponent.h"
#include <box2d/box2d.h>
#include "CollisionComponent.h"
#include "AnimatorComponent.h"
//void createGroundObject();

int main() {
    if (!Engine::init("SDL2 Game Engine", 800, 600)) {
        return -1;
    }
    SDL_Renderer* renderer = Engine::getRenderer();
    // Create and add a GameObject with a SpriteComponent
    auto player = std::make_unique<GameObject>();
    auto p2 = std::make_unique<GameObject>();
    auto ground = std::make_unique<GameObject>();

 
    Textures::load("player1", "C:\\Users\\mikey\\Downloads\\R.png", renderer);
    Textures::load("ground", "C:\\Users\\mikey\\OneDrive\\Desktop\\ground.png", renderer);
    Textures::load("player_spritesheet", "C:\\Users\\mikey\\Downloads\\MainGuySpriteSheet.png", renderer);
    
   //createGroundObject();

    ground->add<SpriteComponent>("ground", 800, 600); 
    ground->add<BodyComponent>(0, 500);
    
    

    player->add<SpriteComponent>("player1");
    player->add<BodyComponent>(100,200);
    player->add<CharacterControllerComponent>(10);
    player->add<AnimatorComponent>();

    p2->add<SpriteComponent>("player1");
    p2->add<BodyComponent>(200, 300);


    
    

    Engine::addGameObject(std::move(ground));
    Engine::addGameObject(std::move(player));
    Engine::addGameObject(std::move(p2));
    
    

    // Run the game
    Engine::run();

    return 0;
}


