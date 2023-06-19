/**
  * @file:		main.h
  * @author:	Bünyamin Bugra Korkmazer
  * @date:		June 18, 2023
  * @version:	1.0
  *
  * @brief:		Header file for the main module
  *
  * @details:	This header file includes the necessary dependencies and defines the macro definitions used in the main module.
  *
  * Revision History: 
  * - 1.0.0 (June 18, 2023): Initial release.
  */

#ifndef MAIN_H
#define MAIN_H

/* Include the standard C library for input-output operations */
#include <stdio.h>

/* Include the standard library for memory allocation */
#include <stdlib.h>

/* Include the header file for the NuMicro MCU series */
#include "NuMicro.h"

/* Include the header file specific to the M031 series of the NuMicro MCU */
#include "M031Series.h"

/* Include other necessary header files */
#include "led.h"
#include "button.h"
#include "utils.h"
#include "eventDriven.h"
#include "softTimer.h"

#endif

/* End of the file */
