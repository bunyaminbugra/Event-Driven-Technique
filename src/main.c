/**
  * @file		main.c
  * @version	V1.0
  * @brief		EAE Group Mulakat Uygulamasi
  *
  */

#include "main.h"

/**
  * @brief   Main function
  * @details This is the entry point of the program.
  * @param   None
  * @return  Integer value indicating the exit status
  * @note    The main function should return an exit status indicating the program's termination status.
  */
int main()
{
	struct Event event;
	button_InitTypeDef *button1;
	led_InitTypeDef *led1;
	
	LED_state lastLedState;
	
    SYS_Init();
	Timer_Init();
	SoftTimer_Init();

	button1 = button_Init(PB, BIT15);
	led1 = led_Init(PB, BIT14);
	
	event.Time = 1000;
	event.mode = SHORT_PRESS;
	
    while(1)
	{
		switch (event.mode) 
		{
			case SHORT_PRESS:
			{
				switch(event.led_state)
				{
					case LED_ON:
					{
						if(lastLedState != event.led_state)
						{
							SoftTimer_SetTimer(TIMER_LED, event.Time);
						}
						if(SoftTimer_GetTimerStatus(TIMER_LED))
						{
							event.led_state = LED_OFF;
						}
						
						led_SET(led1);
						
						button_Get_Status(button1);
						
						lastLedState = event.led_state;
						break;
					}
					
					case LED_OFF:
					{
						if(lastLedState != event.led_state)
						{
							SoftTimer_SetTimer(TIMER_LED, event.Time);
						}
						if(SoftTimer_GetTimerStatus(TIMER_LED))
						{
							event.led_state = LED_OFF;
						}
						
						led_RESET(led1);
						
						button_Get_Status(button1);
						
						break;
					}
				}
				break;
			}
				
			case LONG_PRESS:
			{
				switch(event.led_state)
				{
					case LED_ON:
					{
						if(lastLedState != event.led_state)
						{
							SoftTimer_SetTimer(TIMER_LED, event.Time);
						}
						if(SoftTimer_GetTimerStatus(TIMER_LED))
						{
							event.led_state = LED_OFF;
						}
						
						led_SET(led1);
						
						button_Get_Status(button1);
						
						break;
					}
					
					case LED_OFF:
					{
						if(lastLedState != event.led_state)
						{
							SoftTimer_SetTimer(TIMER_LED, event.Time);
						}
						if(SoftTimer_GetTimerStatus(TIMER_LED))
						{
							event.led_state = LED_OFF;
						}
						
						led_RESET(led1);
						
						button_Get_Status(button1);
						
						break;
					}
				}			
				break;
			}
		}
	}
}
