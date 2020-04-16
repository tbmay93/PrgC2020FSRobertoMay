// Module: bit operation suppoerting the handling
// of register manipulations on microcontrollers

// this module's header
#include "bitOperation.h"


// source file

/*
SetBitN( target, bitNumber )
ClearBitN( target, bitNumber )
FlipBitN( target, bitNumber )
unsigned char CheckBitN( target, bitNumber)
*/

void setBitNof8( unsigned char* target, unsigned char bitNumber ){
	*target = (*target | (1 << bitNumber));
}

void clearBitNof8( unsigned char* target, unsigned char bitNumber ){
	*target = (*target & ~(1 << bitNumber));
}

void flipBitNof8( unsigned char* target, unsigned char bitNumber ){
	*target = (*target ^ (1 << bitNumber));
}

// returns 1 if Bit is set, 0 otherwise
unsigned char checkBitNof8( unsigned char target, unsigned char bitNumber ){
	return (target & (1<<bitNumber)) >> bitNumber;
	
	// long version
	/*
	unsigned char BitIsSet = 0;
	
	if(target & (1<<bitNumber)){
		BitIsSet = 1;
	}
	else{
		BitIsSet = 0;
	}
	
	return BitIsSet;
	*/
}
