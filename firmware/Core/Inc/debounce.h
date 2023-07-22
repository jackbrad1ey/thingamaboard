#ifndef DEBOUNCE_M
#define DEBOUNCE_M

#define DEBOUNCE_RATE 100
int debounce_array[256] = {0};
int active_toggle[256] = {0};

void debounce_decrement();
void set_debounce(int keycode);

#endif