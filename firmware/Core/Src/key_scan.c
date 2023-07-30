#include <stdint.h>

#include "key_scan.h"
#include "main.h"
#include "key_map.h"
#include "keycodes.h"
#include "debounce.h"

int columns_pins[NUM_COLUMNS] = {
    GPIO_PIN_15,
    GPIO_PIN_10,
    GPIO_PIN_11,
    GPIO_PIN_12,
    GPIO_PIN_2,
    GPIO_PIN_3,
    GPIO_PIN_7,
    GPIO_PIN_8,
    GPIO_PIN_9,
    GPIO_PIN_8,
    GPIO_PIN_9,
    GPIO_PIN_10
};

GPIO_TypeDef *columns_ports[NUM_COLUMNS] = {
    GPIOA,
    GPIOC,
    GPIOC,
    GPIOC,
    GPIOD,
    GPIOB,
    GPIOC,
    GPIOC,
    GPIOC,
    GPIOA,
    GPIOA,
    GPIOA
};

// all row inputs are on GPIOB
int rows[NUM_ROWS] = {
  GPIO_PIN_8,
  GPIO_PIN_9,
  GPIO_PIN_10,
  GPIO_PIN_2
};

void scan_keys(int keys[KEYS_PER_REPORT], int *modifier_byte) {
    int num_keys = 0;

    for (int col=0; col < NUM_COLUMNS; col++) {
        HAL_GPIO_WritePin(columns_ports[col], columns_pins[col], GPIO_PIN_SET);
        delay_us(10);

        for (int row=0; row < NUM_ROWS; row++) {
        	if (col == 0 && row == 0) {  // dead key for now
        		continue;
        	}

            if (HAL_GPIO_ReadPin(ROW_PORT, rows[row]) == GPIO_PIN_SET) {
                int keycode = BASE_LAYOUT[row][col];

                if (is_modifier(keycode)) {
                    update_modifier_byte(keycode, modifier_byte);
                } else if (num_keys < KEYS_PER_REPORT && active_toggle[keycode] == 0) { // add a check to see if debounced as well
                    set_debounce(keycode);
                    keys[num_keys] = keycode;
                    num_keys++;
                }
            }
        }
        HAL_GPIO_WritePin(columns_ports[col], columns_pins[col], GPIO_PIN_RESET);
        delay_us(10);
    }
    debounce_decrement();
}
