#include "safe_mode.hpp"

bool update_safe_mode(bool current_mode, double temperature_c, bool reset_requested) {
    if (temperature_c >= 60.0) {
        return true;
    }

    if (temperature_c < 50.0 && reset_requested) {
        return false;
    }
    
    return current_mode;
}

