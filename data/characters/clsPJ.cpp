#include <iostream>
#include "pj.h"
#include "mapa.h"

// Constructor y Destructor
pj::pj() {
    // Cargar textura y configurar sprite
    _textureM.loadFromFile("assets/characters(100x100)/Knight/Knight/Knight.png");
    _sprite.setTexture(_textureM);
    _sprite.setTextureRect({0, 0, 195, 195});
    _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height);



    // Configurar hitboxes
    m_hitbox.setSize({50, 60}); // Hitbox personaje
    m_hitbox.setFillColor(sf::Color::Red);
    e_hitbox.setSize({25, 65}); // Hitbox espada
    e_hitbox.setFillColor(sf::Color::Blue);


    _sprite.setPosition(200, 200);

    _vida=100;
   _bVida.setSize({_vida,10});
   _bVida.setFillColor(sf::Color::Green);



}

pj::~pj() {}

// Método de actualización del estado del personaje
void pj::update(mapa& _objetoMapa) {

    _velocity = {0, _velocity.y};  // Reiniciar velocidad en X y mantener la velocidad en Y


   // _velocity.y += 3.0f; // Aplicar gravedad en el eje Y

    // Animación si el personaje está quieto
    if (_velocity.x == 0 && !_isJumping) {
        _frame += 0.09;
        _sprite.setTextureRect({0 + (int)_frame * 195, 0, 195, 195});
        if (_frame >= 5)_frame = 0;
    }

    // Movimiento y animación en función de las teclas presionadas
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        _frame += 0.2;
        _velocity.x = -4;
        _sprite.setTextureRect({0 + (int)_frame * 195, 195, 195, 195});
        if (_frame >= 7) _frame = 0;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        _frame += 0.2;
        _velocity.x = 4;
        _sprite.setTextureRect({0 + (int)_frame * 195, 195, 195, 195});
        if (_frame >= 7) _frame = 0;
    }
    // Verificar si se presiona la tecla de salto y el personaje no está en el aire
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !_isJumping) {
        _velocity.y = _jumpVelocity; // Iniciar el salto con la velocidad de salto
        _isJumping = true;           // Marcar que está en el aire
    }
    // Aplicar gravedad si el personaje está en el aire
    if (_isJumping) {
        _velocity.y += _gravity; // Incrementar la velocidad hacia abajo (caída)
        _sprite.setTextureRect({0,1170,195,195});
    }else{_velocity.y+=_gravity;}

    // Ataque activado con la tecla Z
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)&& !_isJumping) {
        if (!_ban) _ban = true;
        e_hitbox.setPosition(-50, -50);
    }

    // Animación de ataque
    if (_ban) {
        _frame2 += 0.15;
        if (_sprite.getScale().x == -1 && _frame2 > 2) {
            e_hitbox.setPosition(_sprite.getGlobalBounds().left + 40, _sprite.getGlobalBounds().top + 60);
        } else if (_frame2 > 2) {
            e_hitbox.setPosition(m_hitbox.getGlobalBounds().left + 55, _sprite.getGlobalBounds().top + 60);
        }
        _velocity = {0, 0};
        _sprite.setTextureRect({0 + (int)_frame2 * 195, 390, 195, 195});
        if (_frame2 >= 6) {
            _frame2 = 0;
            _ban = false;
        }
    }
    _sprite.move(0, _velocity.y); // Movimiento en el eje Y

    // Actualización de la posición de la hitbox del personaje en función del sprite
    m_hitbox.setPosition(_sprite.getGlobalBounds().left + 66, _sprite.getGlobalBounds().top + 64);

    // Verificar colisiones en el eje Y
    if (_objetoMapa.verificarColision(m_hitbox)) {
        if (_velocity.y > 0) {  // Si el personaje estaba cayendo
            _sprite.setPosition(_sprite.getPosition().x, _sprite.getPosition().y - _velocity.y); // Reposicionar justo encima de la colisión
            _velocity.y = 0; // Detener solo el movimiento en el eje Y
            _isJumping = false;    // Marcar que el personaje está en el suelo
        }else if (_velocity.y < 0) { // Si el personaje está subiendo
        _sprite.setPosition(_sprite.getPosition().x, _sprite.getPosition().y - _velocity.y); // Reposicionar justo debajo de la colisión
        _velocity.y = 0; // Detener solo el movimiento en el eje Y
        _sprite.setTextureRect({0,1170,195,195});
        // No es necesario marcar _isJumping como false aca, ya que el personaje todavía está en el aire
    }else{_sprite.setTextureRect({0,1170,195,195});}
}

    _sprite.move(_velocity.x, 0); // Movimiento en el eje X
    // Verificar colisiones en el eje X
    m_hitbox.setPosition(_sprite.getGlobalBounds().left + 66, _sprite.getGlobalBounds().top + 64);
    if (_objetoMapa.verificarColision(m_hitbox)) {
        if (_velocity.x != 0) {  // Si el personaje estaba moviéndose en X

            _sprite.move(-_velocity.x, 0); // Deshacer el movimiento en X
            _velocity.x = 0; // Detiene el movimiento en X sin afectar el eje Y
        }
}

    // Actualización de la posición de la hitbox
    m_hitbox.setPosition(5 + _sprite.getGlobalBounds().left + 66, _sprite.getGlobalBounds().top + 64);
    _bVida.setPosition(5 + _sprite.getGlobalBounds().left + 66, _sprite.getGlobalBounds().top + 50);
    if(_vida < 51 ){

        _bVida.setFillColor(sf::Color::Red);
    }else{
    _bVida.setFillColor(sf::Color::Green);
    }

    // Ajuste de dirección del sprite
    if (_velocity.x < 0) {
        _sprite.setScale(-1, 1);
    } else if (_velocity.x > 0) {
        _sprite.setScale(1, 1);
    }

    // Límites de la ventana
    if (m_hitbox.getGlobalBounds().left < 0) {
        _sprite.setPosition(_sprite.getPosition().x + 4, _sprite.getPosition().y);
        m_hitbox.setPosition(m_hitbox.getPosition().x - _velocity.x, m_hitbox.getPosition().y);
    }
    if (m_hitbox.getGlobalBounds().left+50 > 1600) {
        _sprite.setPosition(_sprite.getPosition().x - 4, _sprite.getPosition().y);
        m_hitbox.setPosition(m_hitbox.getPosition().x - _velocity.x, m_hitbox.getPosition().y);
    }
    if (m_hitbox.getGlobalBounds().top < 0) {
        _sprite.setPosition(_sprite.getPosition().x, _sprite.getPosition().y + 4);
    }
    if (m_hitbox.getGlobalBounds().top + m_hitbox.getGlobalBounds().height > 600) {
          muerte();
        //_sprite.setPosition(_sprite.getPosition().x, 600 + (_sprite.getGlobalBounds().height - 122));
    }
}

 bool pj::isAlive(){
 if( _vida > 0  ){ return true;   }
 else{return false;    }
 }
    void pj::danioRecibido(int danio){

        _frame4 += 0.1f;


         _sprite.setTextureRect({0 + (int)_frame4 * 195, 1170 , 195, 195});
        if (_frame4 >= 4) {
            _frame4 = 0;
        _vida=_vida-danio;
        }
}
// Método para dibujar el personaje y sus hitboxes
void pj::draw(sf::RenderTarget& target, sf::RenderStates state) const {
    target.draw(m_hitbox, state);
    target.draw(_sprite, state);
    target.draw(_bVida);
    if (_ban) {
        target.draw(e_hitbox, state); // Si se activa el ataque, lo dibuja
    }
}

// Métodos auxiliares y de estado del personaje
bool pj::getBan(){
return _ban;
}

void pj::curar(int cant) {
    _vida = _vida + cant;
}
float pj::getPositionX(){
    return _sprite.getPosition().x;
};
float pj::getPositionY(){
    return m_hitbox.getPosition().y;
};
void pj::muerte() {

    _frame3 += 0.15;
    _velocity = {0, 0};
    _sprite.setTextureRect({0 + (int)_frame3 * 195, 1560, 195, 195});
    if (_frame3 >= 4) {
        _frame3 = 0;
        m_hitbox.setPosition(0, 0);
        _sprite.setPosition(0, 0);
    _vida=100;
    }
}

// Métodos de obtención de hitboxes
sf::RectangleShape pj::getHitbox() const {
    return m_hitbox;
}

sf::RectangleShape pj::getHitboxE() {
    return e_hitbox;
}

// Método de respawn para reiniciar la posición del personaje
void pj::respawn() {
    _sprite.setPosition(std::rand() % 700 + _sprite.getGlobalBounds().width,
                        std::rand() % 500 + _sprite.getGlobalBounds().height);
    m_hitbox.setPosition(_sprite.getGlobalBounds().left, _sprite.getGlobalBounds().top);
}


