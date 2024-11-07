#ifndef ITEMPUNTOS_H_INCLUDED
#define ITEMPUNTOS_H_INCLUDED
#include <SFML/Graphics.hpp>
#include "colisionable.h"
#include "inc.h"

class itemPuntos : public sf::Drawable, public colisionable{
    public:
        void update();//Metodo para actualizar la posicion del personaje
        void draw(sf::RenderTarget& target, sf::RenderStates state)const override;//Dibuja al personaje
        void respawn(mapa& _objetoMapa);
//        sf::FloatRect getBounds()const override;
        sf::RectangleShape getHitbox()const override;
        itemPuntos();
        bool getActive();
        void setActive(bool e);
    protected:

    private:
        sf::Sprite _spriteP;
        sf::Texture _textureP;
        sf::RectangleShape p_hitbox;
        bool activo=false;
};

#endif // ITEMPUNTOS_H_INCLUDED
