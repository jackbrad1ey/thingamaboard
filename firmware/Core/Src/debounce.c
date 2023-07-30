#include "debounce.h"

int debounce_array[256] = {0};
int active_toggle[256] = {0};

void debounce_decrement() {
    for (int i=0; i < 256; i++) {
        if (debounce_array[i] != 0) {
            debounce_array[i]--;
        }
    }
}

void set_debounce(int keycode) {
    debounce_array[keycode] = DEBOUNCE_RATE;
    active_toggle[keycode] = 1;
}