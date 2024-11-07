#include "mapa.h"
#include <iostream>

// Implementación del constructor
mapa::mapa() {
    // Cargar la textura
    if (!_nivel1.loadFromFile("data/maps/nivel1_mapa.png")) {
        std::cerr << "Error al cargar el archivo del Mapa" << std::endl;
    }
    if(!_nivel2.loadFromFile("data/maps/nivel2_mapa.png")){
        std::cout << "Error al cargar el archivo del Mapa 2" << std::endl;
    }
    // Valor del vector cambiado
    _hitbox.resize(35);
    cargarEstructura();
    cargarMapa();
}

mapa::~mapa(){
    _hitbox.clear();
}

// Implementación del método para cargar el mapa
void mapa::cargarMapa() {
    switch(_nivel){
    case 1:
        _Smapa.setTexture(_nivel1);
        break;
    case 2:
        _Smapa.setTexture(_nivel2);
        break;
    }
}
// Implementacion del metodo para cambiar la textura del mapa segun el nivel
void mapa::setTextMapa(int numero){
    switch(numero){
case 1:
    // Desarrollo del cambio de textura
    _nivel=1;
    if(!_nivel1.loadFromFile("data/maps/nivel1_mapa.png")){
        std::cout << "Error al cargar el archivo del Mapa 1" << std::endl;
    }
    cargarMapa();
    break;
case 2:
    // Desarrollo del cambio de textura
    _nivel=2;
    if(!_nivel2.loadFromFile("data/maps/nivel2_mapa.png")){
        std::cout << "Error al cargar el archivo del Mapa 2" << std::endl;
    }
    cargarMapa();
    break;
case 3:
    // Desarrollo del cambio de textura
    if(!_nivel3.loadFromFile("data/maps/nivel3_mapa.png")){
        std::cout << "Error al cargar el archivo del Mapa 3" << std::endl;
    }
    cargarMapa();
    break;
    }
}
// Implementación del método para configurar la estructura de la hitbox
bool mapa::cargarEstructura() {
    //Crear la estructura del terreno segun el nivel
    switch(_nivel){
case 1:
    setTextMapa(1);
    cargarNivel1();
    break;
case 2:
    setTextMapa(2);
    cargarNivel2();
    break;
case 3:
    break;
    }


    return true;
}
// Metodo para cargar hitboxes del nivel 1
bool mapa::cargarNivel1(){

      inicializarVector(25);
      cargarHitbox(0,345.0f, 75.0f, 0.0f, 146.0f);
      cargarHitbox(1,48.0f,101.0f,310.0f,221.0f);
      cargarHitbox(2,229.0f,26.0f,110.0f,326.0f);
      cargarHitbox(3,75.0f,83.0f,341.0f,325.0f);
      cargarHitbox(4,345.0f,45.0f,449.0f,209.0f);
      cargarHitbox(5,115.0f,13.0f,756.0f,77.0f);
      cargarHitbox(6,11.0f,120.0f,798.0f,90.0f);
      cargarHitbox(7,175.0f,26.0f,799.0f,195.0f);
      cargarHitbox(8,72.0f,34.0f,508.0f,366.0f);
      cargarHitbox(9,72.0f,34.0f,654.0f,366.0f);
      cargarHitbox(10,365.0f,17.0f,325.0f,522.0f);
      cargarHitbox(11,70.0f,39.0f,399.0f,483.0f);
      cargarHitbox(12,199.0f,27.0f,122.0f,557.0f);
      cargarHitbox(13,117.0f,30.0f,2.0f,529.0f);
      cargarHitbox(14,27.0f,113.0f,1.0f,415.0f);
      cargarHitbox(15,47.0f,29.0f,29.0f,419.0f);//
      cargarHitbox(16,213.0f,40.0f,694.0f,505.0f);
      cargarHitbox(17,167.0f,40.0f,798.0f,337.0f);
      cargarHitbox(18,71.0f,13.0f,971.0f,194.0f);
      cargarHitbox(19,258.0f,53.0f,1042.0f,194.0f);
      cargarHitbox(20,125.0f,23.0f,1306.0f,234.0f);
      cargarHitbox(21,161.0f,51.0f,1439.0f,195.0f);
      cargarHitbox(22,19.0f,141.0f,912.0f,387.0f);
      cargarHitbox(23,302.0f,22.0f,1038.0f,405.0f);
      cargarHitbox(24,207.0f,131.0f,1393.0f,375.0f);
      return true;
}
// Metodo para cargar hitboxes del nivel 2
bool mapa::cargarNivel2(){
    inicializarVector(35);
    cargarHitbox(0,195.0f, 80.0f, 40.0f, 422.0f);
    cargarHitbox(1,40.0f, 10.0f, 265.0f, 415.0f);
    _hitbox[1].setRotation(135.f);
    cargarHitbox(2,180.f,50.f,260.f,395.f);
    cargarHitbox(3,40.0f, 10.0f, 440.0f, 409.0f);
    _hitbox[3].setRotation(45.f);
    cargarHitbox(4,180.f,50.f,465.f,420.f);
    cargarHitbox(5,40.0f, 10.0f, 640.0f, 440.0f);
    _hitbox[5].setRotation(45.f);
    cargarHitbox(6,70.0f, 8.0f, 420.0f, 310.0f);
    cargarHitbox(7,125.0f, 8.0f, 570.0f, 250.0f);
    cargarHitbox(8, 70.0f, 8.0f, 530.0f, 105.0f);
    cargarHitbox(9, 100.0f, 90.0f, 380.0f, 110.0f);
    cargarHitbox(10,35.0f, 10.0f, 475.0f, 125.0f);
    _hitbox[10].setRotation(45.f);
    cargarHitbox(11,20.0f, 10.0f, 355.0f, 90.0f);
    _hitbox[11].setRotation(45.f);
    cargarHitbox(12,100.0f, 120.0f, 260.0f, 90.0f);
    cargarHitbox(13,25.0f, 10.0f, 265.0f, 105.f);
    _hitbox[13].setRotation(135.f);
    cargarHitbox(14,40.0f, 90.0f, 195.0f, 115.0f);
    cargarHitbox(15,25.0f, 10.0f, 195.0f, 120.f);
    _hitbox[15].setRotation(135.f);
    cargarHitbox(16,165.0f, 10.0f, 0.0f, 160.0f);
    cargarHitbox(17,240.0f, 10.0f, 800.0f, 445.0f);
    cargarHitbox(18,30.0f, 10.0f, 810.0f, 450.0f);
    _hitbox[18].setRotation(135.f);
    cargarHitbox(19,100.0f, 10.0f, 1100.0f, 460.0f);
    cargarHitbox(20,30.0f, 10.0f, 1260.0f, 495.0f);
    _hitbox[20].setRotation(135.f);
    cargarHitbox(21,350.0f, 10.0f, 1250.0f, 485.0f);
    cargarHitbox(22,50.0f, 10.0f, 975.0f, 370.0f);
    cargarHitbox(23,70.0f, 10.0f, 970.0f, 370.0f);
    _hitbox[23].setRotation(90.f);
    cargarHitbox(24,20.0f, 10.0f, 1080.0f, 290.0f);
    cargarHitbox(25,70.0f, 1.0f, 1150.0f, 230.0f);
    cargarHitbox(26,70.0f, 5.0f, 1280.0f, 150.0f);
    cargarHitbox(27,50.0f, 5.0f, 1380.0f, 120.0f);
    cargarHitbox(28,20.0f, 5.0f, 1440.0f, 110.0f);
    _hitbox[28].setRotation(135.f);
    cargarHitbox(29,50.0f, 10.0f, 1530.0f, 100.0f);
    _hitbox[29].setRotation(90.f);
    cargarHitbox(30,70.0f, 10.0f, 1520.0f, 90.0f);
    cargarHitbox(31,20.0f, 5.0f, 1440.0f, 110.0f);
    return true;
}
// Metodo para cargar hitboxes del nivel 3
bool mapa::cargarNivel3(){
    inicializarVector(25);
    return true;
}

bool mapa::cargarHitbox(int vecPos,float w,float h,float x,float y){

    _hitbox[vecPos].setSize({w,h}); // Define el tamaño en pixeles del rectangulo
    _hitbox[vecPos].setPosition({x,y}); // Setea la posicion del rectangulo en la pantalla
    _hitbox[vecPos].setFillColor(sf::Color::Blue); // Para poder ver las hitboxes, borrar despues
    return true;
}
// Limpia el vector y le reasigna el tamaño
void mapa::inicializarVector(int tam){
    _hitbox.clear();
    _hitbox.resize(tam);
}
// Metodo para establecer el valor de la variable _nivel
void mapa::setNivel(int nivel){
    if(_nivel==2){
    _nivel=1;
    }
    _nivel=2;
}
// Método para dibujar el mapa en la ventana
void mapa::dibujar(sf::RenderWindow& ventana) {

     ventana.draw(_Smapa); // Dibujar mapa
     dibujarHitbox(ventana); // Llamado al metodo dibujar hitbox
}
    // Metodo para Dibujar la hitbox
void mapa::dibujarHitbox(sf::RenderWindow& ventana){
    for(int j=0; j<_hitbox.size();j++){ // Recorre el vector
    ventana.draw(_hitbox[j]);
     }
}
    // Método para verificar colisiones
bool mapa::verificarColision(const sf::RectangleShape& objeto) {
    for (int i=0;i<35;i++) { // Recorre el vector buscando colision
        if (_hitbox[i].getGlobalBounds().intersects(objeto.getGlobalBounds())) {
            return true; // Colisión detectada
        }
    }
    return false; // No hay colisión
}

int mapa::getNivel(){
    return _nivel;
}

void mapa::destructor(){
    _hitbox.clear();
}
