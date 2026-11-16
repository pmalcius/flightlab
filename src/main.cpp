#include <iostream>
#include <cassert>

// Declrations

#include "safe_mode.cpp"

void test_update_safe_mode();


int main() {
    test_update_safe_mode();

    const double readings[] = {25.0, 65.0, 55.0, 40.0, 40.0};
    const bool reset_requested[] = {false, false, true, false, true};

    bool safe_mode = false;

    for (int i = 0; i < 5; i++) {
        safe_mode = update_safe_mode(safe_mode, readings[i], reset_requested[i]);

        std::cout << readings[i] << " C | Reset: " << (reset_requested[i] ? "YES" : "NO") << " | Mode: " << (safe_mode ? "SAFE" : "NOMINAL") << "\n";
    }

    return 0;
}

void test_update_safe_mode() {
    assert(update_safe_mode(false, 65.0, false));
    assert(update_safe_mode(true, 50.0, true));
    assert(!update_safe_mode(true, 49.0, true));
    assert(update_safe_mode(true, 40.0, false));
    assert(update_safe_mode(false, 60.0, true));
}

