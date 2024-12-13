#include "FreeRTOS.h"
#include "task.h"
#include "hardware/timer.h"
#include "pico_sleep/include/pico/sleep.h"
#include "pico/stdio.h"
#include "pico/time.h"
#include "hardware/gpio.h"

int main(void)
{
    stdio_init_all();
    gpio_init(0);
    gpio_set_dir(0, true);
    gpio_put(0, true);

    while(1) {
        uint32_t k;
        for (int i = 0; i < 30; i++) {
            uint32_t j = 0;
            j = ((~j >> i) + 1) * 27644437;
            k = j;
        }
    }
    return 0;
}