#include <msp430.h> 

unsigned long *pBootCounter = 0x1800;
unsigned int wait = 0;
unsigned int i = 0;

/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	P1DIR |= BIT0;      // set P1.0 as output for red LED
	P4DIR |= BIT0;      // set P4.0 as output for green LED

	P1OUT = P4OUT = ~BIT0;      // both LED off

	SYSCFG0 &= ~DFWP;   // dislock FRAM
	(*pBootCounter)++;    // increment Boot-Counter
	SYSCFG0 |= DFWP;    // lock FRAM

	P4OUT = BIT0;      // turn on green LED

    wait = 0;       // reset wait
    while(wait < 65000)       // wait
    {
        wait++;
    }

	for(i = 0; i < *pBootCounter; i++)
	{
	    P1OUT = BIT0;  // turn on red LED

	    wait = 0;       // reset wait
	    while(wait < 50000)       // wait
	    {
	        wait++;
	    }

	    P1OUT = ~BIT0; // turn off red LED

        wait = 0;       // reset wait
        while(wait < 50000)       // wait
        {
            wait++;
        }
	}

	P4OUT = ~BIT0;      // turn off green LED

	return 0;
}
