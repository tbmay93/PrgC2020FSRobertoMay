#include <stdio.h>
#include <stdlib.h>

// this module's header
#include "bitOperation.h"

void printBinary(unsigned int input, unsigned char nBitsToPrint);

int main( int argc, char *argv[] )
{
	unsigned char testRegister = 0b00000000;

	// test 1: setting all bits, one-by-one
	printf("*** setting all bits, one-by-one ***\n");
	printBinary( testRegister, 8);
	for(int i = 0; i < 8; i++){
		setBitNof8( &testRegister, i);
		printBinary( testRegister, 8);
	}

	// test 2: clearing all bits, one-by-one
	printf("*** clearing all bits, one-by-one ***\n");
	printBinary( testRegister, 8);
	for(int i = 7; i >= 0; i--){
		clearBitNof8( &testRegister, i);
		printBinary( testRegister, 8);
	}


	// test 3: flip all bits, one-by-one
	printf("*** flip all bits, one-by-one ***\n");
	printBinary( testRegister, 8);
	for(int i = 0; i < 8; i++){
		flipBitNof8( &testRegister, i);
		printBinary( testRegister, 8);
		flipBitNof8( &testRegister, i);
		printBinary( testRegister, 8);
	}

	// test 4: check all pits, one-by-one
	printf("*** check all pits, one-by-one ***\n");
	testRegister = 0b10101010;
	printBinary( testRegister, 8);
	for(int i = 0; i < 8; i++){
		printf("Bit %d is: %u \n",i ,checkBitNof8( testRegister, i));
	}


	return EXIT_SUCCESS;
}


void printBinary(unsigned int input, unsigned char nBitsToPrint){
	unsigned int i = 0;

	printf("%u = \t 0b", input);

	for(i = (1 << (nBitsToPrint-1)); i > 0; i = (i>>1) ){
		if(input & i){
			printf("1");
		}
		else{
			printf("0");
		}
	}
	printf("\n");
}
