#include <stdio.h>
#include <stdlib.h>

void printBinary(unsigned int input);

int main(int argc, char *argv[]){
	unsigned int a = 12, b = 25;

	// AND
	printf("*** AND ***\n");
	printBinary(a);
	printBinary(b);
	printBinary(a&b);

	// OR
	printf("*** OR ***\n");
	printBinary(a);
	printBinary(b);
	printBinary(a|b);

	// XOR
	printf("*** XOR ***\n");
	printBinary(a);
	printBinary(b);
	printBinary(a^b);

	// Complement
	printf("*** Complement ***\n");
	printBinary(a);
	printBinary(~a);

	// shift left
	printf("*** shift left ***\n");
	printBinary(a);
	printBinary(a << 1);

	// shift right
	printf("*** shift right ***\n");
	printBinary(a);
	printBinary(a >> 1);

	// bit masking: Set bit 5
	unsigned char c 	= 0b00001100;
	unsigned char mask	= 0b00100000;	// set bit 5
	printf("*** set bit 5 ***\n");
	printBinary(c);
	printBinary(c | mask);
	mask = 1; // 0b00000001
	printBinary(c | mask<<5);

	// bit masking: Clear Bit 5 --> AND
	c = 0b00101100;
	mask	= 0b11011111;
	printf("*** clear bit 5 ***\n");
	printBinary(c);
	printBinary(c & mask);
	printBinary(c & ~(1<<5));

	// check if bit 3 is set
	printf("*** check bit 3 ***\n");
	printBinary(c);	
	printBinary(c & 1<<3);

	// invert bit 3 and 0
	printf("*** invert bit 3 and 0 ***\n");
	printBinary(c);	
	mask = 0b00001001;	
	printBinary(c ^ mask);		
	printBinary(c ^ ((1<<3) | 1));



	return EXIT_SUCCESS;
}

void printBinary(unsigned int input){
	unsigned int i = 0;

	printf("%u = \t 0b", input);

	for(i = (1 << 7); i > 0; i = (i>>1) ){
		if(input & i){
			printf("1");
		}
		else{
			printf("0");
		}
	}
	printf("\n");
}
