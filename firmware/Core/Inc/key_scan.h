#ifndef KEY_SCAN
#define KEY_SCAN

#define ROW_PORT        GPIOB
#define KEYS_PER_REPORT 6

typedef struct {
    int MODIFIER;
    int RESERVED;
    int KEYCODE1;
    int KEYCODE2;
    int KEYCODE3;
    int KEYCODE4;
    int KEYCODE5;
    int KEYCODE6;
} Keyboard;

void scan_keys(int keys[KEYS_PER_REPORT], int *modifier_byte);
#endif