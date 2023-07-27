#ifndef KEY_SCAN
#define KEY_SCAN

#define ROW_PORT        GPIOB
#define KEYS_PER_REPORT 6

typedef struct {
    uint8_t MODIFIER;
    uint8_t RESERVED;
    uint8_t KEYCODE1;
    uint8_t KEYCODE2;
    uint8_t KEYCODE3;
    uint8_t KEYCODE4;
    uint8_t KEYCODE5;
    uint8_t KEYCODE6;
} Keyboard;

void scan_keys(int keys[KEYS_PER_REPORT], int *modifier_byte);
#endif