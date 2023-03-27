#pragma once
#include <SFML/Graphics.hpp>

#define MAX_ITEMS 6

class Menu
{
public:
    Menu(float width, float height);

    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem() {return selectedItemIndex;}
        int selectedItemIndex;

private:

    sf::Font font;
    sf::Text menu[MAX_ITEMS];


};
