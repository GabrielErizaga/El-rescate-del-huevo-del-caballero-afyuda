#ifndef JEFE_H
#define JEFE_H
#include "inc.h"
class Jefe : public sf::Drawable, public colisionable
{
     public:
        Jefe();
        void update();
        void draw(sf::RenderTarget& target, sf::RenderStates state)const override;
        void respawn();
        bool muerte();
        sf::RectangleShape getHitbox()const override;
        bool isAlive();
        void danioRecibido(int danio);
        /*void setSpritePosition(int posicionX, int posicionY);*/
        virtual ~Jefe();
        void setSpritePosition(int posX, int posY,int posA,int posB);
    protected:

    private:
    sf::RectangleShape j_hitbox;
    int _direccion=-1;
    sf::Sprite j_sprite;
    sf::Texture _texturej;
    sf::Vector2f j_velocity={0,0};
    float _frame=0;
    float _frame2=0;
    float _frame3=0;
    int j_vida;
    int limitA=300;
    int limitB=400;
    bool _life;
};

#endif // JEFE_H
