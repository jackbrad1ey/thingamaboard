#include <stdint.h>
#include "key_scan.h"
#include "main.h"

int columns[NUM_COLUMNS][2] = {
  {GPIO_PIN_7, GPIOC},
  {GPIO_PIN_8, GPIOC},
  {GPIO_PIN_9, GPIOC},
  {GPIO_PIN_10, GPIOC},
  {GPIO_PIN_11, GPIOC},
  {GPIO_PIN_12, GPIOC},
  {GPIO_PIN_8, GPIOA},
  {GPIO_PIN_9, GPIOA},
  {GPIO_PIN_10, GPIOA},
  {GPIO_PIN_15, GPIOA},
  {GPIO_PIN_2, GPIOD},
  {GPIO_PIN_3, GPIOB},
};

// all row inputs are on GPIOB
int rows[NUM_ROWS] = {
  GPIO_PIN_2,
  GPIO_PIN_8,
  GPIO_PIN_9,
  GPIO_PIN_10
};

typedef struct
{
	uint8_t MODIFIER;
	uint8_t RESERVED;
	uint8_t KEYCODE1;
	uint8_t KEYCODE2;
	uint8_t KEYCODE3;
	uint8_t KEYCODE4;
	uint8_t KEYCODE5;
	uint8_t KEYCODE6;
} Keyboard;

void scan_keys(int *rows, int **columns) {

}