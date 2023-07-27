#include "keycodes.h"

void update_modifier_byte(int keycode, int *modifier_byte) {
    switch (keycode) {
        case KEY_MOD_LCTRL:
            *modifier_byte |= KEY_MOD_LCTRL_MASK;
            break;
        case KEY_MOD_LSHIFT:
            *modifier_byte |= KEY_MOD_LSHIFT_MASK;
            break;
        case KEY_MOD_LALT:
            *modifier_byte |= KEY_MOD_LALT_MASK;
            break;
        case KEY_MOD_LMETA:
            *modifier_byte |= KEY_MOD_LMETA_MASK;
            break;
        case KEY_MOD_RCTRL:
            *modifier_byte |= KEY_MOD_RCTRL_MASK;
            break;
        case KEY_MOD_RSHIFT:
            *modifier_byte |= KEY_MOD_RSHIFT_MASK;
            break;
        case KEY_MOD_RALT:
            *modifier_byte |= KEY_MOD_RALT_MASK;
            break;
        case KEY_MOD_RMETA:
            *modifier_byte |= KEY_MOD_RMETA_MASK;
            break;
    }
}

int is_modifier(int keycode) {
    switch (keycode) {
        case KEY_LEFTCTRL:
            return 1;
        case KEY_LEFTSHIFT:
            return 1;
        case KEY_LEFTALT:
            return 1;
        case KEY_LEFTMETA:
            return 1;
        case KEY_RIGHTCTRL:
            return 1;
        case KEY_RIGHTSHIFT:
            return 1;
        case KEY_RIGHTALT:
            return 1;
        case KEY_RIGHTMETA:
            return 1;
    }

    return 0;
}
