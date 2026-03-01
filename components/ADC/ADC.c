#include <stdio.h>
#include "ADC.h"
#include "driver/gpio.h"
#include "driver/adc.h"

#define POTENTIOMETER_CHANNEL ADC1_CHANNEL_0
#define ADC_UNIT ADC_UNIT_1
#define RESOLUTIE ADC_WIDTH_BIT_12
#define VERZWAKKING ADC_ATTEN_DB_0



void pot_init(void){
    adc1_config_width(RESOLUTIE);
    adc1_config_channel_atten(POTENTIOMETER_CHANNEL, VERZWAKKING);
}


int give_pot_value(void)
{
    pot_init();

    int pot_value = adc1_get_raw(POTENTIOMETER_CHANNEL);
    printf("Potentiometer value: %d\n", pot_value);
    return pot_value;
}