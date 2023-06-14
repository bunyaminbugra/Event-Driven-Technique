#include "led.h"
#include "main.h"

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
void blink(int onTime, int offTime, int repeat)
{    
	int i = 0;
	
	while(i < repeat)
	{
		LED_GREEN_ON;	// LED'i a�
        CLK_SysTickDelay(onTime * 1000); // onTime s�resi kadar beklet
        LED_GREEN_OFF;	// LED'i kapat
        CLK_SysTickDelay(offTime * 1000); // offTime s�resi kadar beklet
		
		i++;
    }
}
