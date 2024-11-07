#include <colisionable.h>

bool colisionable::isCollision(colisionable& obj)const {

    return getHitbox().getGlobalBounds().intersects(obj.getHitbox().getGlobalBounds());
}
