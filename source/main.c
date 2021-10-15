/*	Author: Brandon Tran
 *  Partner(s) Name: 
 *	Lab Section: 22
 *	Assignment: Lab #5  Exercise #1
 *	Exercise Description: 

		(From an earlier lab) A car has a fuel-level sensor that sets PA3..PA0 to a value between 
		0 (empty) and 15 (full). A series of LEDs connected to PC5..PC0 should light to 
		graphically indicate the fuel level. If the fuel level is 1 or 2, PC5 lights. If the level 
		is 3 or 4, PC5 and PC4 light. 5-6 lights PC5..PC3. 7-9 lights PC5..PC2. 10-12 lights 
		PC5..C1. 13-15 lights PC5..PC0. Also, PC6 connects to a "Low fuel" icon, which should 
		light if the level is 4 or less. Use buttons on PA3..PA0 and mimic the fuel-level sensor 
		with presses. 

 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
    /* Insert your solution below */
    while (1) {
		unsigned char aTmp = ~PINA & 0x0F; //temporary A from PA3..PA0
        unsigned char cTmp;
        
        switch(aTmp) {
            case 0:
                cTmp = 0x40;
                break;
            case 1:
            case 2:
                cTmp = 0x20 | 0x40;
                break;
            case 3:
            case 4:
                cTmp = 0x30 | 0x40;
                break;
            case 5:
            case 6:
                cTmp = 0x38;
                break;
            case 7:
            case 8:
            case 9:
                cTmp = 0x3C;
                break;
            case 10:
            case 11:
            case 12:
                cTmp = 0x3E;
                break;
            case 13:
            case 14:
            case 15:
                cTmp = 0x3F;
                break;
        }

        PORTC = cTmp;
    }
    return 1;
}
