#include "ButtonRect.hpp"

ButtonRect::ButtonRect(
    uint gamepadId, 
    uint buttonCode, 
    sf::Vector2f pos
) : gamepadId(gamepadId), 
    buttonCode(buttonCode) 
{
    rect = sf::RectangleShape();
    rect.setSize(sf::Vector2f(20, 20));
    rect.setOrigin(sf::Vector2f(10, 10));
    rect.setPosition(pos);
}

void ButtonRect::update(float frameTime) {
    if (sf::Joystick::isButtonPressed(gamepadId, buttonCode)) {
        rect.setFillColor(sf::Color::Green);
    } else {
        rect.setFillColor(sf::Color::Blue);
    }
}

void ButtonRect::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(rect);
}