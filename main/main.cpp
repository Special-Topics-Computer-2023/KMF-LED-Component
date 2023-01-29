#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "LED.h"
extern "C"
{
	void app_main(void);
}

LED led1(GPIO_NUM_23);
LED led2(GPIO_NUM_22);
LED led3(GPIO_NUM_1);
LED led4(GPIO_NUM_3);
LED led5(GPIO_NUM_21);
LED led6(GPIO_NUM_19);
LED led7(GPIO_NUM_18);
LED led8(GPIO_NUM_5);

uint32_t sleep_us = 150000l;

LED ledRow[8] = {led1, led2, led3, led4, led5, led6, led7, led8 };


void LED_Chasing_1()
{
	led8.OFF();
	led1.ON();
	usleep(sleep_us);
	led1.OFF();
	led2.ON();
	usleep(sleep_us);
	led2.OFF();
	led3.ON();
	usleep(sleep_us);
	led3.OFF();
	led4.ON();
	usleep(sleep_us);
	led4.OFF();
	led5.ON();
	usleep(sleep_us);
	led5.OFF();
	led6.ON();
	usleep(sleep_us);
	led6.OFF();
	led7.ON();
	usleep(sleep_us);
	led7.OFF();
	led8.ON();
	usleep(sleep_us);
}

void app_main(void)
{
	while (true)
	{
//		LED_Chasing_1();

		for (uint8_t i = 0; i < 8; i++)
		{
			ledRow[i % 8].OFF();
			ledRow[(i + 1) % 8].ON();
			usleep(sleep_us);
		}

	}
}
