#include "main.h"

button_InitTypeDef* button_Init(GPIO_T *port, unsigned long pin)
{
	button_InitTypeDef *button = (button_InitTypeDef *)malloc(sizeof(button_InitTypeDef));
	
	button->port = port;
	button->pin = pin;
	
	GPIO_SetMode(port, pin, GPIO_MODE_INPUT);
	
	return button;
}

void button_DeInit(button_InitTypeDef *button)
{
	free(button);
}

int button_Get_Status(button_InitTypeDef *button, led_InitTypeDef *led)
{
	static int lastButtonState, buttonState;
	
	buttonState = button_Read(button);
	
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
	else if(SoftTimer_GetTimerStatus(TIMER_LONG_PRESS))
		{
			SoftTimer_ResetTimer(TIMER_LONG_PRESS);
			SoftTimer_ResetTimer(TIMER_DEBOUNCE);
			enqueue(LONG_PRESS);
			lastButtonState = buttonState;
			return 0;
		}
	else if (SoftTimer_GetTimerStatus(TIMER_DEBOUNCE) && (!buttonState))
	{
		SoftTimer_ResetTimer(TIMER_DEBOUNCE);
		enqueue(SHORT_PREES);
		lastButtonState = buttonState;
		return 0;
	}
	
	lastButtonState = buttonState;
	return -1;
}

int button_Read(button_InitTypeDef *button)
{
	return !(GPIO_PIN_DATA(getPortNumber(button->port), getPinNumber(button->pin)));
}
