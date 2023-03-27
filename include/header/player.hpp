#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Entity.hpp"
#include "Platform.hpp"
#include <vector>
#include "Ground.hpp"
class Player : public Entity{
private:

    bool collision;
    float speed;
 //   float acceleration;
    float jumpHeight;
    int walkCounter, idleCounter, walkFrames, idleFrames, walkSpeed, idleSpeed, shootCounter, shootFrames, shootSpeed;
public:
     bool onGround;
    Player(float X, float Y, float W, float H, sf::Texture& t);
    void update(bool &A, bool &D, bool &W, bool &S,std::vector <Platform>& level, std::vector <Ground>& Ground, std::vector <Coins>& coins);
    void collide(float xVel, float yVel ,std::vector <Platform>& level);
    void collide2(float xVel, float yVel ,std::vector <Ground>& Ground);
    void collide3(float xVel, float yVel ,std::vector <Coins>& Coins);
     void lives(int &lifeNumber);

    void animate();
    void walk();
    void idle();
    void shoot();
};
