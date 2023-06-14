#include "led.h"
#include "main.h"

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
void blink(int onTime, int offTime, int repeat)
{    
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
