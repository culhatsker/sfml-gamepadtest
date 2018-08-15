#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Joystick.hpp>

#include "UpdatableDrawable.hpp"

class ButtonRect : public UpdatableDrawable {
public:
    ButtonRect(uint gamepadId, uint buttonCode, sf::Vector2f pos);

    virtual void update(float frameTime);
private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    uint gamepadId, buttonCode;
    sf::RectangleShape rect;
};