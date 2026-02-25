#include <stdio.h>
#include "ADC.h"
#include "driver/gpio.h"
#include "driver/adc.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define POTENTIOMETER_CHANNEL ADC1_CHANNEL_0
#define ADC_UNIT ADC_UNIT_1
#define RESOLUTIE ADC_WIDTH_BIT_12
#define VERZWAKKING ADC_ATTEN_DB_0
#define RED_LED GPIO_NUM_13
#define GREEN_LED GPIO_NUM_12
#define GRENS 2000

static void led_init(void){
    gpio_reset_pin(RED_LED);
    gpio_reset_pin(GREEN_LED);
    gpio_set_direction(RED_LED, GPIO_MODE_OUTPUT);
    gpio_set_direction(GREEN_LED, GPIO_MODE_OUTPUT);
}

static void pot_init(void){
    adc1_config_width(RESOLUTIE);
    adc1_config_channel_atten(POTENTIOMETER_CHANNEL, VERZWAKKING);
}


void func(void)
{
    led_init();
    pot_init();

    while (1)
    {
        int pot_value = adc1_get_raw(POTENTIOMETER_CHANNEL);
        printf("Potentiometer value: %d\n", pot_value);
        if (pot_value > GRENS)
        {
            gpio_set_level(RED_LED, 1);
            gpio_set_level(GREEN_LED, 0);
        }
        else
        {
            gpio_set_level(RED_LED, 0);
            gpio_set_level(GREEN_LED, 1);
        }
        vTaskDelay(pdMS_TO_TICKS(200));
    }
    
}