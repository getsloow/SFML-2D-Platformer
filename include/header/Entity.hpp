#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Hitbox.hpp"

using namespace sf;
class Entity : public Sprite{
public:
    Vector2f velocity, size, frameSize, framesAmount;
    hitBox hitbox;
    std::vector <sf::IntRect> frames;

};

