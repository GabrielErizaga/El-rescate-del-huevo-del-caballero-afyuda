#ifndef HITBOX_H
#define HITBOX_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>


class Hitbox: public sf::Transformable
{
    public:
        virtual void setHitbox(const sf::IntRect& hitbox);
        virtual sf::FloatRect getGlobalHitbox() const;
        Hitbox();
        virtual ~Hitbox();

    protected:

    private:
        sf::FloatRect m_hitbox;
};

#endif // HITBOX_H
