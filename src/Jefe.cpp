#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include "Jefe.h"

Jefe::Jefe()
{
    _texturej.loadFromFile("assets/Characters(100x100)/Werebear/Werebear/Werebear.png");
    j_sprite.setTexture(_texturej);
    j_sprite.setTextureRect({0,0,130,130});
    /*j_sprite.setOrigin(j_sprite.getGlobalBounds().width/2, j_sprite.getGlobalBounds().height);*/
    j_hitbox.setSize({60,30});
    j_hitbox.setFillColor(sf::Color::Yellow);
    j_vida=50;
}

Jefe::~Jefe()
{
    //dtor
}

void Jefe::respawn(){
    j_sprite.setPosition(std::rand()%700+j_sprite.getGlobalBounds().width,std::rand() % 500+j_sprite.getGlobalBounds().height);
    j_hitbox.setPosition(j_sprite.getGlobalBounds().left, j_sprite.getGlobalBounds().top);
}


 bool Jefe::muerte(){
    if(j_vida<=0){
        return true;
    }else return false;
    }

 bool Jefe::isAlive(){
 if(j_vida > 0  ){ return true;   }
 else{return false;}




 }
    void Jefe::danioRecibido(int danio){
        _frame3 += 0.1f;


         j_sprite.setTextureRect({0 + (int)_frame3 * 130, 520 , 130, 130});
        if (_frame3 >= 4) {
            _frame3 = 0;
        j_vida=j_vida-danio;
        }
    j_vida=j_vida-danio;


    }



void Jefe::update()
{
    bool ban=true;
    j_velocity= {};




    if(j_velocity.x==0&&j_velocity.y==0)
    {
        _frame+=0.009;
        j_sprite.setTextureRect({0 + (int)_frame*130,0,130,130}); //Ancho y Alto del Personaje,70x65.
        if(_frame>=4)
        {
            _frame=0;
        }
    }



    if(j_velocity.x==0&&j_velocity.y==0 )
    {



        _frame+=0.2;
        j_velocity.x=-2 * _direccion;
        j_sprite.setTextureRect({0 + (int)_frame*130,130,130,130}); //Ancho y Alto del Personaje,70x65.
        if(_frame>=6)
        {
            _frame=0;
        }

    }
        if(muerte()){
         _frame2 += 0.05;
        j_velocity = {0, 0};
        j_sprite.setTextureRect({0 + (int)_frame2 * 130, 650, 130, 130});
        if (_frame2 >= 4) {
            _frame2 = 0;
        j_hitbox.setPosition(-50, -50);
        j_sprite.setPosition(-50,-50);
        }

    }

    if(j_hitbox.getGlobalBounds().left < limitA)
    {

        j_sprite.setPosition(j_sprite.getPosition().x + 4, j_sprite.getPosition().y);
        j_hitbox.setPosition(5 + j_sprite.getGlobalBounds().left + 66, j_sprite.getGlobalBounds().top + 64);


        _direccion=_direccion*-1;



    }

    if (j_hitbox.getGlobalBounds().left + j_hitbox.getGlobalBounds().width > limitB)
    {
        j_sprite.setPosition(limitB - (j_sprite.getGlobalBounds().width - 103), j_sprite.getPosition().y);
        j_hitbox.setPosition(5 + j_sprite.getGlobalBounds().left + 66, j_sprite.getGlobalBounds().top + 64);

        _direccion=_direccion*-1;
    }


    if(j_velocity.x < 0)
    {
        j_sprite.setScale(-1,1);//setScale es el encargado del efecto visual para que el personaje se de vuelta
    }
    else if(j_velocity.x > 0 )
    {
        j_sprite.setScale(1,1);
    }


    j_sprite.move(j_velocity);



    j_hitbox.setPosition( j_sprite.getGlobalBounds().left + 30, j_sprite.getGlobalBounds().top + 50 );



}
sf::RectangleShape Jefe::getHitbox()const{
    return j_hitbox;
}

void Jefe::draw(sf::RenderTarget& target, sf::RenderStates state)const
{
    target.draw(j_hitbox);
    target.draw(j_sprite);
}



/*void Jefe::setSpritePosition(int posicionX, int posicionY){
    j_sprite.setPosition(posicionX,posicionY);
}*/

void Jefe::setSpritePosition(int posX, int posY, int posA,int posB){
    j_vida=50;
    j_sprite.setPosition(sf::Vector2f(posX,posY));
    limitA=posA;
    limitB=posB;
    j_sprite.setOrigin(j_sprite.getGlobalBounds().width/2, j_sprite.getGlobalBounds().height);
}
