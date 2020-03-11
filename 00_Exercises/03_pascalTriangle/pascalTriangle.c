#include<stdio.h>
#include<stdlib.h>

void PrintUsageMassage(void);
void PrintPascalTriangle(int);

const int lowerLimit = 1;
const int uperLimit = 20;

int main(int argc, char *argv[]){
	
	int inputValue = 0;

	if( argc != 2){
		PrintUsageMassage();
		return 0;
	}
	else{
		inputValue = atoi(argv[1]);
		if( inputValue >= lowerLimit && inputValue <= uperLimit){
			// input is valid
			PrintPascalTriangle(inputValue);		
		}
		else{
			// no valid input
			PrintUsageMassage();
		}
	}


	return 0;
}

void PrintUsageMassage(void){
	printf("Usage: pascalTriangle wholeNumber \n \twholeNumber: integer on the interval [%d,%d]\n",lowerLimit ,uperLimit);
}

void PrintPascalTriangle(int tableLimit){
	int taps = 4 * tableLimit;	
	int arrayPascalTriangleOld[20] = {0};
	int arrayPascalTriangleNew[20] = {0};
	arrayPascalTriangleOld[0] = 1;
	arrayPascalTriangleNew[0] = 1;
	for(int i = 0; i < taps; i++){
		printf(" ");
	}
	printf("%d\n", arrayPascalTriangleNew[0]);
	for(int j = 1; j < tableLimit; j++){
		for(int l = 0; l < (taps - j*3); l++){
			printf(" ");
		}
		for(int k = 0; k <= j; k++){
			if(k == 0){
				printf("%d", arrayPascalTriangleNew[k]);			
			} else if(arrayPascalTriangleNew[k] == 1){
				printf("     %d\n", arrayPascalTriangleNew[k]);
			} else if(arrayPascalTriangleNew[k-1] < 10 && arrayPascalTriangleNew[k] < 100){
				printf("     %d", arrayPascalTriangleNew[k]);
			} else if(arrayPascalTriangleNew[k-1] < 100 && arrayPascalTriangleNew[k] < 100){
				printf("    %d", arrayPascalTriangleNew[k]);
			} else if(arrayPascalTriangleNew[k-1] < 1000 && arrayPascalTriangleNew[k] < 10000){
				printf("   %d", arrayPascalTriangleNew[k]);
			} else if(arrayPascalTriangleNew[k-1] < 10000 && arrayPascalTriangleNew[k] < 10000){
				printf("  %d", arrayPascalTriangleNew[k]);
			} else if(arrayPascalTriangleNew[k-1] < 100000 && arrayPascalTriangleNew[k] < 1000000){
				printf(" %d", arrayPascalTriangleNew[k]);
			} else if(arrayPascalTriangleNew[k-1] < 1000000){
				printf("%d", arrayPascalTriangleNew[k]);
			}
			if(k != 0 && arrayPascalTriangleNew[k] == 1){
				for(int m = 0; m < 20; m++){
					arrayPascalTriangleOld[m] = arrayPascalTriangleNew[m];
				}
			} else{
				arrayPascalTriangleNew[k+1] = arrayPascalTriangleOld[k] + arrayPascalTriangleOld[k+1];
			}
		}		
	}
}
