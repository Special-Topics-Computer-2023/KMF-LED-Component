#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "driver/gpio.h"

class LED
{
	const gpio_num_t LED_gpio_num;
	const bool status;
	LED();
public:
	LED(gpio_num_t gpio_num);
	void ON();
	void OFF();
};
