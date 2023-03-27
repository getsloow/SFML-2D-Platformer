#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Entity.hpp"
#include "Platform.hpp"
#include <vector>
#include "Ground.hpp"
class Enemy : public Entity{
private:
    bool onGround;
    bool collision;
    float speed;
 //   float acceleration;
    float jumpHeight;
    int walkCounter, idleCounter, walkFrames, idleFrames, walkSpeed, idleSpeed, shootCounter, shootFrames, shootSpeed;
public:
    Enemy (float X, float Y, float W, float H, sf::Texture& t);
    void update(bool &A, bool &D, bool &W, bool &S,std::vector <Platform>& level, std::vector <Ground>& Ground);
    void collide(float xVel, float yVel ,std::vector <Platform>& level);
    void collide2(float xVel, float yVel ,std::vector <Ground>& Ground);

    void animate();
    void walk();
    void idle();
    void shoot();
};
