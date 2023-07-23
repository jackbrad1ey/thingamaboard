// maps keycode to each matrix position, this also will store each layer map once we make multiple layers
#include "key_map.h"
#include "keycodes.h"

int BASE_LAYOUT[NUM_ROWS][NUM_COLUMNS] = {
    {KEY_TAB, KEY_Q, KEY_W, KEY_F, KEY_P, KEY_B, KEY_J, KEY_L, KEY_U, KEY_Y, KEY_SEMICOLON, KEY_MINUS},
    {KEY_LEFTSHIFT, KEY_A, KEY_R, KEY_S, KEY_T, KEY_G, KEY_M, KEY_N, KEY_E, KEY_I, KEY_O, KEY_APOSTROPHE},
    {KEY_KEYPAD_EXC_MARK, KEY_Z, KEY_X, KEY_C, KEY_D, KEY_V, KEY_K, KEY_H, KEY_COMMA, KEY_DOT, KEY_SLASH, KEY_BACKSLASH},
    {KEY_NONE, KEY_NONE, KEY_NONE, KEY_NONE, KEY_NONE, KEY_SPACE, KEY_BACKSPACE, KEY_ENTER, KEY_ESC, KEY_NONE, KEY_NONE, KEY_NONE}
};