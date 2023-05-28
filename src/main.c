/**
  * @file		main.c
  * @version	V1.0
  * @brief		EAE Group Mulakat Uygulamasi
  *
  */
  
/*
 * MCU:M031TB0AE(QFN33)
 * Base Clocks:
 * LIRC:38.4kHz
 * HIRC:48MHz
 * HXT:32MHz
 * HCLK:32MHz
 * PCLK0:32MHz
 * PCLK1:32MHz
 * Enabled-Module Frequencies:
 * ISP=Bus Clock(HCLK):32MHz/Engine Clock:48MHz
 * TMR0=Bus Clock(PCLK0):32MHz/Engine Clock:48MHz
 * WDT=Bus Clock(PCLK0):32MHz/Engine Clock:38.4kHz
 * WWDT=Bus Clock(PCLK0):32MHz/Engine Clock:15.625kHz
 */
 
/*
 * MCU:M031TB0AE(QFN33)
 * Pin Configuration:
 * Pin17:ICE_DAT
 * Pin18:ICE_CLK
 * Pin28:PB.15
 * Pin29:PB.14
 */

/* Include the standard C library for input-output operations */
#include <stdio.h>

/* Include the header file for the NuMicro MCU series */
#include "NuMicro.h"

/* Include the header file specific to the M031 series of the NuMicro MCU */
#include "M031Series.h"


/**
  * @section   Macro Definitions
  * @brief     This section includes macro definitions.
  */
  
#define	HIGH	0
#define	LOW	1
  
#define LED_GREEN	PB14
#define LED_GREEN_PORT	PB
#define LED_GREEN_PIN	BIT14

#define LED_GREEN_ON	(LED_GREEN = HIGH)
#define LED_GREEN_OFF	(LED_GREEN = LOW)

#define BUTTON	PB15
#define	BUTTON_PORT	PB
#define	BUTTON_PIN	BIT15

#define DEBOUNCE_TIME	100
#define LONG_PRESS_TIME	3000
#define SHORT_PRESS_TIME	2000




/**
  * @section   Function Prototypes
  * @brief     This section includes function prototypes.
  *            These are declarations of all functions used in the main program.
  */
  
/* Initializes the GPIO (General Purpose Input/Output) pins */
void GPIO_Init(void);

/**
  * @section   Function Definitions
  * @brief     This section includes function definitions.
  *            These are the definitions of the functions declared in the function prototypes.
  */

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
	/*
	 * -- Init System Clock --
	 *
	 * CLK->PWRCTL   = (CLK->PWRCTL   & ~(0x0000000DUL)) | 0x0231001FUL;
	 * CLK->CLKDIV0  = (CLK->CLKDIV0  & ~(0x00FFFFFFUL)) | 0x00000000UL;
	 * CLK->CLKDIV4  = (CLK->CLKDIV4  & ~(0x00FFFFFFUL)) | 0x00000000UL;
	 * CLK->PCLKDIV  = (CLK->PCLKDIV  & ~(0x00000077UL)) | 0x00000000UL;
	 * CLK->CLKSEL0  = (CLK->CLKSEL0  & ~(0x0000013FUL)) | 0x00000038UL;
	 * CLK->CLKSEL1  = (CLK->CLKSEL1  & ~(0x7777777FUL)) | 0x4477773BUL;
	 * CLK->CLKSEL2  = (CLK->CLKSEL2  & ~(0x0030033FUL)) | 0x0020032BUL;
	 * CLK->CLKSEL3  = (CLK->CLKSEL3  & ~(0x77777700UL)) | 0x44444400UL;
	 * CLK->AHBCLK   = (CLK->AHBCLK   & ~(0x0000009EUL)) | 0x00000004UL;
	 * CLK->APBCLK0  = (CLK->APBCLK0  & ~(0x18FF33FFUL)) | 0x00000005UL;
	 * CLK->APBCLK1  = (CLK->APBCLK1  & ~(0x000F0300UL)) | 0x00000000UL;
	 * CLK->CLKOCTL  = (CLK->CLKOCTL  & ~(0x0000007FUL)) | 0x00000000UL;
	 * SysTick->CTRL = (SysTick->CTRL & ~(0x00000005UL)) | 0x00000000UL;
	 * RTC->LXTCTL   = (RTC->LXTCTL   & ~(0x00000080UL)) | 0x00000000UL;
	 */

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
	
	/*
	 * -- Pin Konfigurasyonlari --
	 *
	 * SYS->GPA_MFPH = 0x00000000UL;
	 * SYS->GPA_MFPL = 0x00000000UL;
	 * SYS->GPB_MFPH = 0x00000000UL;
	 * SYS->GPB_MFPL = 0x00000000UL;
	 * SYS->GPC_MFPL = 0x00000000UL;
	 * SYS->GPF_MFPH = 0x00000000UL;
	 * SYS->GPF_MFPL = 0x000000EEUL;
	 */ 

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

void Timer_Init(void)
{
    /**************  TIMER0 ***************/
    /* Set TIMER0 in periodic mode ,frequency 1Hz and enable its interrupt */
    TIMER_Open(TIMER0, TIMER_PERIODIC_MODE, 1);
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
	
	/*
	 * Nuvoton M031/M032 ailesinde donanimsal debounce özelligi var.
	 * Fakat bizden istenen uygulamada yazilimsal yetenekler gözetilecegi için
	 * bu uygulamada yazilimsal debounce kullanilacaktir.
	 */
//	GPIO_ENABLE_DEBOUNCE(BUTTON_PORT, BUTTON_PIN);
//	GPIO_SET_DEBOUNCE_TIME(GPIO_DBCTL_DBCLKSRC_LIRC, GPIO_DBCTL_DBCLKSEL_4096);
	
	LED_GREEN_OFF;
}

/**
 * @brief   LED'in belirli bir süre boyunca yanip sönmesini saglar.
 * 
 * @param   onTime  LED'in açik kalacagi süre (milisaniye cinsinden).
 * @param   offTime LED'in kapali kalacagi süre (milisaniye cinsinden).
 * @param   repeat  Yanip sönmeyi tekrarlama sayisi.
 * 
 * Bu fonksiyon, LED'in belirli bir süre boyunca yanip sönmesini saglar.
 * Yanma ve sönme süreleri, belirtilen 'onTime' ve 'offTime' parametreleri
 * ile ayarlanabilir. Yanip sönme döngüsü, 'repeat' parametresi kadar tekrarlanir.
 * 
 * Örnegin, blink(1000, 500, 3) çagrisi LED'i 1000 ms boyunca açar, 
 * sonra 500 ms boyunca kapatir ve bu döngüyü 3 kez tekrarlar.
 * 
 * @author  Bünyamin Bugra Korkmazer
 * 
 */
void blink(int onTime, int offTime, int repeat) {
    
	int i = 0;
	
	while(i < repeat)
	{
		LED_GREEN_ON;	// LED'i aç
        CLK_SysTickDelay(onTime * 1000); // onTime süresi kadar beklet
        LED_GREEN_OFF;	// LED'i kapat
        CLK_SysTickDelay(offTime * 1000); // offTime süresi kadar beklet
		
		i++;
    }
}

/**
  * @brief   Main function
  * @details This is the entry point of the program.
  * @param   None
  * @return  Integer value indicating the exit status
  * @note    The main function should return an exit status indicating the program's termination status.
  */
int main()
{
	unsigned long lastDebounceTime = 0;  // Son debounce zamani
	unsigned long debounceDelay = 50;    // Debounce gecikmesi (ms)

	int buttonState = 0;  // Butonun son durumu
	int lastButtonState = 0;  // Butonun son stabil durumu
	
    SYS_Init();
	GPIO_Init();

    while(1)
	{
		// Butonun mevcut durumunu okuyun
		int reading = BUTTON;

		// Eger durum degismisse, debounce zamanini yeniden ayarlayin
		if (reading != lastButtonState)
		{
		TIMER_Start(TIMER0);	
			lastDebounceTime = TIMER_GetCounter(TIMER0);
		}

		// Eger buton durumu son debounce zamanindan bu yana degismediyse, 
		// durumun stabil oldugunu kabul edin.
		if ((TIMER_GetCounter(TIMER0) - lastDebounceTime) > debounceDelay)
		{
			if (reading != buttonState) 
			{
				buttonState = reading;

			// Burada buton durumuna bagli olarak bir eylem yapabilirsiniz.
			}
		}

		// Son okunan durumu kaydedin
		lastButtonState = reading;
	}
}

/*** (C) COPYRIGHT 2017 Nuvoton Technology Corp. ***/
