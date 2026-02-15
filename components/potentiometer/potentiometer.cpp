#include "potentiometer.hpp"

namespace dev {

Potentiometer::Potentiometer(Pin pin) : pin_{pin} {}

auto Potentiometer::read() -> int { return pin_.read(); }

} // namespace dev
