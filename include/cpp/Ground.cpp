#include <SFML/Graphics.hpp>
#include "../header/Entity.hpp"
#include "../header/ground.hpp"

Ground::Ground(float X, float Y, float W, float H, sf::Texture& t){

   size.x = W;
   size.y = H;

    hitbox.left = X + 0.f;
    hitbox.right = X + size.x - 0.f;
    hitbox.top = Y+ 0.f;
    hitbox.bottom = Y+ size.y - 0.f;

    setTexture(t);

    setPosition(X, Y);

}

Ground2::Ground2(float X, float Y, float W, float H, sf::Texture& t){

   size.x = W;
   size.y = H;

    hitbox.left = X + 0.f;
    hitbox.right = X + size.x - 0.f;
    hitbox.top = Y+ 0.f;
    hitbox.bottom = Y+ size.y - 0.f;

    setTexture(t);

    setPosition(X, Y);

}


EndLevel::EndLevel(float X, float Y, float W, float H, sf::Texture& t){

   size.x = W;
   size.y = H;

    hitbox.left = X + 0.f;
    hitbox.right = X + size.x - 0.f;
    hitbox.top = Y+ 0.f;
    hitbox.bottom = Y+ size.y - 0.f;

    setTexture(t);

    setPosition(X, Y);

}

Coins::Coins (float X, float Y, float W, float H, sf::Texture& t){

   size.x = W;
   size.y = H;

    hitbox.left = X + 0.f;
    hitbox.right = X + size.x - 0.f;
    hitbox.top = Y+ 0.f;
    hitbox.bottom = Y+ size.y - 0.f;

    setTexture(t);

    setPosition(X, Y);

}


