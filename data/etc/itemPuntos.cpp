#include <stdlib.h>
#include "itemPuntos.h"

//sf::FloatRect itemPuntos::getBounds() const{
//    return _spriteP.getGlobalBounds();
//}


sf::RectangleShape itemPuntos::getHitbox()const{
    return p_hitbox;
}

void itemPuntos::respawn(mapa& _objetoMapa){
    _spriteP.setPosition(std::rand()%1400+_spriteP.getGlobalBounds().width,std::rand() % 400+_spriteP.getGlobalBounds().height);
    p_hitbox.setPosition(_spriteP.getGlobalBounds().left, _spriteP.getGlobalBounds().top);
    if(_objetoMapa.verificarColision(p_hitbox)==true){
    while(_objetoMapa.verificarColision(p_hitbox)==true){
    _spriteP.setPosition(std::rand()%1500+_spriteP.getGlobalBounds().width,std::rand() % 400+_spriteP.getGlobalBounds().height);
    p_hitbox.setPosition(_spriteP.getGlobalBounds().left, _spriteP.getGlobalBounds().top);
    }

}
}
void itemPuntos::draw(sf::RenderTarget& target, sf::RenderStates state)const{
       target.draw(p_hitbox,state);
        target.draw(_spriteP, state);
}

bool itemPuntos::getActive(){
    return activo;
}

void itemPuntos::setActive(bool e){
    activo=e;
}

itemPuntos::itemPuntos()
{
    //Esto es provisional, deberiamos optimizarlo para que podamos elegir cual textura queremos usar
    //Y que solo tengamos que enviar la direccion de la imagen
    _textureP.loadFromFile("data/images/coinexample.png");
    _spriteP.setTexture(_textureP);
    _spriteP.setOrigin(_spriteP.getGlobalBounds().width/2, _spriteP.getGlobalBounds().height);
    p_hitbox.setSize({_spriteP.getGlobalBounds().getSize()});
     p_hitbox.setFillColor(sf::Color::Green);

    //ctor
}
