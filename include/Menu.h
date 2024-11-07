#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Menu  {
private:
    sf::Font font;
    std::vector<sf::Text> menuOptions;
    int selectedIndex;
    sf::Color normalColor = sf::Color::White;
    sf::Color selectedColor = sf::Color::Red;

public:
    Menu(const std::vector<std::string>& options, const sf::Font& menuFont, float width, float height);

    void draw(sf::RenderWindow& window);
    void moveUp();
    void moveDown();
    int getSelectedOption();
};

#endif // MENU_H
