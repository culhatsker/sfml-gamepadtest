#include "StickButtonRect.hpp"

StickButtonRect::StickButtonRect(
    uint gamepadId, 
    uint buttonCode, 
    sf::Joystick::Axis horizontal, 
    sf::Joystick::Axis vertical, 
    sf::Vector2f pos
) : gamepadId(gamepadId), 
    buttonCode(buttonCode), 
    hor(horizontal), 
    ver(vertical),
    pos(pos)
{
    big = sf::RectangleShape(sf::Vector2f(80, 80));
    big.setFillColor(sf::Color(128, 128, 128));
    big.setOrigin(sf::Vector2f(40, 40));
    big.setPosition(pos);
    small = sf::RectangleShape(sf::Vector2f(20, 20));
    small.setOrigin(sf::Vector2f(10, 10));
    small.setPosition(pos);
}

void StickButtonRect::update(float frameTime) {
    sf::Vector2f stick_val = sf::Vector2f(
        sf::Joystick::getAxisPosition(gamepadId, hor),
        sf::Joystick::getAxisPosition(gamepadId, ver)
    ) * 0.4f;
    small.setPosition(pos + stick_val);
    if (sf::Joystick::isButtonPressed(gamepadId, buttonCode)) {
        small.setFillColor(sf::Color::Green);
    } else {
        small.setFillColor(sf::Color::Blue);
    }
}

void StickButtonRect::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(big);
    target.draw(small);
}