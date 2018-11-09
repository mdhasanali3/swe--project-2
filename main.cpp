#include<bits/stdc++.h>
#include<SFML/Graphics.hpp>
#include<math.h>
#include<stdlib.h>
#include<cstdlib>

using namespace std;
using namespace sf;
///       variable   ///////////
int score=0;
  double backy1=1;
                double backy2=2249;

        double backy3=4496;
                double backy4=8436;


                ///   function ///////////////////


class enemy
{

public:
  RectangleShape enem;
Vector2f curr;
    float ma;
    enemy(Texture* tex)
       //:curr(0.f,0.f),ma(5.f)
        {
//    this->enem.setTexture(&tex);
   this-> enem.setScale(1.f,1.f);
    //this->enem.setOrigin(enem.getPosition().x+700,enem.getPosition().y+400);
//    this-> enem.setPosition(rand()%window.getSize().x,rand()%window.getSize().y);

    }

};
class bullet
{
public:
    CircleShape shape;
    Vector2f currentvelocity;
    float maxspeed;

    bullet(float radius=5.f)
        :currentvelocity(0.f,0.f),maxspeed(15.f)
    {
        this->shape.setRadius(radius);
        this->shape.setFillColor(Color::Red);
    }
};
main()
{
    srand(time(0));

    enum dir{Left,Right};
    int sourcex=138,sourcey=Right;
    Vector2i source(1,Right);


    RenderWindow window(VideoMode(1400,800),"game");
    window.setFramerateLimit(60);

    Texture texture;
    texture.loadFromFile("soldierSeatDownShoot.png");
    Sprite circle;
    circle.setTexture(texture);
    circle.setScale(.7f,.7f);
    circle.setOrigin(circle.getPosition().x+100,circle.getPosition().y+50);
    circle.setPosition(200.f,500.f);
        Texture background1,background2;

        background1.loadFromFile("7f7c4ef4b62f622f944831f1be6eab7e.png");
        background2.loadFromFile("bg 2.png");


        Sprite back1(background1),back2(background1),back3(background2),back4(background2);

        double backy1=1;
                double backy2=2249;

        double backy3=4496;
                double backy4=8436;

    Font font;
    font.loadFromFile("AGENTORANGE.TTF");
    Text text;
    text.setFont(font);
    text.setCharacterSize(22);
    text.setFillColor(Color::Red);
    text.setPosition(10.f,30.f);


///     bullet    //////////
    bullet b1;
    vector<bullet>bullets;



///    enemy     /////
  // enemy *e1;
    Texture tex;
    tex.loadFromFile("cheetah_PNG14852.png");

        RectangleShape enemy;
    vector<RectangleShape>enemies;
    int enemycount=20;
    enemy.setFillColor(Color::Green);
    enemy.setSize(Vector2f(150.f,75.f));
  // enemy.setOrigin(enemy.getSize().x/2,enemy.getSize().y/2);

enemy.setTexture(&tex);

///   vectors      //////
    Vector2f playercenter;
    Vector2f mouseposwindow;
    Vector2f aimdir;
    Vector2f aimdirnorm;
    Vector2f enemyloc;
    Vector2f ai;
    Vector2f ain;


    float c,v,m,p,q,r,x,y;
 //int p,q,r;
    while(window.isOpen())
    {

        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type==Event::Closed)
                window.close();

            if(Keyboard::isKeyPressed(Keyboard::Escape))
                window.close();
        }
        Vector2i pos,curr;
        pos=Vector2i(circle.getPosition());

        ///    update   ////////////
        playercenter=Vector2f(circle.getPosition().x,circle.getPosition().y);

        mouseposwindow=Vector2f(Mouse::getPosition(window));
        aimdir=mouseposwindow-playercenter;
        c=aimdir.x*aimdir.x;
        v=aimdir.y*aimdir.y;
        m=c+v;
        aimdirnorm=aimdir/sqrt(m);

///   background         //////////////////////////////////////////

   back1.setPosition(backy1,0);
        back2.setPosition(backy2,0);
  back3.setPosition(backy3,0);
        back4.setPosition(backy4,0);


  ///    player update  ////////

        if(Keyboard::isKeyPressed(Keyboard::Up))
            {circle.move(0,-10.f);
            source.y=Right;

            }
        if(Keyboard::isKeyPressed(Keyboard::Down))
            {circle.move(0,10.f);
 source.y=Right;

            }
        if(Keyboard::isKeyPressed(Keyboard::Right))
            {circle.move(1.f,0);
 source.y=Right;
 //back_change_right();
  backy1-=3;
     backy2-=3;
 backy3-=3;
     backy4-=3;

            }
        if(Keyboard::isKeyPressed(Keyboard::Left))
           {circle.move(-1.f,0);
 //back_change_left();
    backy1+=3;
       backy2+=3;
        backy3+=3;
       backy4+=3;




            }
        ///    update enemies    //////
        if(enemycount<20)
            enemycount++;

        if(enemycount>=20)
        {
           enemy.setPosition(rand()%window.getSize().x,rand()%window.getSize().y);
              enemies.push_back(RectangleShape(enemy));
            enemycount=0;
        }

        ///  shooting      //////
        if(Mouse::isButtonPressed(Mouse::Left)||Keyboard::isKeyPressed(Keyboard::Space))
        {
            b1.shape.setPosition(playercenter);
            b1.currentvelocity=aimdirnorm*b1.maxspeed;

            bullets.push_back(bullet(b1));
        }

        for(size_t i=0; i<bullets.size(); i++)
        {
            bullets[i].shape.move(bullets[i].currentvelocity);
/// out of bounds   ///////
            if(bullets[i].shape.getPosition().x<0||bullets[i].shape.getPosition().x>window.getSize().x
                    ||bullets[i].shape.getPosition().y<0||bullets[i].shape.getPosition().y>window.getSize().y)
             {
                 bullets.erase(bullets.begin()+i);
     //  break;
             }

    ///    collision    ////
   for(size_t k=0;k<enemies.size();k++)
    {if(bullets[i].shape.getGlobalBounds().intersects(enemies[k].getGlobalBounds()))
{enemies.erase(enemies.begin()+k);
bullets.erase(bullets.begin()+i);
score+=3;
break;
}
    }
        }

        for(size_t i=0;i<enemies.size();i++)
{

  //    enemies[i].enem.move();

            if(enemies[i].getPosition().x<0||enemies[i].getPosition().x>window.getSize().x
                    ||enemies[i].getPosition().y<0||enemies[i].getPosition().y>window.getSize().y)
             {
                 enemies.erase(enemies.begin()+i);
     //  break;
             }

}
        char a[100],b[100];
        sprintf(a," your position x=%d   y=%d \n \n \t score :  %d ",pos.x,pos.y,score);
        text.setString(a);

  ///    draw     ////////////

circle.setTextureRect(IntRect(source.x*1,source.y*1,130,155));

if(circle.getPosition().x>1200||circle.getPosition().x<200)
    circle.setPosition(Vector2f(400.f,500.f));

window.draw(back1);
window.draw(back2);
window.draw(back3);
window.draw(back4);

        window.draw(text);
        for(size_t i=0; i<enemies.size(); i++)
        {
            window.draw(enemies[i]);

            }

window.draw(circle);
        for(size_t i=0; i<bullets.size(); i++)
        {
            window.draw(bullets[i].shape);
        }

        window.display();
         window.clear();
    }
}

