#include "game.h"


game::game() : mapaTest("data/maps/nivel2_mapa.png"), window(sf::VideoMode(1600, 600), "El rescate del huevo del caballero",sf::Style::Default) {
    window.setFramerateLimit(60);
}

game::~game(){}

const bool game::isRunning() const {

    return window.isOpen();

}

void game::updateEvent(){
    while (window.pollEvent(evento)){
            if (evento.type == sf::Event::Closed){
                window.close();
        }
}
}
//Toda las verificaiones y los updates de cada objeto van acá
void game::update(){
    updateEvent();
    if(corazon.getActive()==false){
       corazon.respawn();
       corazon.setActive(true);
    }
    ejemplo.update(mapaTest);
    slime.update();
    if(ejemplo.isCollision(corazon) ) {
            ejemplo.curar(25);
            corazon.setActive(false);
        }
        if(ejemplo.isCollision(slime)){
            if(ejemplo.isAlive()==false){
                ejemplo.muerte();
            }else{ejemplo.danioRecibido(25);
                   //ejemplo.respawn();             }
        }
    }
        if( ejemplo.getHitboxE().getGlobalBounds().intersects(slime.getHitbox().getGlobalBounds()) and ejemplo.getBan()){
            if(slime.isAlive()==false){
                slime.muerte();
            }else{slime.danioRecibido(25);}


        }

}

//Todas las visualizaciones
void game::render(){
        window.clear();
        mapaTest.dibujar(window);
        window.draw(slime);
        window.draw(ejemplo);
        window.draw(corazon);
        window.display();

}
