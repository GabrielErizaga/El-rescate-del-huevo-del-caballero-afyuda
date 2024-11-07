#ifndef COLISIONABLE_H_INCLUDED
#define COLISIONABLE_H_INCLUDED
#include <SFML/Graphics.hpp>
//Clase encargada de administar las colisiones
class colisionable{

public:
    virtual sf::RectangleShape getHitbox()const=0;
    bool isCollision(colisionable& col) const;
};


#endif // COLISIONABLE_H_INCLUDED
