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
void blink(int onTime, int repeat)
{    
	int i = 0;
	
	while(i < repeat)
	{
		LED_GREEN_ON;	// LED'i a�
        CLK_SysTickDelay(onTime * 1000); // onTime s�resi kadar beklet // ?????????????????????????????????????????????
        LED_GREEN_OFF;	// LED'i kapat
        CLK_SysTickDelay(onTime * 1000); // offTime s�resi kadar beklet // ?????????????????????????????????????????????
		
		i++;
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
void short_press_state(void)
{
    /* LED'i 1 saniyelik periyotlarla 2 defa yanip s�nd�r */
    blink(1000, 2);

    /* LED'i 2 saniyelik periyotlarla 2 defa yanip s�nd�r */
    blink(2000, 2);
}

/**
  * @brief   Uzun basma durumu i�in yapilacak islemler
  * @details Bu islev, kullanicinin d�gmeye uzun bir s�re basmasi durumunda �agrilir.
  *          LED'i 1 saniyelik periyotlarla 4 kez ve 2 saniyelik periyotlarla 4 kez yanip s�nd�r�r.
  * @param   Yok
  * @return  Yok
  * @author  B�nyamin Bugra Korkmazer
  */
void long_press_state(void)
{
    /* LED'i 1 saniyelik periyotlarla 4 defa yanip s�nd�r */
    blink(1000, 4);

    /* LED'i 2 saniyelik periyotlarla 4 defa yanip s�nd�r */
    blink(2000, 4);
}
