#include "main.h"

/**
  * @brief   Initialize system
  * @details This function is used to initialize the system, including system clock, GPIO and module clocks.
  * @param   None
  * @return  None
  * @note    The function must be invoked at the beginning of the program.
  * @author  Bünyamin Bugra Korkmazer
  */
void SYS_Init(void)
{
	/* Unlock protected registers */
	SYS_UnlockReg();

	/* If the macros do not exist in your project, please refer to the related clk.h in Header folder of the tool package */
	/* Enable clock source */
	CLK_EnableXtalRC(CLK_PWRCTL_LIRCEN_Msk|CLK_PWRCTL_HIRCEN_Msk|CLK_PWRCTL_HXTEN_Msk);

	/* Waiting for clock source ready */
	CLK_WaitClockReady(CLK_STATUS_LIRCSTB_Msk|CLK_STATUS_HIRCSTB_Msk|CLK_STATUS_HXTSTB_Msk);

	/* Set HCLK clock */
	CLK_SetHCLK(CLK_CLKSEL0_HCLKSEL_HXT, CLK_CLKDIV0_HCLK(1));

	/* Set PCLK-related clock */
	CLK->PCLKDIV = (CLK_PCLKDIV_APB0DIV_DIV1 | CLK_PCLKDIV_APB1DIV_DIV1);

	/* Enable IP clock */
	CLK_EnableModuleClock(ISP_MODULE);
	CLK_EnableModuleClock(TMR0_MODULE);
	CLK_EnableModuleClock(WDT_MODULE);

	/* Set IP clock */
	CLK_SetModuleClock(TMR0_MODULE, CLK_CLKSEL1_TMR0SEL_HIRC, MODULE_NoMsk);
	CLK_SetModuleClock(WDT_MODULE, CLK_CLKSEL1_WDTSEL_LIRC, MODULE_NoMsk);

	/* Update System Core Clock */
	/* User can use SystemCoreClockUpdate() to calculate SystemCoreClock. */
	SystemCoreClockUpdate();

	/* If the macros do not exist in your project, please refer to the corresponding header file in Header folder of the tool package */
	SYS->GPA_MFPH = 0x00000000;
	SYS->GPA_MFPL = 0x00000000;
	SYS->GPB_MFPH = SYS_GPB_MFPH_PB15MFP_GPIO | SYS_GPB_MFPH_PB14MFP_GPIO;
	SYS->GPB_MFPL = 0x00000000;
	SYS->GPC_MFPL = 0x00000000;
	SYS->GPF_MFPH = 0x00000000;
	SYS->GPF_MFPL = SYS_GPF_MFPL_PF1MFP_ICE_CLK | SYS_GPF_MFPL_PF0MFP_ICE_DAT;

	/* Lock protected registers */
	SYS_LockReg();

	return;
}

/**
  * @brief   Initialize timer
  * @details This function is used to initialize the timer, configure its mode, enable interrupt, and start the timer.
  * @param   None
  * @return  None
  * @note    The function must be invoked to initialize the timer before using it.
  * @author  Bünyamin Buðra Korkmazer
  */
void Timer_Init(void)
{
	/*
     * Init Timer
     */
	
	/* Open Timer1 in periodic mode with a prescale value of 3 */
	TIMER_Open(TIMER1, TIMER_PERIODIC_MODE, 1);

	 /* Enable Timer1 interrupt and enable NVIC IRQ */
	TIMER_EnableInt(TIMER1);
	NVIC_EnableIRQ(TMR1_IRQn);

	/* Start Timer1 counting */
	TIMER_Start(TIMER1);
}

/**
  * @brief   Initialize GPIO pins
  * @details This function is used to initialize the GPIO pins.
  * @param   None
  * @return  None
  * @note    The function must be invoked to initialize the GPIO pins before using them.
  * @author  Bünyamin Bugra Korkmazer
  */
void GPIO_Init(void)
{
	/*
	 * Init GPIO pins
	 */
	
	GPIO_SetMode(LED_GREEN_PORT, LED_GREEN_PIN, GPIO_MODE_OUTPUT);
	
	GPIO_SetMode(BUTTON_PORT, BUTTON_PIN, GPIO_MODE_INPUT);
		
	LED_GREEN_OFF;
}



/**
  * @brief   TMR1 Interrupt Handler
  * @details This function is called when the TIMER1 interrupt occurs.
  * @param   None
  * @return  None
  * @author  Bünyamin Bugra Korkmazer
  */
void TMR1_IRQHandler(void)
{
	/* Check if TIMER1 interrupt occurred */
	if (TIMER_GetIntFlag(TIMER1))
    {
		SoftTimer_ISR();
		/* Clear the TIMER1 interrupt flag */
		TIMER_ClearIntFlag(TIMER1);
	}
}
