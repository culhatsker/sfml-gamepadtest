#include "AxisButtonRect.hpp"

AxisButtonRect::AxisButtonRect(
    uint gamepadId, 
    sf::Joystick::Axis axis, 
    sf::Vector2f pos, 
    int direction
) : gamepadId(gamepadId), 
    axis(axis), 
    direction(direction) 
{
    rect = sf::RectangleShape();
    rect.setSize(sf::Vector2f(20, 20));
    rect.setOrigin(sf::Vector2f(10, 10));
    rect.setPosition(pos);
}

void AxisButtonRect::update(float frameTime) {
    if (sf::Joystick::getAxisPosition(gamepadId, axis) * direction > 0) {
        rect.setFillColor(sf::Color::Green);
    } else {
        rect.setFillColor(sf::Color::Blue);
    }
}

void AxisButtonRect::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(rect);
}