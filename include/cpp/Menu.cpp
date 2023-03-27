#include "../header/menu.hpp"
#include <iostream>

Menu::Menu(float width, float height){

        font.loadFromFile("assets/fonts/bgothl.ttf");



    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("Play");
    menu[0].setPosition(sf::Vector2f(width/2 - width/20, height/(MAX_ITEMS+1)*2));

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Character Select ");
    menu[1].setPosition(sf::Vector2f(width/2 - width/10, height/(MAX_ITEMS+1)*4));

    menu[2].setFont(font);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("Quit");
    menu[2].setPosition(sf::Vector2f(width/2 - width/20, height/(MAX_ITEMS+1)*6));

    selectedItemIndex = 0;
}


void Menu::draw(sf::RenderWindow &window)
{
    for(int i=0;i < MAX_ITEMS; i++)
    {
        window.draw(menu[i]);
    }
}

void Menu::MoveUp()
{
    if(selectedItemIndex  >= 0)
    {
        menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setColor(sf::Color::Red);
    }
}
void Menu::MoveDown()
{
    if(selectedItemIndex  < MAX_ITEMS)
    {
        menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setColor(sf::Color::Red);
    }
}


