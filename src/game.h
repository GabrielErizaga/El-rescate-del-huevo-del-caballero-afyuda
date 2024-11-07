#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "enemigo.h"
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <vector>
#include "Jefe.h"
#include "pj.h"
#include "Item.h"
#include "mapa.h"
#include "enemigoSlime.h"
#include "itemPuntos.h"
//Clase que funciona como el game engine.

class game{
    public:
    //Constructor y destructor
        game();
        virtual ~game();
    //Nexo entre game y main:
        const bool isRunning() const;
    //Funciones:
        bool verificarColisionEnemigo(sf::RectangleShape hitbox);
        bool verificarColisionEspada(pj& p,sf::RectangleShape hitbox);
        void updateEvent();
        void update();
        void render();
        void setEnemies();
        void updateEnemies();
        void enemiesResize();
        void setLevel();
    private:
    //Variables que solo la clase game puede tener acceso:

        mapa mapaTest;
        sf::RenderWindow window{};
        sf::Event evento;
        sf::View camara;
        pj ejemplo;
        Item corazon;
        itemPuntos star;
        int contador;
        sf::Font font;
        sf::Text textoTest;
        float limiteCamaraIzq=400;
        float limiteCamaraDer=1200;
        Jefe osomaloso;
        std::vector<enemigoSlime> skl;
        bool nivel1=false;
        bool nivel2=false;

};

#endif // GAME_H_INCLUDED
