/**
  * @file:		utils.h
  * @author:	Bünyamin Bugra Korkmazer
  * @date:		June 18, 2023
  * @version:	1.0
  *
  * @brief:		Header file for the utility functions used throughout the application.
  *
  * @details:	This file declares the prototypes for the functions used for initializing system setup, 
  *           	handling GPIO and timer initialization, and interrupt handling. These functions are 
  *           	defined in their respective source files. Include this header file in any source file 
  *           	where these functions are needed.
  *
  * Revision History: 
  * - 1.0.0 (June 18, 2023): Initial release.
  */

#ifndef UTILS_H
#define UTILS_H

/**
  * @section   Function Prototypes
  * @brief     This section includes function prototypes.
  */
void GPIO_Init(void);
void Timer_Init(void);
void SYS_Init(void);
void TMR1_IRQHandler(void);

#endif
