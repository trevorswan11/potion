#pragma once

#include "pins.hpp"

namespace dev {

class Touch {
  public:
    explicit Touch(Pin pin);

    [[nodiscard]] auto is_pressed() -> bool;

  private:
    AnalogIn pin_;
};

} // namespace dev
