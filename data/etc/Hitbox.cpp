#include "Hitbox.h"

void Hitbox::setHitbox(const sf::IntRect& hitbox){
    m_hitbox = (sf::FloatRect)hitbox;
}
sf::IntRect Hitbox::getGlobalHitbox()const{
    return getTransform().transformRect(m_hitbox);
}



Hitbox::Hitbox()
{
    //ctor
}

Hitbox::~Hitbox()
{
    //dtor
}
