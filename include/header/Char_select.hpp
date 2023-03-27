#pragma once
#include <SFML/Graphics.hpp>

#define MAX_COLORS 6

class Menu2
{
public:
    Menu2(float width, float height);

    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem() {return selectedItemIndex2;}

private:
    int selectedItemIndex2;
    sf::Font font;
    sf::Text menu2[MAX_COLORS];

};
