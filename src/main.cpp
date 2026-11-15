#include <iostream>


// Declrations

bool update_safe_mode(bool current_mode, double temperature_c, bool reset_requested);

int main() {
    const double readings[] = {25.0, 65.0, 55.0, 40.0, 40.0};
    const bool reset_requested[] = {false, false, true, false, true};

    bool safe_mode = false;

    for (int i = 0; i < 5; i++) {
        safe_mode = update_safe_mode(safe_mode, readings[i], reset_requested[i]);

        std::cout << readings[i] << " C | Reset: " << (reset_requested[i] ? "YES" : "NO") << " | Mode: " << (safe_mode ? "SAFE" : "NOMINAL") << "\n";
    }

    return 0;
}

bool update_safe_mode(bool current_mode, double temperature_c, bool reset_requested) {
    if (temperature_c >= 60.0) {
        return true;
    }

    if (temperature_c <= 50.0 && reset_requested) {
        return false;
    }
    
    return current_mode;
}
