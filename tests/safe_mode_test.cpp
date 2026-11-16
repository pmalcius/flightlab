#include "safe_mode.hpp"
#include <cassert>

int main() {
    assert(update_safe_mode(false, 65.0, false));
    assert(update_safe_mode(true, 50.0, true));
    assert(!update_safe_mode(true, 49.0, true));
    assert(update_safe_mode(true, 40.0, false));
    assert(update_safe_mode(false, 60.0, true));

    return 0;
}

