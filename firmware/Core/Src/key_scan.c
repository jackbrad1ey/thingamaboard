#include <stdint.h>
#include "key_scan.h"
#include "main.h"
#include "key_map.h"
#include "keycodes.h"

int columns[NUM_COLUMNS][2] = {
  {GPIO_PIN_15, GPIOA},
  {GPIO_PIN_10, GPIOC},
  {GPIO_PIN_11, GPIOC},
  {GPIO_PIN_12, GPIOC},
  {GPIO_PIN_2, GPIOD},
  {GPIO_PIN_3, GPIOB},
  {GPIO_PIN_7, GPIOC},
  {GPIO_PIN_8, GPIOC},
  {GPIO_PIN_9, GPIOC},
  {GPIO_PIN_8, GPIOA},
  {GPIO_PIN_9, GPIOA},
  {GPIO_PIN_10, GPIOA},
};

// all row inputs are on GPIOB
int rows[NUM_ROWS] = {
  GPIO_PIN_8,
  GPIO_PIN_9,
  GPIO_PIN_10
  GPIO_PIN_2,
};

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

void scan_keys(int keys[KEYS_PER_REPORT], int *modifier_byte) {
    int num_keys = 0;

    for (int col=0; col < NUM_COLUMNS; col++) {
        HAL_GPIO_WritePin(columns[col][1], columns[col][0], GPIO_PIN_SET);
        delay_us(10);

        for (int row=0; row < NUM_ROWS; row++) {
            if (HAL_GPIO_ReadPin(ROW_PORT, rows[row]) == GPIO_PIN_SET) {
                int keycode = BASE_LAYOUT[row][col];

                if (is_modifier(keycode)) {
                    update_modifier_byte(keycode, modifier_byte);
                } else {
                    keys[num_keys] = keycode;
                }
            }
        }

        HAL_GPIO_WritePin(columns[col][1], columns[col][0], GPIO_PIN_RESET);
        delay_us(10);
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