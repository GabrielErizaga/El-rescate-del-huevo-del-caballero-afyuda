#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include "enemigoEsqueleto.h"
enemigoEsqueleto::enemigoEsqueleto()
{


    j_texture.loadFromFile("assets/Characters(100x100)/Werebear/Werebear/Werebear.png");
    j_sprite.setTexture(j_texture);
    j_sprite.setTextureRect({0,0,130,130});
    j_sprite.setOrigin(j_sprite.getGlobalBounds().width,j_sprite.getGlobalBounds().height);
    j_hitbox.setSize({60,30});
    j_hitbox.setFillColor(sf::Color::Magenta);
    j_sprite.setPosition(1050,250);
    j_vida=500;


}
void enemigoEsqueleto::update(int LimiteA, int LimiteB){

j_velocity={};

if(j_velocity.x==0&& j_velocity.y==0)
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
        j_sprite.setTextureRect({130 + (int)_frame*130,130,130,130}); //Ancho y Alto del Personaje,70x65.
        if(_frame>=6)
        {
            _frame=0;
        }

    }






    if(j_velocity.x < 0)
    {
       j_sprite.setScale(-1,1);//setScale es el encargado del efecto visual para que el personaje se de vuelta
    }
    else if(j_velocity.x > 0 )
    {
        j_sprite.setScale(1,1);
    }



  // Verificar si el objeto ha llegado a los límites y cambiar la dirección suavemente
if (j_hitbox.getGlobalBounds().left <= LimiteA) {
    _direccion = 1; // Cambiar dirección hacia la derecha
} else if (j_hitbox.getGlobalBounds().left + j_hitbox.getGlobalBounds().width >= LimiteB) {
    _direccion = -1; // Cambiar dirección hacia la izquierda
}
    j_sprite.move(j_velocity);

    j_hitbox.setPosition(j_sprite.getGlobalBounds().left + 30, j_sprite.getGlobalBounds().top + 30 );

}


bool enemigoEsqueleto::isAlive(){
if(j_vida > 0  ){ return true;   }
 else{return false;    }


}
void enemigoEsqueleto::setSpritePosition(float x,float y){
    j_sprite.setPosition(x,y);
}
void enemigoEsqueleto::danioRecivido(int danio){

j_vida=j_vida-danio;

}
void enemigoEsqueleto::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    //  `j_sprite` es el sprite principal del enemigoEsqueleto
    target.draw(j_hitbox);
    target.draw(j_sprite, states);
}

//enemigoEsqueleto::~enemigoEsqueleto()
//{
//    //dtor
//}
