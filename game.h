#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "enemigo.h"
#include <stdlib.h>
#include <iostream>
#include "data/characters/pj.h"
#include "data/etc/Item.h"
#include "src/mapa.h"

//Clase que funciona como el game engine.

class game{
    private:
    //Variables que solo la clase game puede tener acceso:
        sf::RenderWindow window{};
        sf::Event evento;
        mapa mapaTest;
        enemigo slime;
        pj ejemplo;
        Item corazon;
    public:
    //Constructor y destructor
        game();
        virtual ~game();
    //Nexo entre game y main:
        const bool isRunning() const;
    //Funciones:
        void updateEvent();
        void update();
        void render();
};

#endif // GAME_H_INCLUDED
