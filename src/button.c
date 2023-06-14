#include "main.h"

void button_Init(GPIO_T *port, unsigned long pin, int portNumber, int pinNumber)
{
	button_InitTypeDef *button = (button_InitTypeDef *)malloc(sizeof(button_InitTypeDef));
	
	button->port = port;
	button->pin = pin;
	button->buttonPin = GPIO_PIN_DATA(portNumber, pinNumber);
}

void button_DeInit(button_InitTypeDef *button)
{
	free(button);
}

int button_Get_Status(button_InitTypeDef *button)
{
	static int lastButtonState, buttonState;
	
	buttonState = button->buttonPin;
	
	if(buttonState != lastButtonState && buttonState)
	{
		SoftTimer_ResetTimer(TIMER_DEBOUNCE);
		SoftTimer_ResetTimer(TIMER_LONG_PRESS);
		
		SoftTimer_SetTimer(TIMER_DEBOUNCE, 100);
		SoftTimer_SetTimer(TIMER_LONG_PRESS, 3000);
		lastButtonState = buttonState;
		enqueue(NONE_EVENT); // ????
		return 0;
	}
	
	else if(SoftTimer_GetTimerStatus(TIMER_DEBOUNCE) && buttonState)
	{
		if(SoftTimer_GetTimerStatus(TIMER_LONG_PRESS))
		{
			SoftTimer_ResetTimer(TIMER_LONG_PRESS);
			enqueue(LONG_PRESS);
			return 0;
		}
		else if (!buttonState)
		{
			SoftTimer_ResetTimer(TIMER_DEBOUNCE);
			enqueue(SHORT_PREES);
			return 0;
		}
	}
	
	return -1;
}
