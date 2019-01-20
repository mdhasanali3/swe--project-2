#include<bits/stdc++.h>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>



using namespace std;
using namespace sf;

///       variable   ///////////
int score=0,hp=10000;



    RenderWindow window(VideoMode(1300,770),"game");

                ///   function ///////////////////

void g1(void);
void g2(void);

        ///         class and structure       /////////



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

class stone
{
public:
    Sprite shape;
    int hp=30,hpmax;
    stone(Texture *texture,Vector2f pos)
    {
        this->hpmax=rand()%6+4;
        this->hp=this->hpmax;

        this->shape.setTexture(*texture);
        this->shape.scale(.08f,.08f);
      this->shape.setPosition(pos);


        }
};
class coin
{
public:
    Sprite shape;

    coin(Texture *texture,Vector2f pos)
    {

        this->shape.setTexture(*texture);
        this->shape.scale(.3f,.3f);
      this->shape.setPosition(pos);


        }
};
void main_menu()
{

srand(time(0));
 //window.setFramerateLimit(60);
 Texture tr;
 tr.loadFromFile("tunnel_01_shot_01.jpg");
 Sprite sd(tr);
 sd.setPosition(0,0);

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
  text.setString("first level ");

    t1.setPosition(220,130);
        t1.setString("second level");

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

Vector2f n=(Vector2f)Mouse::getPosition(window);


if((n.x>=210&&n.x<=410)&&(n.y>=125&&n.y<=155))
    {t1.setFillColor(Color::Magenta);
    if(Mouse::isButtonPressed(Mouse::Left)||Keyboard::isKeyPressed(Keyboard::Space))
    g2();
    }
    else
        t1.setFillColor(Color::Red);

        if((n.x>=210&&n.x<=445)&&(n.y>=243&&n.y<=295))
    t2.setFillColor(Color::Magenta);

    else
        t2.setFillColor(Color::Red);


if((n.x>=210&&n.x<=400)&&(n.y>=27&&n.y<=60))
      {//window.clear(Color::Green);
          text.setFillColor(Color::Magenta);
    if(Mouse::isButtonPressed(Mouse::Left)||Keyboard::isKeyPressed(Keyboard::Space))
    g1();
    }
    else
text.setFillColor(Color::Red);
if((n.x>=210&&n.x<=290)&&(n.y>=380&&n.y<=410))
    {window.clear(Color::Green);
    if(Mouse::isButtonPressed(Mouse::Left)||Keyboard::isKeyPressed(Keyboard::Space))
    window.close();
    }
    else
        {t3.setFillColor(Color::Red);
window.draw(sd);}
window.draw(text);
//window.draw(r1);
window.draw(t3);
window.draw(t2);
window.draw(t1);


window.display();

   // clearviewport();
window.clear();
}
}





main()
{

srand(time(0));
 window.setFramerateLimit(60);
main_menu();

}

void g1()

    {
        srand(time(0));
        Texture texture,shiptex;
    texture.loadFromFile("solderAll.png");


    IntRect recsourcesprite(0,0,129,181),resourcesprite(0,181,129,387);
    Sprite sp(texture,recsourcesprite);
  sp.setScale(.7f,.7f);
    sp.setOrigin(sp.getPosition().x+115,sp.getPosition().y+50);
    sp.setPosition(200.f,500.f);

    shiptex.loadFromFile("dfh45hygd.jpg");
    RectangleShape ship;
    ship.setSize(Vector2f(200.f,111.f));
    ship.setTexture(&shiptex);
    ship.setPosition(0,66);


        Texture background1;
        int hp=10000;
        background1.loadFromFile("finale .jpg");


        Sprite back1(background1);

/// stone coin  all///
 Texture stonetex;
    stonetex.loadFromFile("stne.png");

    Texture tex;
    tex.loadFromFile("iruytruii.jpg");

     IntRect rectsourcesprite(0,0,70,70);
    Sprite s(tex,rectsourcesprite);

Clock clock,cloc,clo;

vector<stone>stones;
 int stonetimer=0,f=-1;

 vector<coin>coins;
 int coinfalltimer=0;

    Font font;
    font.loadFromFile("AGENTORANGE.TTF");
    Text text;
    text.setFont(font);
    text.setCharacterSize(22);
    text.setFillColor(Color::Red);
    text.setPosition(10.f,30.f);

    Text hptext;
    hptext.setFont(font);
    hptext.setCharacterSize(14);
    hptext.setFillColor(Color::White);
    hptext.setPosition(window.getSize().x-100,40.f);


    Text enhptext;
    enhptext.setFont(font);
    enhptext.setCharacterSize(18);
    enhptext.setFillColor(Color::Yellow);


///     bullet    //////////
    bullet b1;
    vector<bullet>bullets;
    Texture tex1,tex2,tex4,tex5;
    tex1.loadFromFile("Tau_Beas reverse t.png");
tex2.loadFromFile("Tau_Beas reverse t.png");
tex4.loadFromFile("mothman-transparent-adorable-3.png");
tex5.loadFromFile("mothman-transparent-adorable-3.png");

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


    float c,v,m,p,q,r,z=-.2;

    while(window.isOpen()&&hp>0)
    {

        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type==Event::Closed)
                window.close();

            if(Keyboard::isKeyPressed(Keyboard::Escape))
                main_menu();
        }

    if(hp<3)
        main_menu();
        Vector2i pos,curr;
        pos=Vector2i(sp.getPosition());

        ///    update   ////////////
        playercenter=Vector2f(sp.getPosition().x,sp.getPosition().y);

        mouseposwindow=Vector2f(Mouse::getPosition(window));
        aimdir=mouseposwindow-playercenter;
        c=aimdir.x*aimdir.x;
        v=aimdir.y*aimdir.y;
        m=c+v;
        aimdirnorm=aimdir/sqrt(m);

///   background         //////////////////////////////////////////



  ///    player update  ////////

        if(Keyboard::isKeyPressed(Keyboard::Up))
            {sp.move(0,-10.f);

            }
        if(Keyboard::isKeyPressed(Keyboard::Down))
            {sp.move(0,10.f);
         }
        if(Keyboard::isKeyPressed(Keyboard::Right))
            {sp.move(4.f,0);

  if(cloc.getElapsedTime().asSeconds()>.09f)
        {if(recsourcesprite.left>=382)
            recsourcesprite.left=0;
            else
            recsourcesprite.left+=140;

            sp.setTextureRect(recsourcesprite);
            cloc.restart();

        }


            }
        if(Keyboard::isKeyPressed(Keyboard::Left))
           {sp.move(-4.f,0);
   if(clo.getElapsedTime().asSeconds()>.09f)
        {if(resourcesprite.left<=0)
            resourcesprite.left=382;
            else
            resourcesprite.left-=127;

            sp.setTextureRect(resourcesprite);
            clo.restart();

        }



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
                {ship.move(-2,0);
                }
    if(ship.getPosition().x<=0)
           dir=1;
           if(dir==1)
                {ship.move(2,0);
                }


    ///    enemy move and shooting    ////////////




    for(size_t i=0;i<enemies1.size();i++)
    {
        enemyloc=Vector2f(enemies1[i].getPosition());
if(enemies1[i].getPosition().y<440)
{enemies1[i].setTexture(&tex1);
}
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
        {enemies1[i].setTexture(&tex4);
//enemy2.setTexture(&tex5);
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
enemies2[i].setTexture(&tex2);
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
         enemies2[i].setTexture(&tex4);
//enemy2.setTexture(&tex5);
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
      for(size_t k=0;k<enemies2.size();k++)
    {if(bullets[i].shape.getGlobalBounds().intersects(enemies2[k].getGlobalBounds()))
{enemies2.erase(enemies2.begin()+k);
bullets.erase(bullets.begin()+i);
score+=3;
break;
}

    }
    }




            ///  /         stone  collision    ////////
    for(size_t k=0;k<stones.size();k++)
{
    if(bullets[i].shape.getGlobalBounds().intersects(stones[k].shape.getGlobalBounds()))
    {
        if(stones[k].hp==1)
       {
            stones.erase(stones.begin()+k);
       score+=stones[k].hpmax;
       }
       else
        stones[k].hp--;

       bullets.erase(bullets.begin()+i);
        break;
    }
    }


        }
      ///  update enemies     ////
if(stonetimer<40)
    stonetimer++;
 if(stonetimer>=40)
 {
        stones.push_back(stone(&stonetex,ship.getPosition()));
stonetimer=-100;
 }
 for(size_t i=0;i<stones.size();i++)
{
    stones[i].shape.move(z,5.f);
    if(stones[i].shape.getPosition().y>=560)
        stones.erase(stones.begin()+i);
    if(stones[i].shape.getGlobalBounds().intersects(sp.getGlobalBounds()))
  {stones.erase(stones.begin()+i);
    hp-=stones[i].hp;

  }
}

///      update coins ///
if(coinfalltimer<750)
    coinfalltimer++;
 if(coinfalltimer==750)
 {
        coins.push_back(coin(&tex,ship.getPosition()));
coinfalltimer=0;
 }
 for(size_t i=0;i<coins.size();i++)
{
    coins[i].shape.move(0,2.f);

        if(clock.getElapsedTime().asSeconds()>.05f)
        {if(rectsourcesprite.left>=202)
            rectsourcesprite.left=0;
            else
            rectsourcesprite.left+=80;

            coins[i].shape.setTextureRect(rectsourcesprite);
           // coins[i].shape.move(0,.3f);
            clock.restart();

        }

    if(coins[i].shape.getPosition().y>=560)
        coins.erase(coins.begin()+i);
    if(coins[i].shape.getGlobalBounds().intersects(sp.getGlobalBounds()))
  {coins.erase(coins.begin()+i);
    hp+=10;
 coins.push_back(coin(&tex,ship.getPosition()));
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
if(sp.getGlobalBounds().intersects(enemies1[i].getGlobalBounds()))
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
            if(sp.getGlobalBounds().intersects(enemies2[i].getGlobalBounds()))
{hp--;
    break;
    }
            }


        char a[100],b[100];
        sprintf(a," your position x=%d   y=%d \t\t\t\t\t \t\t\t  hp = %d\n \n \t score :  %d \n",pos.x,pos.y,hp,score);
        text.setString(a);



  ///    draw     ////////////


if(sp.getPosition().x<200)
    sp.setPosition(Vector2f(200.f,sp.getPosition().y));

    if(sp.getPosition().x>1200)
     sp.setPosition(Vector2f(1200.f,sp.getPosition().y));

if(sp.getPosition().y>500)
      sp.setPosition(Vector2f(sp.getPosition().x,500.f));

    if(sp.getPosition().y<450)
      sp.setPosition(Vector2f(sp.getPosition().x,450.f));



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
             for(size_t i=0; i<stones.size(); i++)
        {
            char ara[100];
        sprintf(ara,"\n         %d",stones[i].hp);
       enhptext.setString(ara);
        enhptext.setPosition(stones[i].shape.getPosition().x,stones[i].shape.getPosition().y);
           window.draw(enhptext);
            window.draw(stones[i].shape);
        }
 for(size_t i=0; i<coins.size(); i++)
        {
            window.draw(coins[i].shape);
        }
            window.draw(ship);
            window.draw(sp);
        //window.draw(sp);
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
    Texture texture;
    IntRect recsourcesprite(0,0,129,181),resourcesprite(0,181,129,387);
    Sprite sp(texture,recsourcesprite);



    texture.loadFromFile("solderAll.png");


  sp.setScale(.7f,.7f);
    sp.setOrigin(sp.getPosition().x+115,sp.getPosition().y+50);
    sp.setPosition(200.f,500.f);
Vertex line;
	line.color=Color::White;
	Vector2f startPos;
	Vector2f mousePos;
	bool isDrawRectangle = false;
    Clock cloc,clo;
	bool done = false;
	while (done == false)
	{
		window.clear();

		Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				done = true;
				break;
			case Event::MouseButtonPressed:
				switch (event.mouseButton.button)
				{
				case Mouse::Button::Left:
					isDrawRectangle = true;
					startPos = mousePos;
					break;
				default:
					break;
				}
				break;
			case Event::MouseButtonReleased:
				switch (event.mouseButton.button)
				{
				case Mouse::Button::Left:
					isDrawRectangle = false;
					break;
				default:
					break;
				}
				break;
			case Event::MouseMoved:
				mousePos.x = event.mouseMove.x;
				mousePos.y = event.mouseMove.y;
				break;
			default:
				break;
			}
		}
		if(Keyboard::isKeyPressed(Keyboard::Escape))
      window.close();
      //main_menu();
		if(Keyboard::isKeyPressed(Keyboard::Left))
            {sp.move(-3,0);


   if(clo.getElapsedTime().asSeconds()>.08f)
        {if(resourcesprite.left<=0)
            resourcesprite.left=382;
            else
            resourcesprite.left-=121;

            sp.setTextureRect(resourcesprite);
            clo.restart();

        }

        }
		if(Keyboard::isKeyPressed(Keyboard::Right))
            {sp.move(3,0);
         if(cloc.getElapsedTime().asSeconds()>.08f)
        {if(recsourcesprite.left>=382)
            recsourcesprite.left=0;
            else
            recsourcesprite.left+=142;

            sp.setTextureRect(recsourcesprite);
            cloc.restart();

        }

            }
		if(Keyboard::isKeyPressed(Keyboard::Up))
            sp.move(0,-3);
    //cout<<line.position.x<<" "<<line.position.y<<endl;
		if(startPos.x==sp.getPosition().x)
     {if(Keyboard::isKeyPressed(Keyboard::Down))
            sp.move(0,0);
     }
else
    {
        if(Keyboard::isKeyPressed(Keyboard::Down))
        sp.move(0,3);
    }
    if(sp.getPosition().y>=600)
    sp.setPosition(sp.getPosition().x,600);
           Vertex line[]={
        Vertex(Vector2f(startPos.x,startPos.y))
,Vertex(Vector2f(mousePos.x,mousePos.y))  };
line[0].position=Vector2f(startPos.x,startPos.y);


if (isDrawRectangle)
			window.draw(line,2,Lines);
        window.draw(sp);
        // window.draw(spe);
		window.display();
	}


}

