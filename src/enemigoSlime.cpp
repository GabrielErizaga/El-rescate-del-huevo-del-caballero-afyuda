#include "enemigoSlime.h"


enemigoSlime::enemigoSlime()
{
    _textureSlm.loadFromFile("assets/Characters(100x100)/Slime/Slime/Slime.png");
    slm_sprite.setTexture(_textureSlm);
    slm_sprite.setTextureRect({0,0,130,130});
    /*slm_sprite.setOrigin(slm_sprite.getGlobalBounds().width/2, slm_sprite.getGlobalBounds().height);*/
    slm_hitbox.setSize({60,30});
    slm_hitbox.setFillColor(sf::Color::Yellow);
    slm_vida=50;
}

enemigoSlime::~enemigoSlime()
{
    //dtor
}

void enemigoSlime::respawn(){
    slm_sprite.setPosition(std::rand()%700+slm_sprite.getGlobalBounds().width,std::rand() % 500+slm_sprite.getGlobalBounds().height);
    slm_hitbox.setPosition(slm_sprite.getGlobalBounds().left, slm_sprite.getGlobalBounds().top);
}

 bool enemigoSlime::muerte(){
    if(slm_vida<=0){
        return true;
    }else return false;
    }

 bool enemigoSlime::isAlive(){
 if(slm_vida > 0  ){ return true;   }
 else{return false;}




 }
    void enemigoSlime::danioRecibido(int danio){
        _frame3 += 0.1f;


         slm_sprite.setTextureRect({0 + (int)_frame3 * 130, 520 , 130, 130});
        if (_frame3 >= 4) {
            _frame3 = 0;
        slm_vida=slm_vida-danio;
        }
    slm_vida=slm_vida-danio;


    }



void enemigoSlime::update()
{
    bool ban=true;
    slm_velocity= {};




    if(slm_velocity.x==0&&slm_velocity.y==0)
    {
        _frame+=0.009;
        slm_sprite.setTextureRect({0 + (int)_frame*130,0,130,130}); //Ancho y Alto del Personaje,70x65.
        if(_frame>=4)
        {
            _frame=0;
        }
    }



    if(slm_velocity.x==0&&slm_velocity.y==0 )
    {



        _frame+=0.2;
        slm_velocity.x=-2 * _direccion;
        slm_sprite.setTextureRect({0 + (int)_frame*130,130,130,130}); //Ancho y Alto del Personaje,70x65.
        if(_frame>=6)
        {
            _frame=0;
        }

    }
        if(muerte()){
         _frame2 += 0.05;
        slm_velocity = {0, 0};
        slm_sprite.setTextureRect({0 + (int)_frame2 * 130, 650, 130, 130});
        if (_frame2 >= 4) {
            _frame2 = 0;
        slm_hitbox.setPosition(-50, -50);
        slm_sprite.setPosition(-50,-50);
        }

    }

    if(slm_hitbox.getGlobalBounds().left < limitA)
    {

        slm_sprite.setPosition(slm_sprite.getPosition().x + 4, slm_sprite.getPosition().y);
        slm_hitbox.setPosition(5 + slm_sprite.getGlobalBounds().left + 66, slm_sprite.getGlobalBounds().top + 64);


        _direccion=_direccion*-1;



    }

    if (slm_hitbox.getGlobalBounds().left + slm_hitbox.getGlobalBounds().width > limitB)
    {
        slm_sprite.setPosition(limitB - (slm_sprite.getGlobalBounds().width - 103), slm_sprite.getPosition().y);
        slm_hitbox.setPosition(5 + slm_sprite.getGlobalBounds().left + 66, slm_sprite.getGlobalBounds().top + 64);

        _direccion=_direccion*-1;
    }


    if(slm_velocity.x < 0)
    {
        slm_sprite.setScale(-1,1);//setScale es el encargado del efecto visual para que el personaje se de vuelta
    }
    else if(slm_velocity.x > 0 )
    {
        slm_sprite.setScale(1,1);
    }


    slm_sprite.move(slm_velocity);



    slm_hitbox.setPosition( slm_sprite.getGlobalBounds().left + 30, slm_sprite.getGlobalBounds().top + 50 );



}
sf::RectangleShape enemigoSlime::getHitbox()const
{
    return slm_hitbox;
}

void enemigoSlime::draw(sf::RenderTarget& target, sf::RenderStates state)const
{
    target.draw(slm_hitbox);
    target.draw(slm_sprite);
}



/*void enemigoSlime::setSpritePosition(int posicionX, int posicionY){
    slm_sprite.setPosition(posicionX,posicionY);
}*/

void enemigoSlime::setSpritePosition(int posX, int posY, int posA,int posB){
    slm_vida=50;
    slm_sprite.setPosition(sf::Vector2f(posX,posY));
    limitA=posA;
    limitB=posB;
    slm_sprite.setOrigin(slm_sprite.getGlobalBounds().width/2, slm_sprite.getGlobalBounds().height);
}
