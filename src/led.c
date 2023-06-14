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
void blink(int onTime, int repeat)
{    
	int i = 0;
	
	while(i < repeat)
	{
		LED_GREEN_ON;	// LED'i aç
        CLK_SysTickDelay(onTime * 1000); // onTime süresi kadar beklet // ?????????????????????????????????????????????
        LED_GREEN_OFF;	// LED'i kapat
        CLK_SysTickDelay(onTime * 1000); // offTime süresi kadar beklet // ?????????????????????????????????????????????
		
		i++;
    }
}

/**
  * @brief   Kisa basma durumu için yapilacak islemler
  * @details Bu islev, kullanicinin dügmeye kisa bir süre basmasi durumunda çagrilir.
  *          LED'i 1 saniyelik periyotlarla 2 kez ve 2 saniyelik periyotlarla 2 kez yanip söndürür.
  * @param   Yok
  * @return  Yok
  * @author  Bünyamin Bugra Korkmazer
  */
void short_press_state(void)
{
    /* LED'i 1 saniyelik periyotlarla 2 defa yanip söndür */
    blink(1000, 2);

    /* LED'i 2 saniyelik periyotlarla 2 defa yanip söndür */
    blink(2000, 2);
}

/**
  * @brief   Uzun basma durumu için yapilacak islemler
  * @details Bu islev, kullanicinin dügmeye uzun bir süre basmasi durumunda çagrilir.
  *          LED'i 1 saniyelik periyotlarla 4 kez ve 2 saniyelik periyotlarla 4 kez yanip söndürür.
  * @param   Yok
  * @return  Yok
  * @author  Bünyamin Bugra Korkmazer
  */
void long_press_state(void)
{
    /* LED'i 1 saniyelik periyotlarla 4 defa yanip söndür */
    blink(1000, 4);

    /* LED'i 2 saniyelik periyotlarla 4 defa yanip söndür */
    blink(2000, 4);
}
