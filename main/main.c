#include <stdio.h>
#include "ADC.h"
#include "driver/gpio.h"

#define RED_LED GPIO_NUM_13
#define GREEN_LED GPIO_NUM_12
#define GRENS 2000

void app_main(void)
{

    gpio_reset_pin(RED_LED);
    gpio_reset_pin(GREEN_LED);
    gpio_set_direction(RED_LED, GPIO_MODE_OUTPUT);
    gpio_set_direction(GREEN_LED, GPIO_MODE_OUTPUT);

    while (1)
    {
        if (give_pot_value() > GRENS)
        {
            gpio_set_level(RED_LED, 1);
            gpio_set_level(GREEN_LED, 0);
        }
        else
        {
            gpio_set_level(RED_LED, 0);
            gpio_set_level(GREEN_LED, 1);
        }
    }
}