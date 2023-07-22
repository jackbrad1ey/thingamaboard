// stops a keypress from being registered twice within a given interval
#include "debounce.h"

void debounce_decrement() {
    for (int i=0; i < 256; i++) {
        if (debounce_array[i] == 1 && active_toggle[i] == 1) {
            active_toggle[i] = 0;
        } 

        if (debounce_array[i] != 0) {
            debounce_array[i]--;
        }
    }
}

void set_debounce(int keycode) {
    debounce_array[keycode] = DEBOUNCE_RATE;
    active_toggle[keycode] = 1;
}