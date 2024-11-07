#ifndef MAPA_H
#define MAPA_H
#include "inc.h"


class mapa  {
public:
    // Constructor que carga el mapa
    mapa();
    ~mapa();
    // Metodo para generar la estructura
    bool cargarEstructura();
    // Método para dibujar el mapa en la ventana de SFML
    void dibujar(sf::RenderWindow& ventana);
    // Método para verificar la colisión con un punto

    // Metodo para crear una hitbox
    bool cargarHitbox(int vecPos,float w,float h,float x, float y);
    // Metodo para dibujar hitbox
    void dibujarHitbox(sf::RenderWindow& ventana);
    // Metodo para verificar la colision
    bool verificarColision(const sf::RectangleShape& objeto);
    // Metodo para cambiar el nivel
    void setNivel(int nivel);
    // Metodo para cambiar la textura del mapa
    void setTextMapa(int nivel);
    // Metodos para cargar la estructura de los niveles
    bool cargarNivel1();
    bool cargarNivel2();
    bool cargarNivel3();
    // Metodo para setearle dinamicamente tamaño al vector
    void inicializarVector(int tam);
    int getNivel();
    void destructor();

private:
    sf::Sprite _Smapa;        // Sprite del mapa
    sf::Texture _nivel1;      // Textura nivel 1
    sf::Texture _nivel2;      // Textura nivel 2
    sf::Texture _nivel3;      // Textura nivel 3

    int _nivel=1;
    std::vector<sf::RectangleShape> _hitbox;  // Terreno
    bool _dibujado=false;     // Booleano para solo dibujar una vez todas las hitbox
    void cargarMapa(); // Método para cargar el mapa
};

#endif // MAPA_H
