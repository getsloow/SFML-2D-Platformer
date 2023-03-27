#pragma once
#include <SFML/Graphics.hpp>

#define MAX_LEVELS 7

class Menu3
{
public:
    Menu3(float width, float height);

    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem() {return selectedItemIndex3;}
    int selectedItemIndex3;

private:
    sf::Font font;
    sf::Text menu3[MAX_LEVELS];

};

