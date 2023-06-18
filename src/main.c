/**
  * @file:		main.c
  * @author:    Bünyamin Bugra Korkmazer
  * @date:      June 18, 2023
  * @version:	V1.0
  *
  * @brief:		EAE Group Job Interview Application
  *  
  * Revision History: 
  * - 1.0.0 (June 18, 2023): Initial release.
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
	/* Initialization of the required structures and variables */
	struct Event event;
	Event_Type currentMode;
	button_InitTypeDef *button1;
	led_InitTypeDef *led1;
	
	LED_state lastLedState = LED_OFF;
	
	/* Initialization of the system */
    SYS_Init();
	
	/* Timer initialization */
	Timer_Init();
	
	/* Software timer initialization */
	SoftTimer_Init();
	
	/* Event structure initialization */
	event_Init(&event);

	/* Button and LED initialization */
	button1 = button_Init(PB, BIT15);
	led1 = led_Init(PB, BIT14);
	
	/* Main program loop */
    while(1)
	{
		/* Handling of events based on their type */
		switch (event.mode) 
		{
			/* Handling of SHORT_PRESS events */
			case SHORT_PRESS:
			{
				switch(event.led_state)
				{
					/* Handling of LED_ON state */
					case LED_ON:
					{
						if(lastLedState != event.led_state)
						{
							SoftTimer_SetTimer(TIMER_LED, event.Time);
						}
						if(SoftTimer_GetTimerStatus(TIMER_LED))
						{
							lastLedState = event.led_state;
							event.led_state = LED_OFF;
							SoftTimer_ResetTimer(TIMER_LED);
							break;
						}
						
						led_SET(led1);
						
						button_Get_Status(button1);
						
						lastLedState = event.led_state;
						break;
					}
					
					/* Handling of LED_OFF state */
					case LED_OFF:
					{
						if(lastLedState != event.led_state)
						{
							SoftTimer_SetTimer(TIMER_LED, event.Time);
						}
						if(SoftTimer_GetTimerStatus(TIMER_LED))
						{
							lastLedState = event.led_state;
							event.led_state = LED_ON;
							SoftTimer_ResetTimer(TIMER_LED);
							
							event.state_Counter++;
						
							if(event.state_Counter == 2)
							{
								event.Time = 2000;
							}
							else if(event.state_Counter == 4)
							{
								event.Time = 1000;
								event.state_Counter = 0;
								
								currentMode = dequeue(&event);
								
								if(currentMode != NONE && currentMode != event.mode)
								{
									event.mode = currentMode;
								}
							}
							
							break;
						}
						
						led_RESET(led1);
						
						button_Get_Status(button1);
						
						lastLedState = event.led_state;
						break;
					}
				}
				break;
			}
			
			/* Handling of LONG_PRESS events */
			case LONG_PRESS:
			{
				switch(event.led_state)
				{
					/* Handling of LED_ON state */
					case LED_ON:
					{
						if(lastLedState != event.led_state)
						{
							SoftTimer_SetTimer(TIMER_LED, event.Time);
						}
						if(SoftTimer_GetTimerStatus(TIMER_LED))
						{
							lastLedState = event.led_state;
							event.led_state = LED_OFF;
							SoftTimer_ResetTimer(TIMER_LED);
							break;
						}
						
						led_SET(led1);
						
						button_Get_Status(button1);
						
						lastLedState = event.led_state;
						break;
					}
					
					/* Handling of LED_OFF state */
					case LED_OFF:
					{
						if(lastLedState != event.led_state)
						{
							SoftTimer_SetTimer(TIMER_LED, event.Time);
						}
						if(SoftTimer_GetTimerStatus(TIMER_LED))
						{
							lastLedState = event.led_state;
							event.led_state = LED_ON;
							SoftTimer_ResetTimer(TIMER_LED);
							
							event.state_Counter++;
						
							if(event.state_Counter == 4)
							{
								event.Time = 2000;
							}
							else if(event.state_Counter == 8)
							{
								event.Time = 1000;
								event.state_Counter = 0;
								
								currentMode = dequeue(&event);
								
								if(currentMode != NONE && currentMode != event.mode)
								{
									event.mode = currentMode;
								}
							}
							
							break;
						}
						
						led_RESET(led1);
						
						button_Get_Status(button1);
						
						lastLedState = event.led_state;
						break;
					}
				}
				break;
			}
			
			case NONE:
			{
				break;
			}
						
		}
	}
}
