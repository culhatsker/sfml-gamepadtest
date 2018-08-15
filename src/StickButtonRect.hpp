#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Joystick.hpp>

#include "UpdatableDrawable.hpp"


class StickButtonRect : public UpdatableDrawable {
public:
    StickButtonRect(
        uint gamepadId, 
        uint buttonCode, 
        sf::Joystick::Axis horizontal, 
        sf::Joystick::Axis vertical, 
        sf::Vector2f pos
    );

    virtual void update(float frameTime);
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    uint gamepadId, buttonCode;
    sf::Joystick::Axis hor, ver;
    sf::RectangleShape big, small;
    sf::Vector2f pos;
};