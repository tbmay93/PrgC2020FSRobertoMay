#include<stdio.h>
#include<stdlib.h>

void PrintUsageMassage(void); // Funktionsprototyp
void PrintMultiTable(int);

const int lowerLimit = 1;
const int uperLimit = 10;

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
			PrintMultiTable(inputValue);		
		}
		else{
			// no valid input
			PrintUsageMassage();
		}
	}


	return 0;
}

void PrintUsageMassage(void){
	printf("Usage: multiTable wholeNumber \n \twholeNumber: integer on the interval [%d,%d]\n",lowerLimit ,uperLimit);
}

void PrintMultiTable(int tableLimit){
	for(int i = 1; i <= tableLimit; i++){
		for(int j = 1; j <= tableLimit; j++){
			printf("%d\t",i*j);
		}
		printf("\n");
	}
}
