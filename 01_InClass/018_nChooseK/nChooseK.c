#include <stdio.h>
#include <stdlib.h>

/* compute the n Choose k result */

// prototype
long factorial(int n);
long nChooseK(int n, int k);


int main( int argc, char* argv[] )
{
    int n = 0, k = 0, waitOnValidInput = 1;
	while(waitOnValidInput){
	    printf("Enter a positive integer for n: ");
    	scanf("%d",&n);
	    printf("Enter a positive integer for k: ");
    	scanf("%d",&k);
		if(n>=0 && k>=0 && n>=k) {
		    printf("For n=%d Choose k=%d are %ld possible solutions!\n", n, k, nChooseK(n,k));
			break;
		}
		else
		{
			printf("Invalid input. Try again.\n");
		}
	}
	return EXIT_SUCCESS;
}

// implementation of the factorial function
long  factorial(int n) {
    if (n>=1)
        return n*factorial(n-1);
    else
        return 1;
}

long nChooseK(int n, int k){
	return factorial(n) / (factorial(k) * factorial(n-k));
}


