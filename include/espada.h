#ifndef ESPADA_H
#define ESPADA_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "colisionable.h"

class espada: public colisionable, public pj
{  private:

    sf::RectangleShape e_hitbox;
    public:
        void update();
    espada();
 sf::RectangleShape getHitbox();



};

#endif // ESPADA_H
