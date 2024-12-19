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
    gpio_put(0, false);

    bool toggle = false;
    while(1)
    {
        sleep_ms(500);
        toggle = !toggle;
        gpio_put(0, toggle);
    }
}