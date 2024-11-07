#include <colisionable.h>

bool colisionable::isCollision(colisionable& obj)const {

    return getBounds().intersects(obj.getBounds());
}
