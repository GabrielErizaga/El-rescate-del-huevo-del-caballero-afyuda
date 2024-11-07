#ifndef ENEMIGOESQUELETO_H_INCLUDED
#define ENEMIGOESQUELETO_H_INCLUDED
#include "inc.h"

class enemigoEsqueleto : public sf::Drawable
{
    public:
        enemigoEsqueleto();
    void update(int LimiteA, int LimiteB );

       void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
//    sf::RectangleShape getHitbox()const override;
    bool isAlive();
    void muerte();
    void danioRecivido(int danio);
    void setSpritePosition(float x,float y);


    private:

        sf::RectangleShape j_hitbox;
        sf::RectangleShape _hitbox;
        sf::Sprite j_sprite;
        sf::Texture j_texture;
        sf::Vector2f j_velocity={};
        int _direccion=-1;
        float  _frame=0;
        float j_vida;
};


#endif // ENEMIGOESQUELETO_H_INCLUDED
