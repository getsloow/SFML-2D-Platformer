#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "Platform.hpp"

class Background : public Entity{
		public:
            Background(float X, float Y, float W, float H, sf::Texture& t);


};


Background::Background(float X, float Y, float W, float H, sf::Texture& t){

   size.x = W;
   size.y = H;

    setTexture(t);

    setPosition(X, Y);

}

