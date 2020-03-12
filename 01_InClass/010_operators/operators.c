#include<stdio.h>

/*
 * Operators
 */

int main(void){
	short largeShort = 	32760;
	largeShort = largeShort + 12345;
	printf("largeShort: %d \n", largeShort);
	
	int numerator = 19, denominator = 5, result = 0;
	result = numerator/denominator;
	printf("result: %d \n", result);

	float e = 2.718281828f;
	e++;
	printf("e incrementiert: %f \n", e);
	e--;
	printf("e decrementiert: %f \n", e);

	double dblNumerator = 12.8, dblresult = 0;
	dblresult = (int)dblNumerator % 3 + (dblNumerator - (int)dblNumerator);
	printf("dblresult: %f \n", dblresult);

	return 0;
}
