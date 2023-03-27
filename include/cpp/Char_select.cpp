#include "../header/Char_select.hpp"
#include <iostream>

Menu2::Menu2(float width, float height){

        font.loadFromFile("assets/fonts/bgothl.ttf");



    menu2[0].setFont(font);
    menu2[0].setColor(sf::Color::White);
    menu2[0].setString("Purple");
    menu2[0].setPosition(sf::Vector2f(width/2 - width/15, height/(MAX_COLORS+1)*1));

    menu2[1].setFont(font);
    menu2[1].setColor(sf::Color::White);
    menu2[1].setString("Turquoise");
    menu2[1].setPosition(sf::Vector2f(width/2 - width/15, height/(MAX_COLORS+1)*2));

    menu2[2].setFont(font);
    menu2[2].setColor(sf::Color::White);
    menu2[2].setString("Yellow");
    menu2[2].setPosition(sf::Vector2f(width/2 - width/15, height/(MAX_COLORS+1)*3));

    menu2[3].setFont(font);
    menu2[3].setColor(sf::Color::White);
    menu2[3].setString("Red");
    menu2[3].setPosition(sf::Vector2f(width/2 - width/15, height/(MAX_COLORS+1)*4));

    menu2[4].setFont(font);
    menu2[4].setColor(sf::Color::White);
    menu2[4].setString("Green");
    menu2[4].setPosition(sf::Vector2f(width/2 - width/15, height/(MAX_COLORS+1)*5));

    menu2[5].setFont(font);
    menu2[5].setColor(sf::Color::White);
    menu2[5].setString("Back to main menu");
    menu2[5].setPosition(sf::Vector2f(width/2 - width/15, height/(MAX_COLORS+1)*6));


    selectedItemIndex2 = 0;
}


void Menu2::draw(sf::RenderWindow &window)
{
    for(int i=0;i < MAX_COLORS; i++)
    {
        window.draw(menu2[i]);
    }
}

void Menu2::MoveUp()
{
    if(selectedItemIndex2  >= 0)
    {
        menu2[selectedItemIndex2].setColor(sf::Color::White);
        selectedItemIndex2--;
        menu2[selectedItemIndex2].setColor(sf::Color::Red);
    }
}
void Menu2::MoveDown()
{
    if(selectedItemIndex2  < MAX_COLORS)
    {
        menu2[selectedItemIndex2].setColor(sf::Color::White);
        selectedItemIndex2++;
        menu2[selectedItemIndex2].setColor(sf::Color::Red);
    }
}


