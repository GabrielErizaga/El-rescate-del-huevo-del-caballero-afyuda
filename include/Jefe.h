#ifndef JEFE_H
#define JEFE_H


class Jefe : public sf::Drawable, public colisionable
{
    public:
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates state)const override;
    void isAlive();
    void muerte();
    void danioRecivido(int danio);


    private:
        Jefe();
        sf::RectangleShape j_hitbox;
        sf::RectangleShape _hitbox;
        sf::Sprite j_sprite;
        sf::Texture j_texture;
        sf::Vector2f j_velovity={};
        float j_frame=0;
        float j_vida;






};

#endif // JEFE_H
