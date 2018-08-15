#include <stdio.h>

#include <vector>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Joystick.hpp>

#include "gamepad-config.hpp"
#include "ButtonRect.hpp"
#include "AxisButtonRect.hpp"
#include "StickButtonRect.hpp"


class GameState : public sf::Drawable {
public:
    GameState() {
        buttons = {
            new ButtonRect(0, GamepadButtons::A, sf::Vector2f(600, 340)),
            new ButtonRect(0, GamepadButtons::B, sf::Vector2f(640, 300)),
            new ButtonRect(0, GamepadButtons::X, sf::Vector2f(560, 300)),
            new ButtonRect(0, GamepadButtons::Y, sf::Vector2f(600, 260)),
            new ButtonRect(0, GamepadButtons::LB, sf::Vector2f(200, 80)),
            new ButtonRect(0, GamepadButtons::RB, sf::Vector2f(600, 80)),
            new ButtonRect(0, GamepadButtons::Back, sf::Vector2f(300, 150)),
            new ButtonRect(0, GamepadButtons::Start, sf::Vector2f(500, 150)),
            new AxisButtonRect(0, GamepadAxes::LT, sf::Vector2f(200, 40)),
            new AxisButtonRect(0, GamepadAxes::RT, sf::Vector2f(600, 40)),
            new AxisButtonRect(0, GamepadAxes::DPadHor, sf::Vector2f(330, 450), 1),
            new AxisButtonRect(0, GamepadAxes::DPadHor, sf::Vector2f(270, 450), -1),
            new AxisButtonRect(0, GamepadAxes::DPadVer, sf::Vector2f(300, 420), 1),
            new AxisButtonRect(0, GamepadAxes::DPadVer, sf::Vector2f(300, 480), -1),
            new StickButtonRect(0, GamepadButtons::LeftStick, GamepadAxes::LeftStickHor, GamepadAxes::LeftStickVer, sf::Vector2f(200, 300)),
            new StickButtonRect(0, GamepadButtons::RightStick, GamepadAxes::RightStickHor, GamepadAxes::RightStickVer, sf::Vector2f(500, 450))
        };
    }

    ~GameState() {
        for (UpdatableDrawable * item: buttons) {
            delete item;
        }
    }

    void update(float frameTime) {
        if (sf::Joystick::isConnected(0)) {
            for (UpdatableDrawable * item: buttons) {
                item->update(frameTime);
            }
        }
    }

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        for (UpdatableDrawable const * item: buttons) {
            target.draw(*item);
        }
    }

    std::vector<UpdatableDrawable *> buttons;
    uint buttonCount;
};


int main(int argc, char **argv){
    sf::RenderWindow window(sf::VideoMode(800, 600), "Gamepad test");
    window.setFramerateLimit(60);
    sf::Clock frameClock;
    GameState state;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        float frameTime = frameClock.restart().asSeconds();
        state.update(frameTime);
        window.clear();
        window.draw(state);
        window.display();
    }
}