#include <print>
#include <thread>

#include "gpio_cxx.hpp"

using namespace idf;

extern "C" auto app_main() -> void {
    const GPIO_Output gpio{GPIONum(13)};

    while (true) {
        std::println("LED ON");
        gpio.set_high();
        std::this_thread::sleep_for(std::chrono::seconds(1));

        std::println("LED OFF");
        gpio.set_low();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
