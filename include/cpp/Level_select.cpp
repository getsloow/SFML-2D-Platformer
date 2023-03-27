#include "../header/Level_select.hpp"
#include <iostream>

Menu3::Menu3(float width, float height){

        font.loadFromFile("assets/fonts/bgothl.ttf");



    menu3[0].setFont(font);
    menu3[0].setColor(sf::Color::Red);
    menu3[0].setString("Stage 1");
    menu3[0].setPosition(sf::Vector2f(width/2 - width/15, height/(MAX_LEVELS+1)*1));


    menu3[1].setFont(font);
    menu3[1].setColor(sf::Color::White);
    menu3[1].setString("Stage 2");
    menu3[1].setPosition(sf::Vector2f(width/2 - width/15, height/(MAX_LEVELS+1)*2));

    menu3[2].setFont(font);
    menu3[2].setColor(sf::Color::White);
    menu3[2].setString("Stage 3");
    menu3[2].setPosition(sf::Vector2f(width/2 - width/15, height/(MAX_LEVELS+1)*3));


    menu3[3].setFont(font);
    menu3[3].setColor(sf::Color::White);
    menu3[3].setString("Stage 4");
    menu3[3].setPosition(sf::Vector2f(width/2 - width/15, height/(MAX_LEVELS+1)*4));

    menu3[4].setFont(font);
    menu3[4].setColor(sf::Color::White);
    menu3[4].setString("Stage 5");
    menu3[4].setPosition(sf::Vector2f(width/2 - width/15, height/(MAX_LEVELS+1)*5));

    menu3[5].setFont(font);
    menu3[5].setColor(sf::Color::White);
    menu3[5].setString("Stage 6");
    menu3[5].setPosition(sf::Vector2f(width/2 - width/15, height/(MAX_LEVELS+1)*6));

    menu3[6].setFont(font);
    menu3[6].setColor(sf::Color::White);
    menu3[6].setString("Back to main menu");
    menu3[6].setPosition(sf::Vector2f(width/2 - width/15, height/(MAX_LEVELS+1)*7));


    selectedItemIndex3 = 0;
}


void Menu3::draw(sf::RenderWindow &window)
{
    for(int i=0;i < MAX_LEVELS; i++)
    {
        window.draw(menu3[i]);
    }
}

void Menu3::MoveUp()
{
    if(selectedItemIndex3  >= 0)
    {
        menu3[selectedItemIndex3].setColor(sf::Color::White);
        selectedItemIndex3--;
        menu3[selectedItemIndex3].setColor(sf::Color::Red);
    }
}
void Menu3::MoveDown()
{
    if(selectedItemIndex3  < MAX_LEVELS)
    {
        menu3[selectedItemIndex3].setColor(sf::Color::White);
        selectedItemIndex3++;
        menu3[selectedItemIndex3].setColor(sf::Color::Red);
    }
}


