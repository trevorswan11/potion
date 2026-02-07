#include <iostream>
#include <thread>

#include "gpio_cxx.hpp"

using namespace idf;

extern "C" void app_main() {
    const GPIO_Output gpio{GPIONum(13)};

    while (true) {
        std::cout << "LED ON\n";
        gpio.set_high();
        std::this_thread::sleep_for(std::chrono::seconds(1));

        std::cout << "LED OFF\n";
        gpio.set_low();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
