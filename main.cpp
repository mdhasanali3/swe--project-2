#include<bits/stdc++.h>
#include<SFML/Graphics.hpp>
#include<math.h>
#include<stdlib.h>
#include<cstdlib>

using namespace std;
using namespace sf;
///       variable   ///////////
int score=0,hp=1000;
float j=0.0;
bool happen=false;

                ///   function ///////////////////




        ///         class and structure       /////////


        struct point
{ int x,y;
};



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
    RectangleShape circle;
    circle.setSize(Vector2f(150.f,100.f));
    circle.setTexture(&texture);
    circle.setScale(.7f,.7f);
    circle.setOrigin(circle.getPosition().x+115,circle.getPosition().y+50);
    circle.setPosition(200.f,500.f);

        Texture background1,background2,background3;

        background1.loadFromFile("7f7c4ef4b62f622f944831f1be6eab7e.png");
        background2.loadFromFile("bg 2.png");
          background3.loadFromFile("sprites-background-63.png");


        Sprite back1(background1),back2(background1),back3(background2),back4(background2),back5(background3),back6(background3);

        int backy1=1,backy2=2249,backy3=4496,backy4=8436,backy5=12376,backy6=15816;

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

///  plat    /////////

point plat[100];
Texture te;
te.loadFromFile("platform.png");
Sprite splat;
splat.setTexture(te);
//splat.setScale(.1f,.1f);
splat.setTextureRect(IntRect(0,0,70,20));

if(back5.getPosition().x+1400<window.getSize().x)
{
      for (int i=0;i<60;i++)
      {
       plat[i].x=rand()%window.getSize().x;
       plat[i].y=rand()%window.getSize().y;
      }
}
int x=100,y=100,h=500,f=500;
    float dx=0,dy=0;
///    enemy     /////
  // enemy *e1;
    Texture tex1,tex2;
    tex1.loadFromFile("Tau_Beast.png");
tex2.loadFromFile("Tau_Beas reverse t.png");

        RectangleShape enemy1,enemy2;
    vector<RectangleShape>enemies1,enemies2;
    int enemycount=20;
    //enemy.setFillColor(Color::Green);
    enemy1.setSize(Vector2f(150.f,75.f));
   enemy1.setOrigin(enemy1.getSize().x,0);

  enemy2.setSize(Vector2f(150.f,75.f));
   enemy2.setOrigin(enemy2.getSize().x,0);

enemy1.setTexture(&tex1);
enemy2.setTexture(&tex2);

///   vectors      //////
    Vector2f playercenter;
    Vector2f mouseposwindow;
    Vector2f aimdir;
    Vector2f aimdirnorm;
    Vector2f enemyloc;
    Vector2f ai;
    Vector2f ain;


    float c,v,m,p,q,r;
 //int p,q,r;
 //if(){
    while(window.isOpen()&&hp>0)
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
back5.setPosition(backy5,0);
        back6.setPosition(backy6,0);


  ///    player update  ////////

        if(Keyboard::isKeyPressed(Keyboard::Up))
            {circle.move(0,-10.f);
            source.y=Right;
            y--;

            }
        if(Keyboard::isKeyPressed(Keyboard::Down))
            {circle.move(0,10.f);
 source.y=Right;
y++;
            }
        if(Keyboard::isKeyPressed(Keyboard::Right))
            {circle.move(.7f,0);
 source.y=Right;
 //back_change_right();
 x++;
  backy1-=3;
     backy2-=3;
 backy3-=3;
     backy4-=3;
backy5-=3;
     backy6-=3;
            }
        if(Keyboard::isKeyPressed(Keyboard::Left))
           {circle.move(-.7f,0);
           x--;
 //back_change_left();
    backy1+=3;
       backy2+=3;
        backy3+=3;
       backy4+=3;
backy5+=3;
       backy6+=3;
}

///   plat update and check landing        ///////

if(back5.getPosition().x+1400<window.getSize().x)
{  circle.setPosition(Vector2f(x,y));
cout<<circle.getPosition().x<< "   "<<circle.getPosition().y<<endl;
}
      dy+=0.5f;
    y+=dy;
    dx+=.03f;
   // x+=dx;
    if (y>500)
        dy=-10;

	if (x>h)
   {
       for (int i=0;i<40;i++)
    {
      x=h;///y=300
      dx=1;
      plat[i].x=plat[i].x-dx;
      if (plat[i].x>window.getSize().x)
        {
            plat[i].x=rand()%window.getSize().x;
             plat[i].y=rand()%window.getSize().y;
        if(plat[i].y<200)
            plat[i].y=rand()%window.getSize().y;
        if(plat[i].y>500)
            plat[i].y=rand()%window.getSize().y;
         if(plat[i].y<200)
            plat[i].y=rand()%window.getSize().y;
        if(plat[i].y>500)
            plat[i].y=rand()%window.getSize().y;
             if(plat[i].y<200)
            plat[i].y=rand()%window.getSize().y;
        if(plat[i].y>500)
            plat[i].y=rand()%window.getSize().y;
     }   }
     //dx-=10;
    }

	for (int i=0;i<40;i++)
    {if ((x-25>plat[i].x) && (x-55<plat[i].x+68)
    && (y+20>plat[i].y) && (y+20<plat[i].y+14) && (dx>0))
    {
      dy=-10;
    }}

        ///    update enemies    //////
        if(enemycount<40)
            enemycount++;

        if(enemycount>=40)
        {
             enemy1.setPosition(back1.getPosition().x+200,630.f);
              enemies1.push_back(RectangleShape(enemy1));

           enemy2.setPosition(back1.getPosition().x+1100.f,419.f);
              enemies2.push_back(RectangleShape(enemy2));

              enemy1.setPosition(back2.getPosition().x+200,630.f);
              enemies1.push_back(RectangleShape(enemy1));

           enemy2.setPosition(back2.getPosition().x+1100.f,419.f);
              enemies2.push_back(RectangleShape(enemy2));

            enemycount=0;


        }

    ///    enemy move and shooting    ////////////

    for(size_t i=0;i<enemies1.size();i++)
    {
        enemyloc=Vector2f(enemies1[i].getPosition());


          ai=enemyloc-playercenter;
        p=ai.x*ai.x;
        q=ai.y*ai.y;
        r=p+q;
        ain=ai/sqrt(r);

        enemies1[i].move(-ain);
    }

     for(size_t i=0;i<enemies2.size();i++)
    {
        enemyloc=Vector2f(enemies2[i].getPosition());


          ai=enemyloc-playercenter;
        p=ai.x*ai.x;
        q=ai.y*ai.y;
        r=p+q;
        ain=ai/sqrt(r);

        enemies2[i].move(-ain);
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
///    bullet out of bounds   ///////
            if(bullets[i].shape.getPosition().x<0||bullets[i].shape.getPosition().x>window.getSize().x
                    ||bullets[i].shape.getPosition().y<0||bullets[i].shape.getPosition().y>window.getSize().y)
             {
                 bullets.erase(bullets.begin()+i);

             }

    ///    collision  with bullet and enemy  also checking player hp ////
   for(size_t k=0;k<enemies1.size();k++)
    {if(bullets[i].shape.getGlobalBounds().intersects(enemies1[k].getGlobalBounds()))
{enemies1.erase(enemies1.begin()+k);
bullets.erase(bullets.begin()+i);
score+=3;
break;
}

    }
       for(size_t k=0;k<enemies2.size();k++)
    {if(bullets[i].shape.getGlobalBounds().intersects(enemies2[k].getGlobalBounds()))
{enemies2.erase(enemies2.begin()+k);
bullets.erase(bullets.begin()+i);
score+=3;
break;
}

    }

        }
///   enemy  out of area   remove   ////////////
        for(size_t i=0;i<enemies1.size();i++)
        {
            if(enemies1[i].getPosition().x<0||enemies1[i].getPosition().x>window.getSize().x
                    ||enemies1[i].getPosition().y<0||enemies1[i].getPosition().y>window.getSize().y)
             {
                 enemies1.erase(enemies1.begin()+i);

             }
if(circle.getGlobalBounds().intersects(enemies1[i].getGlobalBounds()))
{hp--;
    break;
    }
            }
             for(size_t i=0;i<enemies2.size();i++)
        {
            if(enemies2[i].getPosition().x<0||enemies2[i].getPosition().x>window.getSize().x
                    ||enemies2[i].getPosition().y<0||enemies2[i].getPosition().y>window.getSize().y)
             {
                 enemies2.erase(enemies2.begin()+i);

             }
            if(circle.getGlobalBounds().intersects(enemies2[i].getGlobalBounds()))
{hp--;
    break;
    }
            }


        char a[100],b[100];
        sprintf(a," your position x=%d   y=%d \t\t\t\t\t \t\t\t  hp = %d\n \n \t score :  %d \n",pos.x,pos.y,hp,score);
        text.setString(a);

  ///    draw     ////////////

circle.setTextureRect(IntRect(source.x*1,source.y*1,130,155));

if(circle.getPosition().x>1200||circle.getPosition().x<200)
    circle.setPosition(Vector2f(400.f,500.f));

window.draw(back1);
window.draw(back2);
window.draw(back3);
window.draw(back4);
window.draw(back5);
window.draw(back6);

        window.draw(text);
        for(size_t i=0; i<enemies1.size(); i++)
        {
            window.draw(enemies1[i]);

            }
 for(size_t i=0; i<enemies2.size(); i++)
        {
            window.draw(enemies2[i]);

            }
window.draw(circle);
        for(size_t i=0; i<bullets.size(); i++)
        {
            window.draw(bullets[i].shape);
        }

if(back5.getPosition().x+1400<window.getSize().x){
    for (int i=0;i<40;i++)
    {
    splat.setPosition(plat[i].x,plat[i].y);
    window.draw(splat);
//cout<<"hi"<<plat[i].y<<endl;
    }
}
        window.display();
         window.clear();
    }
}

