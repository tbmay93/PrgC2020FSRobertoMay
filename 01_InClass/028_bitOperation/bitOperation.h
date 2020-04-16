// Module: bit operation suppoerting the handling
// of register manipulations on microcontrollers

// header file


/*
SetBitN( target, bitNumber )
ClearBitN( target, bitNumber )
FlipBitN( target, bitNumber )
unsigned char CheckBitN( target, bitNumber)
*/

#ifndef _H_BIT_OPERATION_H
#define _H_BIT_OPERATION_H

// functions prototypes

void setBitNof8( unsigned char* target, unsigned char bitNumber );
void clearBitNof8( unsigned char* target, unsigned char bitNumber );
void flipBitNof8( unsigned char* target, unsigned char bitNumber );
unsigned char checkBitNof8( unsigned char target, unsigned char bitNumber );


#endif // _H_BIT_OPERATION_H

