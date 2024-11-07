#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "colisionable.h"


///using namespace std
#include "pj.h"
#include "espada.h"
void espada :: update()
{
e_hitbox.setPosition(_sprite.getPosition().left - 10);


}
espada::espada()
{

m_hitbox.setSize({50,60});
m_hitbox.setFillColor(sf::Color::Blue);

}

//espada::~espada()
//{
//    //dtor
//}
