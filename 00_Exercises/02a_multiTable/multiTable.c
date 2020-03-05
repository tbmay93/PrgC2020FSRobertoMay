#include<stdio.h>
#include<stdlib.h>

void PrintUsageMassage(void); // Funktionsprototyp
void PrintMultiTable(int);


int main(int argc, char *argv[]){
	
	int inputValue = 0;

	if( argc != 2){
		PrintUsageMassage();
		return 0;
	}
	else{
		inputValue = atoi(argv[1]);
		if( inputValue >= 1 && inputValue <= 10){
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
	printf("Usage: multiTable wholeNumber \n \twholeNumber: integer on the interval [1,10]\n");
}

void PrintMultiTable(int tableLimit){
	for(int i = 1; i <= tableLimit; i++){
		for(int j = 1; j <= tableLimit; j++){
			printf("%d\t",i*j);
		}
		printf("\n");
	}
}
