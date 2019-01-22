#include<bits/stdc++.h>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<fstream>


using namespace std;
using namespace sf;

///       variable   ///////////
int score=0,hp=10000;
int  dir;


RenderWindow window(VideoMode(1300,770),"game");

///   function ///////////////////

void g1(void);
void g2(void);

///         class and structure       /////////



class bullet
{

public:

    //Texture bultex;
    //  bultex.loadFromFile("billet.jpg");

    CircleShape shape;
    //shape.setTexture(&bultex);
    Vector2f currentvelocity;
    float maxspeed;

    bullet(float radius=8.f)
        :currentvelocity(0.f,0.f),maxspeed(15.f)
    {
        //   this->shape.setTexture(&tex);


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
        if(dir==1)
            this->shape.setPosition(pos.x+120,pos.y+20);
        else
            this->shape.setPosition(pos.x+70,pos.y+20);

       // cout<<dir<<endl;
    }
};
class coin
{
public:
    Sprite shape;

    coin(Texture *texture,Vector2f pos)
    {

        this->shape.setTexture(*texture);
        this->shape.scale(.09f,.09f);
        this->shape.setPosition(pos);


    }
};

class sheild
{
public:
    Sprite shape;

    sheild(Texture *texture,Vector2f pos)
    {

        this->shape.setTexture(*texture);
        //shape.setOrigin(-150,-150);
        this->shape.scale(.2f,.2f);
        this->shape.setPosition(pos.x-80,pos.y);


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

    t1.setFont(font);
    t2.setFont(font);
    t3.setFont(font);
    t4.setFont(font);
    t5.setFont(font);
    text.setCharacterSize(22);
    t1.setCharacterSize(22);
    t2.setCharacterSize(22);
    t3.setCharacterSize(22);
    t4.setCharacterSize(22);
    t5.setCharacterSize(22);
    text.setFillColor(Color::Red);
    t1.setFillColor(Color::Red);
    t2.setFillColor(Color::Red);
    t3.setFillColor(Color::Red);
    t4.setFillColor(Color::Red);
    t5.setFillColor(Color::Red);


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

        Event event;
        while(window.pollEvent(event))
        {
            if(event.type==Event::Closed)
                window.close();

            if(Keyboard::isKeyPressed(Keyboard::Escape))
                window.close();
        }

        Vector2f n=(Vector2f)Mouse::getPosition(window);


        if((n.x>=210&&n.x<=410)&&(n.y>=125&&n.y<=155))
        {
            t1.setFillColor(Color::Magenta);
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
        {
            //window.clear(Color::Green);
            text.setFillColor(Color::Magenta);
            if(Mouse::isButtonPressed(Mouse::Left)||Keyboard::isKeyPressed(Keyboard::Space))
                g1();
        }
        else
            text.setFillColor(Color::Red);
        if((n.x>=210&&n.x<=290)&&(n.y>=380&&n.y<=410))
        {
            window.clear(Color::Green);
            if(Mouse::isButtonPressed(Mouse::Left)||Keyboard::isKeyPressed(Keyboard::Space))
                window.close();
        }
        else
        {
            t3.setFillColor(Color::Red);
            window.draw(sd);
        }
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
    window.setFramerateLimit(60);
    srand(time(0));
    Texture texture,shiptex,sheildtex;
    texture.loadFromFile("solderAll.png");
    sheildtex.loadFromFile("Reynos Shield.png");

    Sprite sg;
    sg.setTexture(sheildtex);



    IntRect recsourcesprite(0,0,129,181),resourcesprite(0,181,129,387);
    Sprite sp(texture,recsourcesprite);
    sp.setScale(.4f,.4f);
    sp.setOrigin(sp.getPosition().x+115,sp.getPosition().y+50);
    sp.setPosition(200.f,500.f);

    shiptex.loadFromFile("dfh45hygd.jpg");
    RectangleShape ship;
    ship.setSize(Vector2f(200.f,111.f));
    ship.setTexture(&shiptex);
    ship.setPosition(0,66);

//        Texture bultex;
//        bultex.loadFromFile("billet.jpg");

    Texture background1;
    int hp=1000;
    background1.loadFromFile("finale .jpg");


    Sprite back1(background1);

/// stone coin  all///
    Texture stonetex;
    stonetex.loadFromFile("stne.png");

    Texture tex;
    tex.loadFromFile("222-2221172_preview-coin-sprite-sheet.png");

    IntRect ectsourcesprite(0,0,310,350);
    Sprite s(tex,ectsourcesprite);
    s.setScale(.01,.01);

    Clock cl,clock,cloc,clo;

    vector<stone>stones;
    int stonetimer=0,f=-1 ;

    vector<sheild>sgs;

    vector<coin>coins;
    int coinfalltimer=0,bultimer=0,sheildtimer=0;

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
    // b1.setTexture()
    vector<bullet>bullets;

    Texture tex1,tex2,tex4,tex5;
    tex1.loadFromFile("Tau_Beas reverse t.png");
    tex2.loadFromFile("Tau_Beas reverse t.png");
    tex4.loadFromFile("mothman-transparent-adorable-3.png");
    tex5.loadFromFile("mothman-transparent-adorable-3.png");

    RectangleShape enemy1,enemy2;
    vector<RectangleShape>enemies1,enemies2;
    int enemycount=20,mlk=0;
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


    float c,v,m,p,q,r,z=-.2,o=0.0,n=0.0,h=-40;

    while(window.isOpen())
    {

        Event event;
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
        {
            sp.move(0,-10.f);
            n-=4;

        }
        if(sp.getPosition().y<=630)
        {sp.move(0,2.f);
        n-=1;
        }
        if(Keyboard::isKeyPressed(Keyboard::Down))
        {
            sp.move(0,10.f);
            n+=4;

        }
        if(Keyboard::isKeyPressed(Keyboard::Right))
        {
            sp.move(4.f,0);
            o+=4;
            if(cloc.getElapsedTime().asSeconds()>.09f)
            {
                if(recsourcesprite.left>=382)
                    recsourcesprite.left=0;
                else
                    recsourcesprite.left+=140;

                sp.setTextureRect(recsourcesprite);
                cloc.restart();

            }


        }
        if(Keyboard::isKeyPressed(Keyboard::Left))
        {
            sp.move(-4.f,0);
            o-=4;
            if(clo.getElapsedTime().asSeconds()>.09f)
            {
                if(resourcesprite.left<=0)
                    resourcesprite.left=382;
                else
                    resourcesprite.left-=127;

                sp.setTextureRect(resourcesprite);
                clo.restart();

            }

        }

        ///    update enemies    //////
        if(enemycount<40)
            enemycount++;

        if(enemycount>=40)
        {
            enemy1.setPosition(478.f,225.f);
            enemies1.push_back(RectangleShape(enemy1));

            enemy2.setPosition(877.f,225.f);
            enemies2.push_back(RectangleShape(enemy2));

//           enemy2.setPosition(1044.f,196.f);
//              enemies2.push_back(RectangleShape(enemy2));

            enemycount=-310;


        }

        ///      ship moving   ////



        if(ship.getPosition().x>=window.getSize().x-ship.getSize().x)
            dir=0;
        if(dir==0)
        {
            ship.move(-2,0);
        }
        if(ship.getPosition().x<=0)
            dir=1;
        if(dir==1)
        {
            ship.move(2,0);
        }


        ///    enemy move and shooting    ////////////




        for(size_t i=0; i<enemies1.size(); i++)
        {
            enemyloc=Vector2f(enemies1[i].getPosition());
            if(enemies1[i].getPosition().y<510)
            {
                enemies1[i].setTexture(&tex1);

            if(enemies1[i].getPosition().y<360&&enemies1[i].getPosition().y>12)
            {

                enemies1[i].move(-.3f,1.f);
            }

            else if(enemies1[i].getPosition().y>=360&&enemies1[i].getPosition().y<=406)
            {

                if(enemies1[i].getPosition().x>=545)
                    enemies1[i].move(0.f,1.3f);
                    else  enemies1[i].move(1.f,0.f);
            }
            else if(enemies1[i].getPosition().y>=406&&enemies1[i].getPosition().y<=510)
            {

                if(enemies1[i].getPosition().x<=445)
                    enemies1[i].move(0.f,1.f);
                    else enemies1[i].move(-.8f,.2);
            }}
            else
            {
                enemies1[i].setTexture(&tex4);

                ai=enemyloc-playercenter;
                p=ai.x*ai.x;
                q=ai.y*ai.y;
                r=p+q;
                ain=ai/sqrt(r);
                enemies1[i].move(-ain);
            }


        }
        for(size_t i=0; i<enemies2.size(); i++)
        {
            enemyloc=Vector2f(enemies2[i].getPosition());

         if(enemies2[i].getPosition().y>=500)
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

           else if((enemies2[i].getPosition().x>=535&&enemies2[i].getPosition().x<=1195)&&enemies2[i].getPosition().y<500)
            {
                enemies2[i].setTexture(&tex2);
                if(enemies2[i].getPosition().y>=2&&enemies2[i].getPosition().y<280)
                    enemies2[i].move(0.f,1.f);


                else if(enemies2[i].getPosition().y>=280&&enemies2[i].getPosition().y<=350)
                {
                    if(enemies2[i].getPosition().x<=736)
                        enemies2[i].move(0.f,1.f);
                    else
                        enemies2[i].move(-1.f,0.f);
                }
                else if(enemies2[i].getPosition().y>=350)
                {
                    if(enemies2[i].getPosition().x<=1400&&enemies2[i].getPosition().x>=1120)
                        enemies2[i].move(0.f,1.f);
                    else
                        enemies2[i].move(1.f,0.f);

                }
            }

        }

        ///  shooting      //////
        if(Mouse::isButtonPressed(Mouse::Left)||Keyboard::isKeyPressed(Keyboard::Space))
        {
            b1.shape.setPosition(playercenter);
            b1.currentvelocity=aimdirnorm*b1.maxspeed;
            // b1.setTexture(&bultex);
            if(bultimer<=15)
                bultimer++;
            if(bultimer==15)
            {
                bultimer=-10;
                bullets.push_back(bullet(b1));
           }
        }
        for(size_t i=0; i<bullets.size(); i++)
        {
            bullets[i].shape.move(bullets[i].currentvelocity);
///    bullet out of bounds   ///////
            if(bullets[i].shape.getPosition().x<0||bullets[i].shape.getPosition().x>window.getSize().x
                    ||bullets[i].shape.getPosition().y<554||bullets[i].shape.getPosition().y>670)
            {
                bullets.erase(bullets.begin()+i);

            }

            ///    collision  with bullet and enemy  also checking player hp ////
            for(size_t k=0; k<enemies1.size(); k++)
            {
                if(bullets[i].shape.getGlobalBounds().intersects(enemies1[k].getGlobalBounds()))
                {
                    enemies1.erase(enemies1.begin()+k);
                    bullets.erase(bullets.begin()+i);
                    score+=3;
                    break;
                }

            }

            for(size_t k=0; k<enemies2.size(); k++)
            {
                if(bullets[i].shape.getGlobalBounds().intersects(enemies2[k].getGlobalBounds()))
                {
                    enemies2.erase(enemies2.begin()+k);
                    bullets.erase(bullets.begin()+i);
                    score+=3;
                    break;
                }

            }


            ///  /         stone  collision    ////////
            for(size_t k=0; k<stones.size(); k++)
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

        ///    sheild movement     /////////////

        for(size_t i=0; i<sgs.size(); i++)
        {
            if(o>=4)
                o=4;
            if(n>=4)
                n=4;


            if(mlk>=23)
            {
                sgs.erase(sgs.begin()+i);
                mlk=0;
                break;
            }
            if(sgs[i].shape.getPosition().x<200)
            {
                sgs[i].shape.setPosition(Vector2f(200.f,sgs[i].shape.getPosition().y));
                o=0;
            }
            if(sgs[i].shape.getPosition().x>1200)
            {
                sgs[i].shape.setPosition(Vector2f(1200.f,sgs[i].shape.getPosition().y));
                o=0;
            }

            if(sgs[i].shape.getPosition().y<530)
            {
                sgs[i].shape.setPosition(Vector2f(sgs[i].shape.getPosition().x,530.f));
                n=0;
            }
            if(sgs[i].shape.getPosition().y>630)
            {
                sgs[i].shape.setPosition(Vector2f(sgs[i].shape.getPosition().x,630.f));
                n=0;
            }

            if(sgs[i].shape.getGlobalBounds().intersects(sp.getGlobalBounds()))
                sgs[i].shape.setPosition(sp.getPosition().x-80,sp.getPosition().y-30);

            sgs[i].shape.move(o,n);

            o=n=0;
            for(size_t k=0; k<enemies1.size(); k++)
            {
                if(sgs[i].shape.getGlobalBounds().intersects(enemies1[k].getGlobalBounds()))
                {
                    enemies1.erase(enemies1.begin()+k);
                    mlk+=3;
                    score+=3;
                    break;
                }
            }

            for(size_t k=0; k<enemies2.size(); k++)
            {
                if(sgs[i].shape.getGlobalBounds().intersects(enemies2[k].getGlobalBounds()))
                {
                    enemies2.erase(enemies2.begin()+k);
                    score+=3;
                    mlk+=3;
                    break;
                }
            }


            ///  /         stone  collision    ////////
            for(size_t k=0; k<stones.size(); k++)
            {
                if(sgs[i].shape.getGlobalBounds().intersects(stones[k].shape.getGlobalBounds()))
                {
                    stones.erase(stones.begin()+k);
                    score+=stones[k].hpmax;
                    mlk+=3;
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
        for(size_t i=0; i<stones.size(); i++)
        {
            stones[i].shape.move(z,5.f);
            if(stones[i].shape.getPosition().y>=650)
            {
                stones[i].shape.move(0,h);
                h+=22;
                if(h>1)
                    h=-40;
            }
            if(stones[i].shape.getPosition().y>=645&&h==-18)
                {stones.erase(stones.begin()+i);
              h=-40;  }
            if(stones[i].shape.getGlobalBounds().intersects(sp.getGlobalBounds()))
            {
                stones.erase(stones.begin()+i);
                hp-=stones[i].hp;

          }
           // cout<<h<<endl;
        }



///      update coins ///
        if(coinfalltimer<750)
            coinfalltimer++;
        if(coinfalltimer==750)
        {
            coins.push_back(coin(&tex,ship.getPosition()));
            coinfalltimer=0;
        }
        for(size_t i=0; i<coins.size(); i++)
        {
            coins[i].shape.move(0,2.f);

            if(clock.getElapsedTime().asSeconds()>.05f)
            {
                if(ectsourcesprite.left>=723)
                    ectsourcesprite.left=0;
                else
                    ectsourcesprite.left+=300;

                coins[i].shape.setTextureRect(ectsourcesprite);
                //coins[i].shape.set(0,.3f);
                clock.restart();

            }

            if(coins[i].shape.getPosition().y>=650)
                coins.erase(coins.begin()+i);
            if(coins[i].shape.getGlobalBounds().intersects(sp.getGlobalBounds()))
            {
                sgs.push_back(sheild(&sheildtex,coins[i].shape.getPosition()));
                coins.erase(coins.begin()+i);

                hp+=10;
//coins.push_back(coin(&tex,ship.getPosition()));
            }
        }



///   enemy  out of area   remove   ////////////


        for(size_t i=0; i<enemies1.size(); i++)
        {
            if(enemies1[i].getPosition().x<0||enemies1[i].getPosition().x>window.getSize().x
                    ||enemies1[i].getPosition().y<0||enemies1[i].getPosition().y>window.getSize().y)
            {
                enemies1.erase(enemies1.begin()+i);

            }
            if(sp.getGlobalBounds().intersects(enemies1[i].getGlobalBounds()))
            {
                hp--;
                break;
            }
        }
        for(size_t i=0; i<enemies2.size(); i++)
        {
            if(enemies2[i].getPosition().x<0||enemies2[i].getPosition().x>window.getSize().x
                    ||enemies2[i].getPosition().y<0||enemies2[i].getPosition().y>window.getSize().y)
            {
                enemies2.erase(enemies2.begin()+i);

            }
            if(sp.getGlobalBounds().intersects(enemies2[i].getGlobalBounds()))
            {
                hp--;
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

        if(sp.getPosition().y<530)
            sp.setPosition(Vector2f(sp.getPosition().x,530.f));

        if(sp.getPosition().y>630)
            sp.setPosition(Vector2f(sp.getPosition().x,630.f));



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
            sprintf(ara,"  %d",stones[i].hp);
            enhptext.setString(ara);
            enhptext.setPosition(stones[i].shape.getPosition().x,stones[i].shape.getPosition().y);
            window.draw(enhptext);
            window.draw(stones[i].shape);
        }
        for(size_t i=0; i<coins.size(); i++)
        {
            window.draw(coins[i].shape);
        }
        for(size_t i=0; i<sgs.size(); i++)
        {
            window.draw(sgs[i].shape);
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
    }
}


class cont
{
public:
    Sprite shape;
    cont(Texture *tex,Vector2f pos)
    {
        this->shape.setTexture(*tex);
        this->shape.setPosition(pos);
        this->shape.setScale(.1,.1);


    }


};



void g2()
{
    srand(time(0));
    int j=0,k=0,contimer=0,score=0,hp=0,rr=200,highscore;
    window.setFramerateLimit(60);
    Texture texture;
    //IntRect left(87,0,155,145),normal(0,0,85,145),up(157,0,240,145),right(241,0,320,145);

    texture.loadFromFile("GreenGoblinPromo-TASM2.png");

     Sprite sp(texture);

    sp.setOrigin(sp.getPosition().x+115,sp.getPosition().y+50);
    sp.setPosition(200.f,500.f);
    sp.setScale(.08f,.08f);
    Texture back,fir,ironman1,ironman,leaser1,leaser2,container;
    back.loadFromFile("background.jpg");
    fir.loadFromFile("fire-sprite-sheet-png-5.png");
    ironman1.loadFromFile("flat.jpg");
    //leaser1.loadFromFile("output-onlinepngtools (4).png");
    leaser2.loadFromFile("output-onlinepngtools (5).png");
    container.loadFromFile("1280-20ftStandard.png");

    Sprite sd(back),irm,lea(leaser2),le(leaser2),fire(fir);

   le.setScale(.7,.7);
    lea.setScale(.7,.7);
    fire.setPosition(-10,590);
//    imright.setPosition(1200,0);
    le.setPosition(-10,-35);
    lea.setPosition(1350,0);

    RectangleShape r;
    r.setPosition(10,480);
    r.setFillColor(Color::Red);


    freopen("highscore.txt","r",stdin);
cin>>highscore;



          Font font;
    font.loadFromFile("AGENTORANGE.TTF");
    Text text,tex,best,go;
    text.setFont(font);
    tex.setFont(font);
    best.setFont(font);
    go.setFont(font);
    text.setCharacterSize(22);
    best.setCharacterSize(22);
    tex.setCharacterSize(40);
    go.setCharacterSize(40);
    text.setFillColor(Color::Red);
    tex.setFillColor(Color::Red);
    best.setFillColor(Color::Green);
    best.setPosition(10.f,435.f);
    text.setPosition(10.f,410.f);
    go.setPosition(100.f,235.f);
    tex.setPosition(100,50);

    Vector2i starting_position,starting_positiob;
    starting_position = Mouse::getPosition( window );
    starting_positiob = Mouse::getPosition( window );
    Vector2f current_position,current_positiob;

    vector<cont>cons;

    Clock cloc,clo;
    VertexArray drawrect(LineStrip,3);
    VertexArray drawline(LineStrip,3);

    while( window.isOpen() )
    {
        Event event;
        while(window.pollEvent( event ))
        {
            if(event.type==Event::Closed)
                window.close();
            if( Keyboard::isKeyPressed(Keyboard::Escape) )
                window.close();

            if( event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left )
            {
                starting_position.x = event.mouseButton.x;
                starting_position.y = event.mouseButton.y;

            }
            if( event.type == Event::MouseMoved && Mouse::isButtonPressed(Mouse::Left) )
            {

                drawrect[0].position = Vector2f(starting_position.x,starting_position.y);
                drawrect[1].position = Vector2f(starting_position.x,starting_position.y);
                drawrect[2].position = Vector2f(event.mouseMove.x,event.mouseMove.y);

            }
            if( event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Right )
            {
                starting_positiob.x = event.mouseButton.x;
                starting_positiob.y = event.mouseButton.y;

            }

            if( event.type == Event::MouseMoved && Mouse::isButtonPressed(Mouse::Right) )
            {

                drawline[0].position = Vector2f(starting_positiob.x,starting_positiob.y);
                drawline[1].position = Vector2f(starting_positiob.x,starting_positiob.y);
                drawline[2].position = Vector2f(event.mouseMove.x,event.mouseMove.y);

            }
        }

        drawrect[1].color=Color::Red;
        drawrect[2].color=Color::Red;

        drawline[1].color=Color::Green;
        drawline[2].color=Color::Green;

        if(Keyboard::isKeyPressed(Keyboard::Space)||Mouse::isButtonPressed(Mouse::Left))
        {
            irm.setTexture(ironman1);

        }
        else
        sp.setTexture(texture);
        if(Keyboard::isKeyPressed(Keyboard::Left))
        {
           // sp.setTextureRect(left);
            j-=4;
            sp.move(j,0);
            j=0;
        }

        if(Keyboard::isKeyPressed(Keyboard::Right))
        {
            //sp.setTextureRect(right);
            j+=4;
            sp.move(j,0);
            j=0;
        }

        if(Keyboard::isKeyPressed(Keyboard::Up))
        {
            //sp.setTextureRect(up);
            k-=12;
            if(k<12)
            sp.move(0,k);

            k=0;
        }

        if(Keyboard::isKeyPressed(Keyboard::Down))
        {

            if(sp.getGlobalBounds().intersects(drawrect.getBounds()))
            {
                k=0;
            }
            else if(sp.getGlobalBounds().intersects(drawline.getBounds()))
            {
                k=0;
            }
            else
                k+=8;

            sp.move(0,k);
            k=0;
        }

        if(!sp.getGlobalBounds().intersects(drawrect.getBounds())&&!sp.getGlobalBounds().intersects(drawline.getBounds()))
        {
            k+=3;
            sp.move(0,k);
            k=0;
        }
        le.rotate(1.f);
        lea.rotate(1.f);
        if(contimer<30)
            contimer++;
        if(contimer>=30){
        cons.push_back(cont(&container,Vector2f((rand()%500)+300,-50)));
score++;
        contimer=-50;
        }
        for(size_t i=0;i<cons.size();i++)
        {
            if(cons[i].shape.getPosition().x>600)
            cons[i].shape.move(-1,6.f);
            else
                cons[i].shape.move(1,6.f);

            if(cons[i].shape.getGlobalBounds().intersects(sp.getGlobalBounds()))
            {
                k+=6;
                rr-=1;
                if(cons[i].shape.getPosition().x>600)
                j-=1;
                else
                    j+=1;
            }
        }

        if(rr<=0)
        {
            go.setString("game over");

            if(cloc.getElapsedTime().asSeconds()>=9.f)
            {main_menu();
            cloc.restart();
        }
        }
 if(score>highscore)
        {highscore=score;
      freopen("highscore.txt","w",stdout);
        }
        char a[100];
        sprintf(a,"score  %d ",score);
        text.setString(a);
        char bb[100];
        sprintf(bb,"Best  %d ",highscore);
        best.setString(bb);

    irm.setPosition(sp.getPosition().x+50,sp.getPosition().y);
    irm.setScale(.08f,.08f);

        if(sp.getPosition().y>=600)
            sp.setPosition(sp.getPosition().x,600);
if(sp.getPosition().y==600)
rr--;
  r.setSize(Vector2f(30,rr));
        window.draw(sd);
   for(size_t i=0;i<cons.size();i++)
            {
                window.draw(cons[i].shape);

            }
            if(Keyboard::isKeyPressed(Keyboard::Space)||Mouse::isButtonPressed(Mouse::Left))
        {
            window.draw(irm);
        }
        else
        window.draw(sp);

        if(lea.getGlobalBounds().intersects(sp.getGlobalBounds())||le.getGlobalBounds().intersects(sp.getGlobalBounds())
    ||lea.getGlobalBounds().intersects(irm.getGlobalBounds())||le.getGlobalBounds().intersects(irm.getGlobalBounds()))
            {
             rr-=2;

             tex.setString("fatal error");
            window.draw(tex);
            }
        //cout<<rr<<endl;
        window.draw(text);
        window.draw(drawline);
        window.draw(le);
        window.draw(best);
        window.draw(lea);
        window.draw(fire);

        if(rr<=200&&rr>0)
        window.draw(r);
        window.draw(go);
        window.draw(drawrect);
        window.display();
            window.clear();

    }


}

