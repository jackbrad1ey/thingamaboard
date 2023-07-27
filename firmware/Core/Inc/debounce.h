#ifndef DEBOUNCE_M
#define DEBOUNCE_M

#define DEBOUNCE_RATE 100
extern int debounce_array[256];
extern int active_toggle[256];

void debounce_decrement();
void set_debounce(int keycode);

#endif