#include "rgb_led.hpp"
#include <algorithm>

namespace dev {

RGBLed::RGBLed(Pin red, Pin green, Pin blue)
    : red_{PwmOut{red}}, green_{PwmOut{green}}, blue_{PwmOut{blue}} {}

auto RGBLed::set_red(uint8_t value) -> void {
    red_.pin.write(value);
    red_.value = value;
}

auto RGBLed::set_green(uint8_t value) -> void {
    green_.pin.write(value);
    green_.value = value;
}

auto RGBLed::set_blue(uint8_t value) -> void {
    blue_.pin.write(value);
    blue_.value = value;
}

auto RGBLed::update(uint8_t r, uint8_t g, uint8_t b) -> void {
    set_red(r);
    set_green(g);
    set_blue(b);
}

auto RGBLed::update(uint32_t hex) -> void { update(hex, 1.0f); }

auto RGBLed::update(uint32_t hex, float scale) -> void {
    const auto    clamped = std::clamp(scale, 0.0f, 1.0f);
    const uint8_t r       = hex >> 16;
    const uint8_t g       = hex >> 8;
    const uint8_t b       = hex;
    update(r * clamped, g * clamped, b * clamped);
}

} // namespace dev
