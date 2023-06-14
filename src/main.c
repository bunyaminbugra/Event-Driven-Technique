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
	button_InitTypeDef button1;
	
    SYS_Init();
	GPIO_Init();
	Timer_Init();
	SoftTimer_Init();
	
    while(1)
	{
		button_Get_Status(&button1);
		
		dequeue(&event);

		switch (event.type) 
		{
			case SHORT_PREES:
				short_press_state();
				break;
			case LONG_PRESS:
				long_press_state();
				break;
			default:
				short_press_state(); // ????
				break;
		}
	}
}
