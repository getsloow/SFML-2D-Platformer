#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include <iostream>

class Platform : public Entity{
		public:
            Platform(float X, float Y, float W, float H, sf::Texture& t);


};

