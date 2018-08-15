#include <SFML/Window/Joystick.hpp>

enum GamepadButtons {
    A,
    B,
    X,
    Y,
    LB,
    RB,
    Back,
    Start,
    Unknown_8,
    LeftStick,
    RightStick,
};

namespace GamepadAxes {
    const auto DPadHor = sf::Joystick::Axis::PovX;
    const auto DPadVer = sf::Joystick::Axis::PovY;
    const auto LT = sf::Joystick::Axis::Z;
    const auto RT = sf::Joystick::Axis::R;
    const auto LeftStickHor = sf::Joystick::Axis::X;
    const auto LeftStickVer = sf::Joystick::Axis::Y;
    const auto RightStickHor = sf::Joystick::Axis::U;
    const auto RightStickVer = sf::Joystick::Axis::V;
};