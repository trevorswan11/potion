#include "touch.hpp"

namespace dev {

Touch::Touch(Pin pin) : pin_{pin} {}

auto Touch::is_pressed() -> bool { return pin_.read() > (pin_.get_range() / 2); }

} // namespace dev
