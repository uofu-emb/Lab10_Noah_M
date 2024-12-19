#include <stdio.h>
#include <pico/stdlib.h>
#include <pico/sync.h>

int toggle = 1;
void irq_callback(uint gpio, uint32_t event_mask)
{
    if (gpio != 1) return;
    toggle = !toggle;
    if (event_mask & GPIO_IRQ_EDGE_RISE) {
        gpio_put(0, true);
    } else if (event_mask & GPIO_IRQ_EDGE_FALL) {
        gpio_put(0, false);
    }
}

int main(void)
{
    stdio_init_all();

    gpio_init(1);
    gpio_set_dir(1, GPIO_IN);

    gpio_init(0);
    gpio_set_dir(0, GPIO_OUT);
    gpio_put(0, toggle);

    gpio_set_irq_enabled_with_callback(1, GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL , true, irq_callback);
    while(1) __wfi();
    return 0;
}