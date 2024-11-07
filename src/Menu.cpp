#include "Menu.h"

Menu::Menu(const std::vector<std::string>& options, const sf::Font& menuFont, float width, float height) {
    font = menuFont;
    selectedIndex = 0;

    for (size_t i = 0; i < options.size(); ++i) {
        sf::Text text;
        text.setFont(font);
        text.setString(options[i]);
        text.setFillColor(i == selectedIndex ? selectedColor : normalColor);
        text.setPosition(sf::Vector2f(width / 2, height / (options.size() + 1) * (i + 1)));
        menuOptions.push_back(text);
    }
}
