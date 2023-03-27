#include <SFML/Graphics.hpp>
#include <iostream>
#include "../header/Entity.hpp"
#include "../header/Player.hpp"
#include "../header/Platform.hpp"
#include <vector>
#include <math.h>
#include "../header/ground.hpp"
extern std::vector <Coins> coins;
extern int intCurrentScore;
extern bool isLeft;
extern bool isRight;
extern float accelGravity;
extern float maxGravity;

using namespace std;

Player::Player(float X, float Y, float W, float H, sf::Texture& t){
/*-------------------------------------------------------------------------------*/
        // ANIMATIE JUCATOR
/*-------------------------------------------------------------------------------*/
    speed = 5.f;
    jumpHeight = 6.7f;

    size.x = W;
    size.y = H;

    shootCounter = 0;
    walkCounter = 0;
    idleCounter = 0;
    shootFrames = 4;
    walkFrames = 4;
    idleFrames = 4;

    shootSpeed = 1.5;
    walkSpeed = 7;
    idleSpeed = 12;

    frameSize.x = 31;
    frameSize.y = 45;

    framesAmount.x = t.getSize().x / frameSize.x;
    framesAmount.y = t.getSize().y / frameSize.y;

    for (int y = 0; y < framesAmount.y; y++)
    {
        for(int x = 0; x < framesAmount.x; x++)
        {
            sf::IntRect frame(x * frameSize.x, y * frameSize.y, frameSize.x, frameSize.y);
            frames.push_back(frame);
        }
    }
    setTextureRect(frames[0]);
    setPosition(X, Y);
    setTexture(t);
}
/*-------------------------------------------------------------------------------*/
            // ACTUALIZARE DUPA MISCARE
/*-------------------------------------------------------------------------------*/
void Player::update(bool &A, bool &D, bool &W, bool &S, std::vector <Platform>& level, std::vector <Ground>& ground, std::vector <Coins>& coins){
    //player controls

    if(W && onGround) velocity.y = jumpHeight * -1;

    if(onGround == false){
        velocity.y += accelGravity;
        if(velocity.y > maxGravity) velocity.y = maxGravity;
    }

    if(A) {velocity.x = -1.f;
            if(isLeft == 0){
                 scale(-1.f, 1.f);
                 isLeft = 1;
                 isRight = 0;


    }
    }


    if(D){ velocity.x = 1.f;
            if(isRight == 0){
                 scale(-1.f, 1.f);
                 isLeft = 0;
                 isRight = 1;
    }
    }
  //Else if not pressed
    if(!(A || D))velocity.x =0.f;




    move(velocity.x*speed, 0);
    collide(velocity.x, 0, level);
    collide2(velocity.x, 0, ground);
    collide3(velocity.x, 0, coins);

    onGround = false;
    move(0, velocity.y);
    collide(0, velocity.y, level);
    collide2(0, velocity.y, ground);
    collide3(0, velocity.y, coins);
    animate();

}
/*-------------------------------------------------------------------------------*/
            // COLIZIUNE CU PLATFORMELE
/*-------------------------------------------------------------------------------*/

void Player::collide(float xVel, float yVel, std::vector <Platform>& level){
    for(Platform& p : level)
        {
            if(getPosition().x < p.hitbox.right &&
               getPosition().x + size.x > p.hitbox.left &&
               getPosition().y < p.hitbox.bottom &&
               getPosition().y + size.y > p.hitbox.top)
            {
                collision = true;
            }else
            {
                collision = false;
            }
            if(collision)
            {
                if(xVel > 0){
                setPosition(p.hitbox.left - size.x, getPosition().y );
                 velocity.x = 0.f;
                }
                if(xVel < 0){
               setPosition(p.hitbox.right, getPosition().y );
                  velocity.x = 0.f;
                }
                if(yVel > 0){
                 setPosition(getPosition().x, p.hitbox.top - size.y);
                 onGround = true;
                }
                if(yVel < 0){
                  setPosition(getPosition().x, p.hitbox.bottom);
                   velocity.y = 0.f;
                }




            }
    }}

    /*-------------------------------------------------------------------------------*/
                // COLIZIUNE SOL
    /*-------------------------------------------------------------------------------*/

    void Player::collide2(float xVel, float yVel, std::vector <Ground>& ground){
     for(Ground& s : ground)
        {
            if(getPosition().x < s.hitbox.right &&
               getPosition().x + size.x > s.hitbox.left &&
               getPosition().y < s.hitbox.bottom &&
               getPosition().y + size.y > s.hitbox.top)
                {
                    collision = true;
                }else
                {
                    collision = false;
                }
            if(collision)
            {
                if(xVel > 0){
                    setPosition(s.hitbox.left - size.x, getPosition().y );
                     velocity.x = 0.f;
                }
                if(xVel < 0){
                      setPosition(s.hitbox.right, getPosition().y );
                      velocity.x = 0.f;
                }
                if(yVel > 0){
                     setPosition(getPosition().x, s.hitbox.top - size.y);
                     onGround = true;
                }
                if(yVel < 0){
                      setPosition(getPosition().x, s.hitbox.bottom);
                      velocity.y = 0.f;
                }




            }
    }
}

  void Player::collide3(float xVel, float yVel, std::vector <Coins>& coins){

     for(Coins& c : coins)
        {
            if(getPosition().x < c.hitbox.right &&
               getPosition().x + size.x > c.hitbox.left &&
               getPosition().y < c.hitbox.bottom &&
               getPosition().y + size.y > c.hitbox.top)
                {
                    collision = true;

                }

            if(collision){
                  intCurrentScore += 50/6;
                  coins.erase(coins.begin());

            }

              }


}


/*-------------------------------------------------------------------------------*/
        // FUNCTIILE DE ANIMATII PE SPRITE-URI
/*-------------------------------------------------------------------------------*/

void Player::animate()
{
    if (abs(velocity.x)> 0)
        walk();
    else
        idle();
   if (Mouse::isButtonPressed(Mouse::Left)){
        shoot();

   }

}
void Player::walk(){
    for(int i =0; i < walkFrames; i++)
        if(walkCounter == (i + 1 )* walkSpeed)
            setTextureRect(frames[i]);
    if (walkCounter == walkFrames * walkSpeed)
        walkCounter = 0;
    walkCounter++;


}

void Player::idle(){
    for(int i =1; i < idleFrames; i++)
        if(idleCounter == (i + 1 )* idleSpeed)
            setTextureRect(frames[i+ idleFrames]);
    if (idleCounter == idleFrames * idleSpeed)
        idleCounter = 0;
    idleCounter++;


}
void Player::shoot(){
    for(int i=1;i< shootFrames; i++)
        if(shootCounter == (i+1)*shootSpeed)
            setTextureRect(frames[i+shootFrames+idleFrames]);
        if(shootCounter == shootFrames* shootSpeed)
            shootCounter = 0;
        shootCounter++;
    }
