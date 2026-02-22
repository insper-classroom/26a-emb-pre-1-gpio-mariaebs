#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_R=28;
const int LED_R=4;
const int BTN_G=26;
const int LED_G=6;


int main() {

  stdio_init_all();

  gpio_init(BTN_R);
  gpio_set_dir(BTN_R, GPIO_IN);
  gpio_pull_up(BTN_R);

  gpio_init(BTN_G);
  gpio_set_dir(BTN_G, GPIO_IN);
  gpio_pull_up(BTN_G);
  
  gpio_init(LED_R);
  gpio_set_dir(LED_R, GPIO_OUT);

  gpio_init(LED_G);
  gpio_set_dir(LED_G, GPIO_OUT);
  
  int state_g = 0;  
  int state_r = 0;  

  while (true) {
    if (!gpio_get(BTN_G)) {
        sleep_ms(50);                    
        if (!gpio_get(BTN_G)) {
            state_g = !state_g;          
            gpio_put(LED_G, state_g);
            while (!gpio_get(BTN_G));    
            sleep_ms(50);
        }
      }
    if (!gpio_get(BTN_R)) {
        sleep_ms(50);
        if (!gpio_get(BTN_R)) {
            state_r = !state_r;          
            gpio_put(LED_R, state_r);
            while (!gpio_get(BTN_R));
            sleep_ms(50);
        }
      }
    }
}
