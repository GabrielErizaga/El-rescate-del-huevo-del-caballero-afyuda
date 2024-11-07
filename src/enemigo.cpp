#include <iostream>
#include "enemigo.h"


enemigo::enemigo()
{

    _textureE.loadFromFile("assets/Characters(100x100)/Slime/Slime/Slime.png");
    e_sprite.setTexture(_textureE);
    e_sprite.setTextureRect({0,0,130,130});
    e_sprite.setOrigin(e_sprite.getGlobalBounds().width/2, e_sprite.getGlobalBounds().height);
    en_hitbox.setSize({60,30});
    en_hitbox.setFillColor(sf::Color::Yellow);
    e_sprite.setPosition(500,600);
    e_vida=50;


}
void enemigo::respawn(){
    e_sprite.setPosition(std::rand()%700+e_sprite.getGlobalBounds().width,std::rand() % 500+e_sprite.getGlobalBounds().height);
    en_hitbox.setPosition(e_sprite.getGlobalBounds().left, e_sprite.getGlobalBounds().top);
}
 void enemigo::muerte(){



        _frame2 += 0.15;
        if (e_sprite.getScale().x == -4 && _frame2 > 2) {
            en_hitbox.setPosition(e_sprite.getGlobalBounds().left + 40, e_sprite.getGlobalBounds().top + 60);
        } else if (_frame2 > 2) {
            en_hitbox.setPosition(en_hitbox.getGlobalBounds().left + 55, e_sprite.getGlobalBounds().top + 60);
        }
        e_velocity = {0, 0};
        e_sprite.setTextureRect({139 + (int)_frame2 * 130, 390, 130, 130});
        if (_frame2 >= 4) {
            _frame2 = 0;
        en_hitbox.setPosition(-50, -50);
        e_sprite.setPosition(-50,-50);
        }




    }

 bool enemigo::isAlive(){
 if(e_vida > 0  ){ return true;   }
 else{return false;    }




 }
    void enemigo::danioRecibido(int danio){

    e_vida=e_vida-danio;


    }



void enemigo::update()
{
    bool ban=true;
    e_velocity= {};




    if(e_velocity.x==0&&e_velocity.y==0)
    {
        _frame+=0.009;
        e_sprite.setTextureRect({0 + (int)_frame*130,0,130,130}); //Ancho y Alto del Personaje,70x65.
        if(_frame>=4)
        {
            _frame=0;
        }
    }



    if(e_velocity.x==0&&e_velocity.y==0 )
    {



        _frame+=0.2;
        e_velocity.x=-2 * _direccion;
        e_sprite.setTextureRect({130 + (int)_frame*130,130,130,130}); //Ancho y Alto del Personaje,70x65.
        if(_frame>=6)
        {
            _frame=0;
        }

    }

    if(en_hitbox.getGlobalBounds().left < 0   )
    {

        e_sprite.setPosition(e_sprite.getPosition().x + 4, e_sprite.getPosition().y);
        en_hitbox.setPosition(5 + e_sprite.getGlobalBounds().left + 66, e_sprite.getGlobalBounds().top + 64);


        _direccion=_direccion*-1;



    }

    if (en_hitbox.getGlobalBounds().left + en_hitbox.getGlobalBounds().width > 800)
    {
        e_sprite.setPosition(800 - (e_sprite.getGlobalBounds().width - 103), e_sprite.getPosition().y);
        en_hitbox.setPosition(5 + e_sprite.getGlobalBounds().left + 66, e_sprite.getGlobalBounds().top + 64);

        _direccion=_direccion*-1;

    }


    if(e_velocity.x < 0)
    {
        e_sprite.setScale(-1,1);//setScale es el encargado del efecto visual para que el personaje se de vuelta
    }
    else if(e_velocity.x > 0 )
    {
        e_sprite.setScale(1,1);
    }


    e_sprite.move(e_velocity);



    en_hitbox.setPosition( e_sprite.getGlobalBounds().left + 30, e_sprite.getGlobalBounds().top + 50 );



}
sf::RectangleShape enemigo::getHitbox()const
{
    return en_hitbox;
}

void enemigo::draw(sf::RenderTarget& target, sf::RenderStates state)const
{
    target.draw(en_hitbox);
    target.draw(e_sprite);
}

void enemigo::setLimit(int posX, int posY, int posA,int posB){
    e_vida=50;
    e_sprite.setPosition(sf::Vector2f(posX,posY));
    limitA=posA;
    limitB=posB;
    e_sprite.setOrigin(e_sprite.getGlobalBounds().width/2, e_sprite.getGlobalBounds().height);
}


//
//enemigo::~enemigo()
//{
//    //dtor
//}
