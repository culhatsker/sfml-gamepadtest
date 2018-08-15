#include <SFML/Graphics/Drawable.hpp>

#pragma once

class UpdatableDrawable : public sf::Drawable {
public:
    virtual void update(float) = 0;
private:
    virtual void draw(sf::RenderTarget &, sf::RenderStates) const = 0;
};