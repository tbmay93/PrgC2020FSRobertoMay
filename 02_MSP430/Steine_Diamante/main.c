#include <msp430.h> 
#include "driverlib.h"
#include "hal_LCD.h"
#include <stdlib.h>
#include <time.h>

#define pos1 4   /* Digit A1 - L4  */
#define pos2 6   /* Digit A2 - L6  */
#define pos3 8   /* Digit A3 - L8  */
#define pos4 10  /* Digit A4 - L10 */
#define pos5 2   /* Digit A5 - L2  */
#define pos6 18  /* Digit A6 - L18 */

// Define word access definitions to LCD memories
#define LCDMEMW ((int*)LCDMEM)


int levelSwitch         = 0;
unsigned int speed     = 50000;
int ziffer[6]           = {0};
int leer                = 180;
int diamantOben         = 210;
int diamantUnten        = 240;
int steinOben           = 270;
int steinUnten          = 300;
unsigned int i         = 0;


void showDiamantStein(int c, int position);
void Init_LCD();


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer

    Init_LCD();
    srand(time(NULL));

	while(1)
	{
	    // Zeichen wetergeben und neue zufällig generieren
	    for(i = 0; i<5; i++)
	    {
	        ziffer[i] = ziffer[i+1];
	    }
	    if (levelSwitch <= 20)
	    {
	        ziffer[5] = rand() % 300;
	    }
	    else
	    {
	        ziffer[5] = 0;
	    }


	    // Auf den Display anzeigen
	    showDiamantStein(ziffer[0], pos6);
	    showDiamantStein(ziffer[1], pos5);
	    showDiamantStein(ziffer[2], pos4);
	    showDiamantStein(ziffer[3], pos3);
	    showDiamantStein(ziffer[4], pos2);
	    showDiamantStein(ziffer[5], pos1);

	    // nach 20 Zeichen Spiel schwieriger machen
	    if(levelSwitch == 26 && leer > 100)
	    {
	        leer = leer - 4;
	        diamantOben = diamantOben - 3;
	        diamantUnten = diamantUnten - 2;
	        steinOben = steinOben -1;
	        speed = speed - 2000;
	        levelSwitch = 0;
	        displayScrollText("NEXT LEVEL");
	    }



	    for(i = 0; i < speed; i++);       // Geschwindigkeit Zeichenwechsel
	    levelSwitch++;              // Zeichenwechsel zählen
	}


	return 0;
}

void showDiamantStein(int c, int position)
{
    if (c <= leer)
    {
        // Display space
        LCDMEMW[position/2] = 0;
    }
    else if (c > leer && c <= diamantOben)
    {
        // Display Diamant up
        LCDMEMW[position/2] = 0xA080;
    }
    else if (c > diamantOben && c <= diamantUnten)
    {
        // Display Diamant down
        LCDMEMW[position/2] = 0x0A10;
    }
    else if (c > diamantUnten && c <= steinOben)
    {
        // Display Stone up
        LCDMEMW[position/2] = 0x00C7;
    }
    else if (c > steinOben && c <= steinUnten)
    {
        // Display Stone down
        LCDMEMW[position/2] = 0x003B;
    }
    else
    {
        // Display Stone down
        LCDMEMW[position/2] = 0xFAFF;
    }
}


