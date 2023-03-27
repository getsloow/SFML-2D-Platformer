#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include <iostream>


class Ground : public Entity{
		public:
            Ground(float X, float Y, float W, float H, sf::Texture& t);


};

class Ground2 : public Entity{
		public:
            Ground2(float X, float Y, float W, float H, sf::Texture& t);


};

class EndLevel : public Entity{
		public:
            EndLevel(float X, float Y, float W, float H, sf::Texture& t);


};

class Coins : public Entity{
        public:
            Coins(float X, float Y, float W, float H, sf::Texture& t);



        };
