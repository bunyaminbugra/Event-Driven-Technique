#ifndef UTILS_H
#define UTILS_H

/**
  * @section   Function Prototypes
  * @brief     This section includes function prototypes.
  *            These are declarations of all functions used in the main program.
  */
  
/* Initializes the GPIO (General Purpose Input/Output) pins */
void GPIO_Init(void);
void Timer_Init(void);
void SYS_Init(void);
void TMR1_IRQHandler(void);

#endif
