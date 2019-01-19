#include<bits/stdc++.h>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include<math.h>
#include<stdlib.h>
#include<cstdlib>
#include <time.h>
#include<bits/stdc++.h>



using namespace std;
using namespace sf;
///       variable   ///////////
int score=0,hp=10000;
float j=0.0;
bool happen=false;


    enum dir{Left,Right};
    int sourcex=138,sourcey=Right;
    Vector2i source(1,Right);


    RenderWindow window(VideoMode(1300,770),"game");

                ///   function ///////////////////

void g1(void);
void g2(void);

        ///         class and structure       /////////


struct point
{ int x,y;};


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

void main_menu()
{

srand(time(0));
 //window.setFramerateLimit(60);
     Font font;
    font.loadFromFile("AGENTORANGE.TTF");
    Text text,t2,t4,t3,t1,t5;
    text.setFont(font);

      t1.setFont(font);  t2.setFont(font);  t3.setFont(font);  t4.setFont(font);  t5.setFont(font);
    text.setCharacterSize(22);  t1.setCharacterSize(22);t2.setCharacterSize(22);
    t3.setCharacterSize(22); t4.setCharacterSize(22); t5.setCharacterSize(22);
    text.setFillColor(Color::Red); t1.setFillColor(Color::Red); t2.setFillColor(Color::Red);
      t3.setFillColor(Color::Red); t4.setFillColor(Color::Red); t5.setFillColor(Color::Red);


    text.setPosition(220,30);
  text.setString(" i don't know ");

    t1.setPosition(220,130);
        t1.setString("select level");

        t2.setPosition(220,250);
        t2.setString("Information ");

        t3.setPosition(220,385);
        t3.setString("Exit ");


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

//if(Vector2i(text.getGlobalBounds()).intersects(Vector2i(Mouse::getPosition(window).getGlobalBounds())))
//cout<<t3.getPosition().x<<" "<<t3.getPosition().y;

Vector2f n=(Vector2f)Mouse::getPosition(window);
//cout<<n.x<<" "<<n.y<<endl;

if((n.x>=210&&n.x<=410)&&(n.y>=125&&n.y<=155))
    {t1.setFillColor(Color::Magenta);
    if(Mouse::isButtonPressed(Mouse::Left))
    g1();
    }
    else
        t1.setFillColor(Color::Red);

        if((n.x>=210&&n.x<=445)&&(n.y>=243&&n.y<=295))
    t2.setFillColor(Color::Magenta);

    else
        t2.setFillColor(Color::Red);


if((n.x>=210&&n.x<=290)&&(n.y>=380&&n.y<=410))
    {t3.setFillColor(Color::Magenta);
    if(Mouse::isButtonPressed(Mouse::Left))
    window.close();
    }
    else
        t3.setFillColor(Color::Red);

if((n.x>=215&&n.x<=450)&&(n.y>=27&&n.y<=60))
window.clear(Color::Green);

window.draw(text);
//window.draw(r1);
window.draw(t3);
window.draw(t2);
window.draw(t1);


window.display();
//
   // clearviewport();
window.clear();
}
}





main()
{

srand(time(0));
 window.setFramerateLimit(60);
g1();


}

void g1()

    {
        srand(time(0));
        Texture texture,shiptex;
    texture.loadFromFile("soldierSeatDownShoot.png");
    RectangleShape circle;
    circle.setSize(Vector2f(150.f,100.f));
    circle.setTexture(&texture);
    circle.setScale(.7f,.7f);
    circle.setOrigin(circle.getPosition().x+115,circle.getPosition().y+50);
    circle.setPosition(200.f,500.f);

    shiptex.loadFromFile("dfh45hygd.jpg");
    RectangleShape ship;
    ship.setSize(Vector2f(200.f,111.f));
    ship.setTexture(&shiptex);
    ship.setPosition(0,66);


        Texture background1;
        int hp=10000;
        background1.loadFromFile("finale .jpg");


        Sprite back1(background1);



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
    Texture tex1,tex2;
    tex1.loadFromFile("Tau_Beas reverse t.png");
tex2.loadFromFile("Tau_Beas reverse t.png");

        RectangleShape enemy1,enemy2;
    vector<RectangleShape>enemies1,enemies2;
    int enemycount=20;
    //enemy.setFillColor(Color::Green);
    enemy1.setSize(Vector2f(70.f,35.f));
   enemy1.setOrigin(enemy1.getSize().x,0);

  enemy2.setSize(Vector2f(70.f,35.f));
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

    while(window.isOpen()&&hp>0)
    {

        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type==Event::Closed)
                window.close();

            if(Keyboard::isKeyPressed(Keyboard::Escape))
                main();
        }

    if(hp<3)
        main_menu();
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



  ///    player update  ////////

        if(Keyboard::isKeyPressed(Keyboard::Up))
            {circle.move(0,-10.f);
            source.y=Right;
           // y--;

            }
        if(Keyboard::isKeyPressed(Keyboard::Down))
            {circle.move(0,10.f);
 source.y=Right;
//  y++;
            }
        if(Keyboard::isKeyPressed(Keyboard::Right))
            {circle.move(7.f,0);
 source.y=Right;
 //back_change_right();
 //x++;


            }
        if(Keyboard::isKeyPressed(Keyboard::Left))
           {circle.move(-7.f,0);
   //        x--;
 //back_change_left();

}

        ///    update enemies    //////
        if(enemycount<140)
            enemycount++;

        if(enemycount>=140)
        {
             enemy1.setPosition(458.f,195.f);
              enemies1.push_back(RectangleShape(enemy1));

                enemy2.setPosition(805.f,195.f);
              enemies2.push_back(RectangleShape(enemy2));

//           enemy2.setPosition(1044.f,196.f);
//              enemies2.push_back(RectangleShape(enemy2));

            enemycount=0;


        }

       ///      ship moving   ////


  int  dir;
           if(ship.getPosition().x>=window.getSize().x-ship.getSize().x)
            dir=0;
            if(dir==0)
                {ship.move(-5,0);
                }
    if(ship.getPosition().x<=0)
           dir=1;
           if(dir==1)
                {ship.move(5,0);
                }


    ///    enemy move and shooting    ////////////




    for(size_t i=0;i<enemies1.size();i++)
    {
        enemyloc=Vector2f(enemies1[i].getPosition());

    if(enemies1[i].getPosition().y<290&&enemies1[i].getPosition().y>12)
    {

      enemies1[i].move(-.7f,1.f);
   }

  else if(enemies1[i].getPosition().y>=290&&enemies1[i].getPosition().y<=336)
   {
       enemies1[i].move(1.f,0.f);
        if(enemies1[i].getPosition().x>=490)
            enemies1[i].move(0.f,1.3f);
   }
  else if(enemies1[i].getPosition().y>=336&&enemies1[i].getPosition().y<=440)
   {enemies1[i].move(-.8f,.2);
    if(enemies1[i].getPosition().x<=445)
        enemies1[i].move(0.f,1.f);
   }
    else if(enemies1[i].getPosition().y>=440)
        {
             ai=enemyloc-playercenter;
        p=ai.x*ai.x;
        q=ai.y*ai.y;
        r=p+q;
        ain=ai/sqrt(r);
            enemies1[i].move(-ain);
    }

  //  else if()
    }
     for(size_t i=0;i<enemies2.size();i++)
    {
        enemyloc=Vector2f(enemies2[i].getPosition());

 if((enemies2[i].getPosition().x>=535&&enemies2[i].getPosition().x<=1595)&&enemies2[i].getPosition().y<430)
    {
        if(enemies2[i].getPosition().y>=2&&enemies2[i].getPosition().y<230)
        enemies2[i].move(0.f,1.f);


    else if(enemies2[i].getPosition().y>=230&&enemies2[i].getPosition().y<=300)
        { if(enemies2[i].getPosition().x<=680)
        enemies2[i].move(0.f,1.f);
            else
            enemies2[i].move(-1.f,0.f);
     }
     else if(enemies2[i].getPosition().y>=300)
    {if(enemies2[i].getPosition().x<=1400&&enemies2[i].getPosition().x>=1050)
        enemies2[i].move(0.f,1.f);
        else
        enemies2[i].move(1.f,0.f);

    }
     }
     else
     {
  ai=enemyloc-playercenter;
        p=ai.x*ai.x;
        q=ai.y*ai.y;
        r=p+q;
        ain=ai/sqrt(r);
 enemies2[i].move(-ain);
}
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
                    ||bullets[i].shape.getPosition().y<420||bullets[i].shape.getPosition().y>580)
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

if(circle.getPosition().x<200)
    circle.setPosition(Vector2f(200.f,circle.getPosition().y));

    if(circle.getPosition().x>1200)
     circle.setPosition(Vector2f(1200.f,circle.getPosition().y));

if(circle.getPosition().y>550)
      circle.setPosition(Vector2f(circle.getPosition().x,550.f));

    if(circle.getPosition().y<450)
      circle.setPosition(Vector2f(circle.getPosition().x,450.f));



window.draw(back1);


        window.draw(text);
        for(size_t i=0; i<enemies1.size(); i++)
        {
            window.draw(enemies1[i]);

            }
 for(size_t i=0; i<enemies2.size(); i++)
        {
            window.draw(enemies2[i]);

            }
            window.draw(ship);
window.draw(circle);
        for(size_t i=0; i<bullets.size(); i++)
        {
            window.draw(bullets[i].shape);
        }


        window.display();
         window.clear();
    }}




 void g2()
{
    srand(time(0));


    window.setFramerateLimit(60);

    Texture t1,t2,t3,b1b,e1e;
    t1.loadFromFile("images/7f7c4ef4b62f622f944831f1be6eab7e.png");
    t2.loadFromFile("images/platform.png");
    t3.loadFromFile("images/doodle.png");
    b1b.loadFromFile("enemy bullet back.png");
    e1e.loadFromFile("villan.png");
    //e1e.setOrigin(400,400);
        t1.setRepeated(true);
    Sprite sBackground(t1), sPlat(t2), sPers(t3);
    sPers.setScale(.8,.8);
    sBackground.setTextureRect(IntRect(0,0,window.getSize().x,window.getSize().y));

Sprite enem;
enem.setScale(.5,.5);
enem.setTexture(e1e);
//enem.setOrigin(100,100);

    Sprite bulle;
bulle.setScale(.4f,.4f);
bulle.setTexture(b1b);
//bulle.setOrigin(150,150);

    point plat[100];
    vector<Sprite>enem1;
vector<Sprite>bul;
enem1.push_back(Sprite(enem));
bul.push_back(Sprite(bulle));
int ebs=10;

    for (int i=0;i<40;i++)
      {
       plat[i].x=rand()%window.getSize().x;
       plat[i].y=rand()%window.getSize().y;
      }

	int x=100,y=100,h=500,f=500,g=10;
    float dx=0,dy=0;

    while (window.isOpen()&&hp>0)
    {
        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
                window.close();
        }

    if (Keyboard::isKeyPressed(Keyboard::Right)||Keyboard::isKeyPressed(Keyboard::D)) x+=3;
    if (Keyboard::isKeyPressed(Keyboard::Left)) x-=3;
     if (Keyboard::isKeyPressed(Keyboard::Up)) y-=5;
      if (Keyboard::isKeyPressed(Keyboard::Down)) y+=5;

    dy+=0.6f;
    y+=dy;
    dx+=.03f;
    x+=dx;
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

             s:
             if(plat[i].y>520||plat[i].y<70)
             {
                plat[i].y=rand()%window.getSize().y;
                goto s;
             }

     }
            }


        }
            if(g<30)
                g++;
            if(g>=30){
            enem.setPosition(Vector2f(rand()%(int)window.getSize().x,rand()%200));
          enem1.push_back(Sprite(enem));
            g=0;
          for(int i=0;i<2;i++){
    bulle.setPosition(enem1[i].getPosition().x,enem1[i].getPosition().y+40);
    bul.push_back(Sprite(bulle));

   }
   }

	for (int i=0;i<40;i++)
    {
        if ((x+50>plat[i].x) && (x+20<plat[i].x+68)
    && (y+70>plat[i].y) && (y+70<plat[i].y+14) && (dx>0))
    {
      dy=-10;
    }}


   for(size_t i=0;i<enem1.size();i++)
{
   enem1[i].move(0,.5f);

    if(enem1[i].getPosition().y<=100)
        enem1.erase(enem1.begin()+i);
        //cout<<enem1[i].getPosition().x<<"     "<<enem1[i].getPosition().y<<endl;
if(enem1[i].getGlobalBounds().intersects(sPers.getGlobalBounds()))
  {enem1.erase(enem1.begin()+i);
  //player.hp--;

  }
}

    for(size_t i=0;i<bul.size();i++)
{
    bul[i].move(-5.f,0);
    if(bul[i].getPosition().x<=-100)
        bul.erase(bul.begin()+i);
 if(bul[i].getGlobalBounds().intersects(sPers.getGlobalBounds()))
  {bul.erase(bul.begin()+i);
  //player.hp--;

 }
}


window.clear();
	sPers.setPosition(x,y);

    window.draw(sBackground);
    window.draw(sPers);
   for(size_t i=0;i<bul.size();i++)
{

    window.draw(bul[i]);
}
  for (int i=0;i<enem1.size();i++)
    {
// enem1.setPosition(enbp[i].x,enbp[i].y);
    window.draw(enem1[i]);

    }


    for (int i=0;i<40;i++)
    {
    sPlat.setPosition(plat[i].x,plat[i].y);
    window.draw(sPlat);

    }

    window.display();

}
}
