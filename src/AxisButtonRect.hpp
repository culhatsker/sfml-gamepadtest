#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Joystick.hpp>

#include "UpdatableDrawable.hpp"

class AxisButtonRect : public UpdatableDrawable {
public:
    AxisButtonRect(
        uint gamepadId, 
        sf::Joystick::Axis axis, 
        sf::Vector2f pos, 
        int direction = 1
    );

    virtual void update(float frameTime);

private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    uint gamepadId;
    int direction;
    sf::Joystick::Axis axis;
    sf::RectangleShape rect;
};