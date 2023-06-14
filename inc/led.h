#ifndef LED_H
#define LED_H

#define	HIGH		1
#define	LOW		0
  
#define LED_GREEN	PB14
#define LED_GREEN_PORT	PB
#define LED_GREEN_PIN	BIT14

#define LED_GREEN_ON	(LED_GREEN = HIGH)
#define LED_GREEN_OFF	(LED_GREEN = LOW)

#define BUTTON	PB15
#define	BUTTON_PORT	PB
#define	BUTTON_PIN	BIT15

void blink(int onTime, int repeat);
void short_press_state(void);
void long_press_state(void);

#endif
