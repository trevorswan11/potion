#include <cmath>
#include <thread>

#include "potentiometer.hpp"
#include "rgb_led.hpp"
#include "touch.hpp"

using namespace idf;
using namespace std::chrono_literals;

const uint32_t DEEP_BLUE   = 0x1A2FF9;
const uint32_t HAPPY_COLOR = 0x28E96B;

extern "C" auto app_main() -> void {
    dev::Potentiometer pot{dev::pin_layout::A4};
    dev::Touch         touch{dev::pin_layout::A3};
    dev::RGBLed        rgb{dev::pin_layout::A7, dev::pin_layout::A8, dev::pin_layout::A9};

    rgb.update(0xC0FFEE);
    while (true) {
        const auto pot_percent = static_cast<float>(pot.read()) / pot.max_value();
        const auto base_color  = touch.is_pressed() ? HAPPY_COLOR : DEEP_BLUE;
        rgb.update(base_color, pot_percent);
        std::this_thread::sleep_for(50ms);
    }
}
