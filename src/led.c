#include "main.h"

blink_Type *blink_t;

led_InitTypeDef* led_Init(GPIO_T *port, unsigned long pin)
{
	led_InitTypeDef *led = (led_InitTypeDef *)malloc(sizeof(led_InitTypeDef));
	
	led->port = port;
	led->pin = pin;
	
	GPIO_SetMode(port, pin, GPIO_MODE_OUTPUT);
	
	led_RESET(led);
	
	return led;
}

void led_DeInit(led_InitTypeDef *led)
{
	free(led);
}

/**
 * @brief   LED'in belirli bir s�re boyunca yanip s�nmesini saglar.
 * 
 * @param   onTime  LED'in a�ik kalacagi s�re (milisaniye cinsinden).
 * @param   offTime LED'in kapali kalacagi s�re (milisaniye cinsinden).
 * @param   repeat  Yanip s�nmeyi tekrarlama sayisi.
 * 
 * Bu fonksiyon, LED'in belirli bir s�re boyunca yanip s�nmesini saglar.
 * Yanma ve s�nme s�releri, belirtilen 'onTime' ve 'offTime' parametreleri
 * ile ayarlanabilir. Yanip s�nme d�ng�s�, 'repeat' parametresi kadar tekrarlanir.
 * 
 * �rnegin, blink(1000, 500, 3) �agrisi LED'i 1000 ms boyunca a�ar, 
 * sonra 500 ms boyunca kapatir ve bu d�ng�y� 3 kez tekrarlar.
 * 
 * @author  B�nyamin Bugra Korkmazer
 * 
 */
void blink(led_InitTypeDef *led, int onTime, int repeat)
{    
	int i;
	
	for(i=0; i<repeat; i++)
	{
		led_SET(led);	// LED'i a�
        CLK_SysTickDelay(onTime * 1000); // onTime s�resi kadar beklet // ?????????????????????????????????????????????
        led_RESET(led);	// LED'i kapat
        CLK_SysTickDelay(onTime * 1000); // offTime s�resi kadar beklet // ?????????????????????????????????????????????
    }
}

/**
  * @brief   Kisa basma durumu i�in yapilacak islemler
  * @details Bu islev, kullanicinin d�gmeye kisa bir s�re basmasi durumunda �agrilir.
  *          LED'i 1 saniyelik periyotlarla 2 kez ve 2 saniyelik periyotlarla 2 kez yanip s�nd�r�r.
  * @param   Yok
  * @return  Yok
  * @author  B�nyamin Bugra Korkmazer
  */
void short_press_state(led_InitTypeDef *led)
{
    /* LED'i 1 saniyelik periyotlarla 2 defa yanip s�nd�r */
    blink(led, 250, 2);

    /* LED'i 2 saniyelik periyotlarla 2 defa yanip s�nd�r */
    blink(led, 500, 2);
}

/**
  * @brief   Uzun basma durumu i�in yapilacak islemler
  * @details Bu islev, kullanicinin d�gmeye uzun bir s�re basmasi durumunda �agrilir.
  *          LED'i 1 saniyelik periyotlarla 4 kez ve 2 saniyelik periyotlarla 4 kez yanip s�nd�r�r.
  * @param   Yok
  * @return  Yok
  * @author  B�nyamin Bugra Korkmazer
  */
void long_press_state(led_InitTypeDef *led)
{
    /* LED'i 1 saniyelik periyotlarla 4 defa yanip s�nd�r */
    blink(led, 250, 4);

    /* LED'i 2 saniyelik periyotlarla 4 defa yanip s�nd�r */
    blink(led, 500, 4);
}

void led_SET(led_InitTypeDef *led)
{
	GPIO_PIN_DATA(getPortNumber(led->port), getPinNumber(led->pin)) = 0;
}

void led_RESET(led_InitTypeDef *led)
{
	GPIO_PIN_DATA(getPortNumber(led->port), getPinNumber(led->pin)) = 1;
}

void led_TOGGLE(led_InitTypeDef *led)
{
	GPIO_PIN_DATA(getPortNumber(led->port), getPinNumber(led->pin)) ^= 1;
}

/**
  * @brief  Converts a GPIO port pointer to the corresponding port number.
  * @param  port: Pointer to the GPIO port.
  * @return Port number corresponding to the GPIO port.
  */
int getPortNumber(GPIO_T* port)
{
    if (port == PA) 
		return 0;
    else if (port == PB) 
		return 1;
	else if (port == PC) 
		return 2;
	else if (port == PD) 
		return 3;
	else if (port == PE) 
		return 4;
	else if (port == PF) 
		return 5;
	else if (port == PG) 
		return 6;
	else if (port == PH) 
		return 7;

    else return -1;
}

/**
  * @brief  Converts a pin mask to the corresponding pin number.
  * @param  u32PinMask: Pin mask value.
  * @return Pin number corresponding to the pin mask.
  */
int getPinNumber(unsigned long u32PinMask)
{
    if (u32PinMask == BIT0) 
		return 0;
    else if (u32PinMask == BIT1) 
		return 1;
	else if (u32PinMask == BIT2) 
		return 2;
	else if (u32PinMask == BIT3) 
		return 3;
	else if (u32PinMask == BIT4) 
		return 4;
	else if (u32PinMask == BIT5) 
		return 5;
	else if (u32PinMask == BIT6) 
		return 6;
	else if (u32PinMask == BIT7) 
		return 7;
	else if (u32PinMask == BIT8) 
		return 8;
	else if (u32PinMask == BIT9) 
		return 9;
	else if (u32PinMask == BIT10) 
		return 10;
	else if (u32PinMask == BIT11) 
		return 11;
	else if (u32PinMask == BIT12) 
		return 12;
	else if (u32PinMask == BIT13) 
		return 13;
	else if (u32PinMask == BIT14) 
		return 14;
	else if (u32PinMask == BIT15) 
		return 15;

    else return -1;
}
