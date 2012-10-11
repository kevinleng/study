#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int);

int main(void ){
	const int SIZE = 1024*1024*20;
	int start = time(NULL);
	int i=2;
        for(;i<SIZE;i++){
           isPrime(i);
          // printf("%d isPrime %d\n", i, isPrime(i));
        }
    int end = time(NULL);
    printf("%d\n", (end-start));

	return 0;
}

int isPrime(int num){
    int msqrt = (int) sqrt(num);
    int i=2;
    for(;i<=msqrt;i++){
        if(num%i==0){
            return 0;
        }
    }
    
    return 1;
}
