#ifndef SOFT_TIMER_H
#define SOFT_TIMER_H

/**/
#include <stdint.h>

/**/
#include <stdbool.h>

#define TIMER_COUNT		2

#define TIMER_DEBOUNCE		0
#define TIMER_LONG_PRESS		1
#define TIMER_LED		2

void SoftTimer_Init(void);
void SoftTimer_ISR(void); 
void SoftTimer_SetTimer(uint8_t TimerNo, uint32_t SetTimeMs);
bool SoftTimer_GetTimerStatus(uint8_t TimerNo);
void SoftTimer_ResetTimer(uint8_t TimerNo);

#endif
