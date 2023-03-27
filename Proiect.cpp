#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <windows.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <sstream>

#include "include/header/Entity.hpp"
#include "include/header/Player.hpp"
#include "include/header/Platform.hpp"
#include "include/header/background.hpp"
#include "include/header/ground.hpp"
#include "include/header/Enemy.hpp"
#include "include/header/menu.hpp"
#include "include/header/Char_select.hpp"
#include "include/header/Level_select.hpp"
//#include "menu.hpp"
/*-------------------------------------------------------------------------------*/
int m, n;
int windowWidth =GetSystemMetrics(SM_CXSCREEN);
int windowHeight = GetSystemMetrics(SM_CYSCREEN);
int halfWinHeight = windowHeight/2;
int halfWinWidth = windowWidth/2;
int lifeNumber = 4;
int levelArray[12][80];
int menuSelection = 0;
int intCurrentScore ;
int playerColor =1;
int levelSelection = 1;
int totalProgress ;

float accelGravity = 0.3f;
float maxGravity = 6.f;

bool isLeft = false;
bool isRight = true;
bool menuOption = false;
bool bulletOut = true;
bool enemy_isHit = false;
bool enemy2_isHit = false;
bool enemy3_isHit = false;
bool enemy4_isHit = false;
bool enemy5_isHit = false;
bool hit_1 = false;
bool scored_1 = false;
bool scored_2 = false;
bool scored_3 = false;
bool scored_4 = false;
bool scored_5 = false;
bool isFinished = false;
bool isPaused = false;
bool levelIsLoaded = false;
bool isLevelDrawn = false;
bool levelSelected = false;
bool zoom = false;



using namespace std;
using namespace sf;
ifstream levelRead("stage.in");
ifstream level2Read("stage2.in");
ifstream level3Read("stage3.in");
ifstream load("puncte.out");
ofstream points("puncte.out");


/*-------------------------------------------------------------------------------*/
Vector2f playerCenter;
Vector2f mousePosWindow;
Vector2f aimDir;
Vector2f aimDirNorm;
Vector2f noSpeed;

/*-------------------------------------------------------------------------------*/
                        /* GLOANTE */
/*-------------------------------------------------------------------------------*/
class Bullet
{
public:
    CircleShape shape;
    Vector2f currVelocity;
    float maxSpeed;

    Bullet(float radius = 2.f)
    : currVelocity(0.f, 0.f), maxSpeed(10.f)
    {
        this->shape.setFillColor(Color::Black);
        this->shape.setRadius(radius);

    }
};
/*-------------------------------------------------------------------------------*/

int main()
{
cout<<totalProgress<<" "<<intCurrentScore<<endl<<endl;

while(!load.eof()){
    load>>totalProgress;
    load>>intCurrentScore;
}

cout<<totalProgress<<" "<<intCurrentScore<<endl<<endl;


    /*-------------------------------------------------------------------------------*/
                    // FEREASTRA
    /*-------------------------------------------------------------------------------*/
    RenderWindow window(VideoMode(windowWidth, windowHeight), "MaRio");
    window.setFramerateLimit(60);
    Music menuMusic;
    Music gameMusic;
    Music walk;
    SoundBuffer glont;
    Sound shoot;

    menuMusic.openFromFile("assets/sounds/mainMenu.wav");
    gameMusic.openFromFile("assets/sounds/gameMusic.wav");
    walk.openFromFile("assets/sounds/walk.wav");
    glont.loadFromFile("assets/sounds/shoot.wav");

    shoot.setBuffer(glont);

    if(menuSelection == 0 || menuSelection == 2)

        walk.play();
        menuMusic.play();
        menuMusic.setVolume(40);
        gameMusic.play();
        gameMusic.setLoop(true);
        gameMusic.setVolume(0);
        walk.setLoop(true);
        walk.setVolume(0);




   Menu menu(window.getSize().x, window.getSize().y);
   Menu2 menu2(window.getSize().x, window.getSize().y);
   Menu3 menu3(window.getSize().x, window.getSize().y);


/*-------------------------------------------------------------------------------*/
    vector <Platform> level;
    vector <Ground> ground;
    vector <Ground2> ground2;
    vector <EndLevel> endLevel;
    vector <Coins> coins;




/*-------------------------------------------------------------------------------*/
                // TEXTURI
/*-------------------------------------------------------------------------------*/
    Texture groundTex;
    Texture groundTex_2;
    Texture backgroundTex;
    Texture backgroundTex2;
    Texture gameEndTex;
    Texture platformsTex;
    Texture enemyTex;
    Texture enemyTex2;
    Texture playerTex;
    Texture lifeTex;
    Texture coinsTex;
    Texture imageTurq;
    Texture imagePurp;
    Texture imageYellow;
    Texture imageRed;
    Texture imageGreen;
    Texture menuBg;

    Font MyFont;
    MyFont.loadFromFile("assets/fonts/bgothl.ttf");

    imageTurq.loadFromFile("assets/images/turq.png");
    imagePurp.loadFromFile("assets/images/purp.png");
    imageYellow.loadFromFile("assets/images/yellow.png");
    imageRed.loadFromFile("assets/images/red.png");
    imageGreen.loadFromFile("assets/images/green.png");
    menuBg.loadFromFile("assets/images/menu_background.png");

    groundTex.loadFromFile("assets/images/brickblock.png");
    groundTex_2.loadFromFile("assets/images/ground_22.png");
    enemyTex.loadFromFile("assets/images/enemy_idle.png");
    enemyTex2.loadFromFile("assets/images/enemy_idle.png");
    playerTex.loadFromFile("assets/images/player_purple.png");
    platformsTex.loadFromFile("assets/images/floor.png");
    gameEndTex.loadFromFile("assets/images/finish.png");
    lifeTex.loadFromFile("assets/images/life.png");
    backgroundTex.loadFromFile("assets/images/background_final.png");
    coinsTex.loadFromFile("assets/images/coin.png");


   Text text("Navigate the menu using the UP and DOWN keys", MyFont, 50);
   Text text2("then make your selection by pressing the ENTER key.", MyFont, 50);
   Text textTurq("You have chosen the turquoise character", MyFont, 50);
   Text textPurp("You have chosen the purple character", MyFont, 50);
   Text textYellow("You have chosen the yellow character", MyFont, 50);
   Text textRed("You have chosen the red character", MyFont, 50);
   Text textGreen("You have chosen the green character", MyFont, 50);

   text.setColor(Color::Cyan);
   text.scale(0.5f, 0.5f);
   text2.setColor(Color::Cyan);
   text2.scale(0.5f, 0.5f);
   textPurp.scale(0.5f, 0.5f);
   textPurp.setColor(Color::Magenta);
   textTurq.scale(0.5f, 0.5f);
   textTurq.setColor(Color::Cyan);
   textYellow.setColor(Color::Yellow);
   textYellow.scale(0.5f, 0.5f);
   textRed.setColor(Color::Red);
   textRed.scale(0.5f, 0.5f);
   textGreen.setColor(Color::Green);
   textGreen.scale(0.5f, 0.5f);



    Sprite spriteLife;
    Sprite spriteLife2;
    Sprite spriteLife3;
    Sprite spriteBackground;
    Sprite spriteBackground2;
    Sprite spriteBackground3;
    Sprite spriteBackground4;
    Sprite spriteTurq;
    Sprite spritePurple;
    Sprite spriteRed;
    Sprite spriteYellow;
    Sprite spriteGreen;
    Sprite menuSprite;

    spriteTurq.setTexture(imageTurq);
    spritePurple.setTexture(imagePurp);
    spriteGreen.setTexture(imageGreen);
    spriteRed.setTexture(imageRed);
    spriteYellow.setTexture(imageYellow);
    spriteLife.setTexture(lifeTex);
    spriteLife2.setTexture(lifeTex);
    spriteLife3.setTexture(lifeTex);
    menuSprite.setTexture(menuBg);

    spriteBackground.setTexture(backgroundTex);
    spriteBackground2.setTexture(backgroundTex);
    spriteBackground3.setTexture(backgroundTex);
    spriteBackground4.setTexture(backgroundTex);


    spriteBackground.scale(0.3f, 0.3f);
    spriteBackground2.scale(0.3f, 0.3f);
    spriteBackground3.scale(0.3f, 0.3f);
    spriteBackground4.scale(0.3f, 0.3f);
    spriteLife.scale(0.5f, 0.5f);
    spriteLife2.scale(0.5f, 0.5f);
    spriteLife3.scale(0.5f, 0.5f);
    menuSprite.scale(windowWidth/192, windowHeight/108);

/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
                            // NIVELUL
/*-------------------------------------------------------------------------------*/




        menuMusic.setLoop(true);

 /*--------------------------------------------------------------------------------------------------------------------*/
    Bullet b1;

    std::vector<Bullet> bullets;
    bullets.push_back(Bullet(b1));

/*-------------------------------------------------------------------------------*/
                // STABILIRE COORDONATE JUCATOR / INAMICI / FUNDAL
/*-------------------------------------------------------------------------------*/
    Enemy enemy(670, 445, 31, 45, enemyTex);
    Enemy enemy_2(1229, 195, 31, 45, enemyTex2);
    Enemy enemy_3(1444, 75, 31, 45, enemyTex);
    Enemy enemy_4(2215, 555, 31, 45, enemyTex);
    Enemy enemy_5(2540, 555, 31, 45, enemyTex2);
    Enemy enemy_6(5600, 555, 31, 45, enemyTex);
    Player player(260, 550, 31, 45, playerTex);
    spriteBackground4.move(player.getPosition().x + 0.3f*13060, player.getPosition().y -250.f - 0.3f*1080);
    spriteBackground3.move(player.getPosition().x + 0.3f*13060, player.getPosition().y -250.f);
    spriteBackground2.move(player.getPosition().x - 600.f, player.getPosition().y -250.f - 0.3f*1080);
    spriteBackground.move(player.getPosition().x- 600.f, player.getPosition().y-250.f);

    View view(Vector2f(0.0f, 0.0f), Vector2f(windowWidth,windowHeight));


    float gameScale = 4;
   // view.zoom(1.0f/gameScale);

    float mouseX, mouseY;
	// Start the game loop
	/*-------------------------------------------------------------------------------*/
	/*-------------------------------------------------------------------------------*/
	/*-------------------------------------------------------------------------------*/
   while (window.isOpen())
    {
        // Process events
    Event event;
    while (window.pollEvent(event))
    {


        switch (event.type)
        {
    case Event::KeyReleased:
        switch(event.key.code)
        {
        case Keyboard::Up:{
                menu.MoveUp();
                menu2.MoveUp();
                menu3.MoveUp();

                      break;}



        case Keyboard::Down:{
                menu.MoveDown();
                 menu2.MoveDown();
                 menu3.MoveDown();
                  break;}


            break;

        case Keyboard::Return:
                switch(menu.GetPressedItem())
                {
                case 0:
                     if(menuSelection == 0){
                    cout<<"Play button pressed"<<endl<<endl;
                    menuSelection = 3;
                    menu3.selectedItemIndex3 = 0;
                    break;}
                        if(menuSelection == 2)
                    {
                    cout<<"PURPLE"<<endl;

                    playerColor = 1;
                    window.draw(textPurp);
                    break;
                    }
                        if(menuSelection == 3)
                        {
                    cout<<"Play button pressed"<<endl<<endl;
                    levelSelection = 1;
                    levelSelected = true;
                    menuSelection = 1;
                    view.zoom(1.0f/gameScale);


                    break;}



                 case 1:
                     if(menuSelection == 0){
                    cout<<"Settings button pressed"<<endl<<endl;
                    menuSelection = 2;
                    break;}
                             if(menuSelection == 2)
                    {
                        cout<<"TURQUOISE"<<endl;
                        playerColor = 2;
                        break;
                    }

                    if(menuSelection == 3)
                        {
                            if(totalProgress > 1){
                                levelSelection = 2;
                                levelSelected = true;
                                view.zoom(1.0f/gameScale);
                                menuSelection = 1;
                            }
                            else
                                cout<<"Nu sunt suficiente nivele completate"<<endl<<endl;
                            break;

                        }
                 case 2:
                       if(menuSelection == 0){
                    cout<<"Quit button pressed"<<endl<<endl;
                    window.close();

                    break;}
                        if(menuSelection == 2)
                        {
                            cout<<"YELLOW"<<endl;
                            playerColor = 3;
                            break;
                        }

                     if(menuSelection == 3)
                        {
                            if(totalProgress > 2){
                                levelSelection = 3;
                                view.zoom(1.0f/gameScale);
                            cout<<"Nivel selectat: 3"<<endl<<endl;
                                menuSelection = 1;

                            }
                            else
                                cout<<"Nu sunt suficiente nivele completate"<<endl<<endl;
                            break;

                        }
                 case 3:
                    if(menuSelection == 2)
                    {
                        cout<<"RED"<<endl;
                        playerColor = 4;
                        break;
                    }


                 case 4:
                    if(menuSelection == 2)
                    {
                        cout<<"GREEN"<<endl;
                        playerColor = 5;
                        break;
                    }
                 case 5:
                    if(menuSelection ==2)
                    {
                        cout<<"Back button pressed"<<endl<<endl;
                        menuSelection = 0;
                        menu.selectedItemIndex = 1;
                        window.clear(Color(0,0,0));
                    }
                 case 6:
                     if(menuSelection ==3)
                    {
                        cout<<"Back button pressed"<<endl<<endl;
                        menuSelection = 0;
                        menu.selectedItemIndex = 0;
                        menu.MoveDown();
                        window.clear(Color(0,0,0));
                    }

                    }

                }

                break;


            break;

                case Event::Closed:
                window.close();

                break;
        }
        }

    if(levelIsLoaded == false)
        if(levelSelected == true){
        if(levelSelection == 1){
      for (int i=0;i< 12; i++)
        for(int j=0;j<80;j++){
            levelRead>>levelArray[i][j];

        }
        }
         if(levelSelection == 2){
      for (int i=0;i< 12; i++)
        for(int j=0;j<80;j++){
            level2Read>>levelArray[i][j];

        }
        }
         if(levelSelection == 3){
      for (int i=0;i< 12; i++)
        for(int j=0;j<80;j++){
            level3Read>>levelArray[i][j];

        }
        }

    for(int i = 0; i< 12; i++){
        for(int j= 0; j<80;j++){
            if(levelArray[i][j] == 1){
                Platform p(j * 60, i * 60, 60, 60, platformsTex);
                level.push_back(p);
            }
        }
    }

     for(int m = 0; m< 12; m++){
            for(int n= 0; n<80;n++){
                if(levelArray[m][n] == 2){
                    Ground g(n * 60, m * 60, 60, 60, groundTex);
                    ground.push_back(g);
            }
        }
    }

    for(int m = 0; m< 12; m++){
            for(int n= 0; n<80;n++){
                if(levelArray[m][n] == 3){
                    Ground2 g2(n * 60, m * 60, 60, 60, groundTex_2);
                    ground2.push_back(g2);
            }
        }
    }

    for(int m = 0; m< 12; m++){
            for(int n= 0; n<80;n++){
                if(levelArray[m][n] == 4){
                    EndLevel e(n * 60, m * 60, 60, 60, gameEndTex);
                    endLevel.push_back(e);
            }
        }
    }


    for(int i = 0; i< 12; i++){
        for(int j= 0; j<80;j++){
            if(levelArray[i][j] == 5){
                Coins c(j * 60, i * 60, 60, 60, coinsTex);
                coins.push_back(c);
            }
        }
    }
    levelIsLoaded = true;


    }


            if(menuSelection == 1){
                menuMusic.stop();
                gameMusic.setVolume(60);

            }

/*-------------------------------------------------------------------------------*/
            //CONTROALE
/*-------------------------------------------------------------------------------*/
    Text score("Score: ", MyFont, 30);
    string currScore;
  stringstream ss;
  ss << intCurrentScore;
  ss >> currScore;
   Text currentScore(currScore, MyFont, 30);
   score.setColor(Color::White);
   currentScore.setColor(Color::White);
   currentScore.scale(0.5f, 0.5f);
   score.scale(0.5f, 0.5f);


    bool W, A, S, D, ENTER;

    A = Keyboard::isKeyPressed(Keyboard::A);
    D = Keyboard::isKeyPressed(Keyboard::D);
    W = Keyboard::isKeyPressed(Keyboard::W);
    S = Keyboard::isKeyPressed(Keyboard::S);
    ENTER = Keyboard::isKeyPressed(Keyboard::Enter);

    if(Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::A))
        if(player.getPosition().y < 560)
        walk.setVolume(100);
    if(!(Keyboard::isKeyPressed(Keyboard::D)) && !(Keyboard::isKeyPressed(Keyboard::A)))
        walk.setVolume(0);

/*-------------------------------------------------------------------------------*/
    //Shoot
    if (Mouse::isButtonPressed(Mouse::Left))
    {
          if(bulletOut == false){
                    b1.shape.setPosition(playerCenter.x, playerCenter.y + 25);
                    b1.currVelocity = aimDir * b1.maxSpeed / 100.f;
                    bullets.push_back(Bullet(b1));
                    shoot.play();
                    bulletOut = true;}

    }
    if (!(Mouse::isButtonPressed(Mouse::Left)))
            bulletOut = false;

    for(size_t i = 0; i<bullets.size(); i++)
    {
        bullets[i].shape.move(bullets[i].currVelocity);
    }
/*-------------------------------------------------------------------------------*/
                     //  VIETI
/*-------------------------------------------------------------------------------*/
    spriteLife.setPosition(player.getPosition().x- windowWidth/8.72f, player.getPosition().y-windowHeight/10.8f); //
    spriteLife2.setPosition(player.getPosition().x- windowWidth/10.10f, player.getPosition().y-windowHeight/10.8f);
    spriteLife3.setPosition(player.getPosition().x- windowWidth/12.f, player.getPosition().y -windowHeight/10.8f);


    spritePurple.setPosition(windowWidth/3, windowHeight/9 );
    spriteTurq.setPosition(windowWidth/3, windowHeight/4 );
    spriteRed.setPosition(windowWidth/3, windowHeight/1.8 );
    spriteYellow.setPosition(windowWidth/3, windowHeight/2.5 );
    spriteGreen.setPosition(windowWidth/3, windowHeight/1.4 );


    spritePurple.setScale(2.f, 2.f);
    spriteRed.setScale(2.f, 2.f);
    spriteYellow.setScale(2.f, 2.f);
    spriteGreen.setScale(2.f, 2.f);
    spriteTurq.setScale(2.f, 2.f);
    Vector2i mousePos = Mouse::getPosition(window);

    mouseX = (player.getPosition().x + player.size.x /2) + mousePos.x / gameScale - halfWinWidth / gameScale;
    mouseY = (player.getPosition().y + player.size.y /2) + mousePos.y / gameScale - halfWinHeight / gameScale;

    player.update( A, D, W, S, level, ground, coins);
    enemy.update(A, D, W, S, level, ground);
    enemy_2.update(A, D, W, S, level, ground);
    enemy_3.update(A, D, W, S, level, ground);
    enemy_4.update(A, D, W, S, level, ground);
    enemy_5.update(A, D, W, S, level, ground);
    enemy_6.update(A, D, W, S, level, ground);

    /*-------------------------------------------------------------------------------*/
                        // TINTA //
    /*-------------------------------------------------------------------------------*/
    playerCenter= Vector2f(player.getPosition().x + player.size.x /2 , player.getPosition().y + + player.size.y/ 5.0 );
    mousePosWindow = Vector2f(mouseX, mouseY- player.size.y/2);
    aimDir =mousePosWindow - playerCenter;


/*-------------------------------------------------------------------------------*/
            // FINAL DE NIVEL
/*-------------------------------------------------------------------------------*/




    if(playerCenter.x > 4460)
    {  if( isFinished == 0 ){
        intCurrentScore += lifeNumber*200;
        MessageBoxA(NULL, "Congratulations, you won!", "We have a winner", MB_OK);
        totalProgress ++;
         isFinished = 1;
            window.clear();
                window.draw(menuSprite);
                player.setPosition(240, 550);
                view.zoom(gameScale/1.0f);

        Menu menu(window.getSize().x, window.getSize().y);

                window.draw(text);
                window.draw(text2);
                menu.draw(window);


     window.display();


    }


    }
    /*-------------------------------------------------------------------------------*/
                    // CAZI PRIN HARTA !
    /*-------------------------------------------------------------------------------*/
 if(isLevelDrawn == true && menuSelection == 1 )
    if (playerCenter.y > 600.f)
    {
        if(lifeNumber == 1)
        {
            MessageBoxA(NULL, "You lost all your lives, game over !", "GG !", MB_OK| MB_OK);
            return EXIT_SUCCESS;
         }
         else
             {
                lifeNumber--;
                player.setPosition(240, 550);
                enemy_isHit = false;
                enemy2_isHit = false;
                enemy3_isHit = false;
                enemy4_isHit = false;
                enemy5_isHit = false;
             }
    }

    /*-------------------------------------------------------------------------------*/
                            // CAMERA URMARESTE JUCATORUL
    /*-------------------------------------------------------------------------------*/

    text2.setPosition(0, 20);
    currentScore.setPosition(player.getPosition().x- 160.f, player.getPosition().y-80.f);
    score.setPosition(player.getPosition().x- 220.f, player.getPosition().y-80.f);


            /*-------------------------------------------------------------------------------*/
                        //   DESENAREA PE ECRAN

            /*-------------------------------------------------------------------------------*/

    if(menuSelection == 0){

    window.clear(Color(0, 0, 0));
    window.draw(menuSprite);
    window.draw(text);
    window.draw(text2);
    menu.draw(window);
     window.display();
    }
    else
    if(menuSelection == 3){

        window.clear(Color(0, 0, 0));
        menu3.draw(window);
        window.display();
    }

    else
        if(menuSelection == 2)
    {
        window.clear(Color(0, 0, 0));

        menu2.draw(window);
        window.draw(menuSprite);
        window.draw(spriteTurq);
        window.draw(spritePurple);
        window.draw(spriteRed);
        window.draw(spriteGreen);
        window.draw(spriteYellow);
        if(playerColor == 1)
             window.draw(textPurp);
        if(playerColor == 2)
             window.draw(textTurq);
        if(playerColor == 3)
             window.draw(textYellow);
        if(playerColor == 4)
            window.draw(textRed);
        if(playerColor == 5)
            window.draw(textGreen);

        window.display();

    }

    else
    if (menuSelection == 1){


    window.clear(Color(0,0,0));
    view.setCenter(player.getPosition().x + player.size.x /2, player.getPosition().y + player.size.y /2);
    window.setView(view);

    if(playerColor == 1)
    playerTex.loadFromFile("assets/images/player_purple.png");
    else
        if(playerColor ==2)
    playerTex.loadFromFile("assets/images/player_turq.png");
          if(playerColor ==3)
    playerTex.loadFromFile("assets/images/player_yellow.png");
          if(playerColor ==4)
    playerTex.loadFromFile("assets/images/player_red.png");
          if(playerColor ==5)
    playerTex.loadFromFile("assets/images/player_green.png");
    window.draw(spriteBackground);
    window.draw(spriteBackground2);
    window.draw(spriteBackground3);
    window.draw(spriteBackground4);
    window.draw(player);
    window.draw(currentScore);
    window.draw(score);

    if(enemy_isHit == false){
        enemy.setTexture(enemyTex);
        window.draw(enemy);
       if (player.getGlobalBounds().intersects(enemy.getGlobalBounds()))
            {
                enemy_isHit = true;
                lifeNumber--;
            }
        }
    if(enemy2_isHit == false){

        enemy_2.setTexture(enemyTex);
        window.draw(enemy_2);
          if (player.getGlobalBounds().intersects(enemy_2.getGlobalBounds()))
            {
                enemy2_isHit = true;
                lifeNumber--;
            }
        }
    if(enemy3_isHit == false){
            enemy_3.setTexture(enemyTex);
        window.draw(enemy_3);
          if (player.getGlobalBounds().intersects(enemy_3.getGlobalBounds()))
            {
                enemy3_isHit = true;
                lifeNumber--;
            }
        }
    if(enemy4_isHit == false)
        {
         window.draw(enemy_4);
          if (player.getGlobalBounds().intersects(enemy_4.getGlobalBounds()))
            {
                enemy4_isHit = true;
                lifeNumber--;
            }

        }



    for(EndLevel& e: endLevel)
        window.draw(e);

    for(Ground& g : ground) {
        window.draw(g);
        }

    for(Ground2& g2 : ground2) {
        window.draw(g2);
        }

    for(size_t i= 0 ;i< bullets.size(); i++){
        window.draw(bullets[i].shape);
        }
        for(Platform& p : level){
            window.draw(p);


        }
    for(Coins& c : coins){
        window.draw(c);
    }

    isLevelDrawn = true;

    if(lifeNumber== 3){
        window.draw(spriteLife);
        window.draw(spriteLife2);
        window.draw(spriteLife3);
        }
    else
        if(lifeNumber == 2){
        window.draw(spriteLife);
        window.draw(spriteLife2);
        }
    else
        window.draw(spriteLife);

    /*-------------------------------------------------------------------------------*/
                            // TRAS IN INAMICI
    /*-------------------------------------------------------------------------------*/
 for(size_t i= 0 ;i< bullets.size(); i++){
    if (bullets[i].shape.getGlobalBounds().intersects(enemy.getGlobalBounds()))
    {   if (scored_1 == false)
    {
        scored_1 = true;
        intCurrentScore += 10 ;
        }
         enemy_isHit = true;
    }
    if (bullets[i].shape.getGlobalBounds().intersects(enemy_2.getGlobalBounds()))
    {
          if (scored_2 == false)
    {
        scored_2 = true;
        intCurrentScore += 10 ;
        }
    enemy2_isHit = true;

    }
    if (bullets[i].shape.getGlobalBounds().intersects(enemy_3.getGlobalBounds()))
    {
          if (scored_3 == false)
    {
        scored_3 = true;
        intCurrentScore += 10 ;
        }
    enemy3_isHit = true;

    }
    if (bullets[i].shape.getGlobalBounds().intersects(enemy_4.getGlobalBounds()))
    {
          if (scored_4 == false)
    {
        scored_4 = true;
        intCurrentScore += 10 ;
        }

    enemy4_isHit = true;


    }
     if (bullets[i].shape.getGlobalBounds().intersects(enemy_5.getGlobalBounds()))
    {
          if (scored_5 == false)
    {
        scored_5 = true;
        intCurrentScore += 10 ;
        }
    enemy5_isHit = true;
    }
}
/*-------------------------------------------------------------------------------*/
            // FINAL DE JOC
/*-------------------------------------------------------------------------------*/

 if(lifeNumber < 1)
        {
            MessageBoxA(NULL, "You lost all your lives, game over !", "GG !", MB_OK| MB_OK);
            return EXIT_SUCCESS;
         }


 window.draw(currentScore);
 window.draw(score);
 if(isFinished == 1)
 {
    points<<totalProgress<<" "<<intCurrentScore<<endl;
    isFinished =0;
    menuSelection = 0;}

    window.display();
    }}
    return EXIT_SUCCESS;
}
