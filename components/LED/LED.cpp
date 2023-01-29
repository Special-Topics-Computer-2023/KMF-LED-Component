#include <stdio.h>
#include "LED.h"

LED::LED() :
		LED_gpio_num(GPIO_NUM_NC), status(0)
{

}

LED::LED(gpio_num_t led_gpio_num) :
		LED_gpio_num(led_gpio_num), status(0)
{
	gpio_reset_pin(LED_gpio_num);
	gpio_set_direction(LED_gpio_num, GPIO_MODE_OUTPUT);
}

void LED::ON()
{
	gpio_set_level(LED_gpio_num, 1);
}

void LED::OFF()
{
	gpio_set_level(LED_gpio_num, 0);
}
